// https://leetcode.com/problems/maximum-product-of-word-lengths/

// Given a string array words, return the maximum value of
// length(word[i]) * length(word[j]) where the two words do not
// share common letters. If no such two words exist, return 0.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Brute Force : TLE 
public:
    bool isValid(string a, string b)
    {
        vector<int> freq(26, 0);
        for (char &x : a)
        {
            ++freq[x - 97];
        }
        for (char &x : b)
        {
            if (freq[x - 97])
            {
                return false;
            }
        }
        return true;
    }
    int maxProduct(vector<string> &words)
    {
        int prod = 0;
        // code
        sort(words.begin(), words.end(), [](string a, string b)
             { return b.size() < a.size(); });
        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = i + 1; j < words.size(); ++j)
            {
                if (isValid(words[i], words[j]))
                {
                    int sss = words[i].size() * words[j].size();
                    prod = max(prod, sss);
                }
            }
        }
        return prod;
    }
};

int main()
{
    vector<string> words = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
    sort(words.begin(), words.end(), [](string a, string b)
         { return b.size() < a.size(); });
    for (string s : words)
    {
        cout << s << " ";
    }
    return 0;
}