#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
    char findTheDifference(string s, string t) 
    {
        this->quickSort(s, 0, s.size() - 1);
        this->quickSort(t, 0, t.size() - 1);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != t[i])
                return t[i];
        }
        return t[t.size() - 1];
    }
private:
    void swap(char* c1, char* c2)
    {
        char temp = *c1;
        *c1 = *c2;
        *c2 = temp;
    }

    int partition(string &str, int front, int end)
    {
        char pivot = str[end];
        int index = front - 1;
        for (int i = front; i < end; i++)
        {
            if (str[i] < pivot)
            {
                index++;
                this->swap(&str[index], &str[i]);
            }
        }
        index++;
        swap(&str[index], &str[end]);
        return index;
    }

    void quickSort(string &str, int front, int end)
    {
        if (front < end)
        {
            int pivot = this->partition(str, front, end);
            this->quickSort(str, front, pivot - 1);
            this->quickSort(str, pivot + 1, end);
        }
    }
};