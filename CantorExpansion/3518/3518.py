import math

# 這是第二題，第一題是3517
# 概念跟第一題一樣拆成3段組合新字串
# 所以一樣只要管前半段的字串
# 但是這一題要改求第k小的，所以問題從只要sort變成
# 需要處理帶重複項的逆康托展開(考點就在這)
# 然後因為康托展開要算階層，所以改由python處理
class Solution:
    # 用來計算目前的帶重複排序總數
    # n! / (n1! * n2! * ... * nk!)
    def get_permutation_cnt(self, cnts: dict[str, int], total: int) -> int:
        numerator = math.factorial(total)
        denominator = 1
        for c in cnts.values():
            if (c > 1):
                denominator *= math.factorial(c)
        return numerator // denominator


    def smallestPalindrome(self, s: str, k: int) -> str:
        cnts = {}
        half_len = len(s) // 2
        for i in range(half_len):
            if (s[i] not in cnts):
                cnts[s[i]] = 0
            cnts[s[i]] += 1

        middle = s[half_len] if (len(s) % 2 == 1) else ""

        curr_total_permutation_num = self.get_permutation_cnt(cnts, half_len)
        # 根本排列不出來
        if (curr_total_permutation_num < k):
            return ""

        # 逆康托展開
        sorted_chars = sorted(cnts.keys())
        left_str_list = []
        remain_slots = half_len # 還有多少格字要填數字
        for i in range(half_len):
            # 從小到大試試看，看每一位應該塞哪個字元
            for c in sorted_chars:
                if (cnts[c] == 0):
                    continue

                # 試試看放這個字元
                # cnts[c] -= 1 # 改到後面計算 (原本配合舊的remain_permutation_num算法)

                # 看放完之後還有多少排列數
                # half_len - i - 1是因為已經放了i個字加上現在新的一個字用掉
                # remain_permutation_num = self.get_permutation_cnt(cnts, half_len - i - 1)
                # 上面這樣算會超時
                # 觀察到新排列數 = (remain_slots - 1)! / (... * (cnts[c] - 1)! * ...) = 上一次排列數 * (cnts[c] / remain_slots)
                remain_permutation_num = curr_total_permutation_num * cnts[c] // remain_slots

                if (k > remain_permutation_num):
                    # 這個字元不可能放在這裡，所以跳過這個字元
                    k -= remain_permutation_num # 因為跳過了這些可能的排列
                    # cnts[c] += 1 # 沒用到所以還回去 (現在不用了)
                else: # k <= remain_permutation_num
                    # 這個字元就是放這裡沒錯
                    left_str_list.append(c)
                    cnts[c] -= 1 # 改到這裡扣
                    curr_total_permutation_num = remain_permutation_num
                    break

            remain_slots -= 1 # 這個格子填完了

        left_str = "".join(left_str_list) # 拼接起來
        return left_str + middle + left_str[::-1]