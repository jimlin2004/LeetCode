class Solution 
{
public:
    /*
        這題題目描述講得很糟，其實就是
        給定數線[0, n - 1]中
        請挑出k個不重疊的線段(端點可共用)
        有幾種方法

        我第一個解法是dp

        但其實這題也可以用組合數學處理

        問題是: 在0 ~ n - 1中
        挑出[l_1, r_1], [l_2, r_2], ... , [l_k, r_k]，共有2k個點
        且限制是
        0 <= l_1 < r_1 <= l_2 < r_2 <= l_3 < r_3 <= ... <= l_k < r_k <= n - 1
        以下參考AI
        如果整個不等式都是 < ，問題相當於從n個候選點中挑出2k個相異點
        但現在中間有<=
        在組合數學中消除<=可以用offset的方式(+ 1)
        也就是
        x_1 = l_1, x_2 = r_1
        x_3 = l2 + 1, x_4 = r_2 + 1
        x_5 = l_3 + 2, x_6 = r_3 + 2
        ...
        x_{2k - 1} = l_k + (k - 1)
        x_{2k} = r_k + (k - 1)

        問題等價於
        0 <= x_1 < x_2 < x_3 < x_4 < ... < x_{2k - 1} < x_{2k} <= (n - 1) + (k - 1)

        所以就是從 0 ~ (n + k - 2)共n + k - 1個點中挑2k個
        C_{2k}^{n + k - 1}

        剩下問題就只剩組合數運算 + mod模逆元處理
    */

    const int MOD = 1e9 + 7;

    long long qpow(long long a, long long b)
    {
        long long res = 1;
        a %= MOD;
        while (b > 0)
        {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    long long C(int n, int r)
    {
        if (r == 0 || r == n)
            return 1;
        
        long long numerator = 1;
        long long denominator = 1;
        for (int i = 0; i < r; ++i)
        {
            numerator = (numerator * (n - i)) % MOD;
            denominator = (denominator * (i + 1)) % MOD;
        }

        // 因為分母用除的，所以要用分母的模逆元
        // 用費馬小定理 a^{-1} = a^{P - 2} (mod P)
        return (numerator * qpow(denominator, MOD - 2)) % MOD;
    }

    int numberOfSets(int n, int k) 
    {
        return (int)C(n + k - 1, 2 * k);
    }
};