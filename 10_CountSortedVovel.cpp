// https://leetcode.com/problems/count-sorted-vovel-strings/

// Given an integer n, return the number of strings of length n that consists
// only of vovel and are lexicographically sroted.

// A string s is lexicographically sorted if for alll valid i, s[i] is
// the same as or comes before s[i+1] in the alphabet.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countVovelStrings(int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(6));
        for (int i = 1; i <= n; ++i)
            for (int k = 1; k <= 5; ++k)
                dp[i][k] = dp[i][k - 1] + (i > 1 ? dp[i - 1][k] : 1);
        return dp[n][5];
    }
};

int main()
{

    return 0;
}