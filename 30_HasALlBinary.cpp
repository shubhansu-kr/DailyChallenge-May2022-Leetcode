// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

// Given a binary string s and an integer k, return true if every
// binary code of length k is a substring of s. Otherwise, return false.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        if (k > s.size())
            return false;
        unordered_set<string> mySet;
        for (int i = 0; i <= s.size() - k; ++i)
        {
            mySet.insert(s.substr(i, k));
        }
        return mySet.size() == (1 << k);
    }
};

class Solution
{
    // Recursion TLE
public:
    bool hasAllCodes(string s, int k)
    {
        string temp(k, '0');
        return check(temp, s);
    }
    bool check(string &temp, string &s, int i = 0)
    {
        if (i >= temp.size())
        {
            if (s.find(temp) == string::npos)
            {
                return false;
            }
            return true;
        }
        // Pick
        temp[i] = '0';
        if (check(temp, s, i + 1))
        {
            temp[i] = '1';
            return check(temp, s, i + 1);
        }
        return false;
    }
};

class Solution
{
    // TLE : Last 2 Test Case Failed
public:
    bool hasAllCodes(string s, int k)
    {
        for (int i = 0; i < (1 << k); ++i)
        {
            string temp;
            for (int j = 0; j < k; ++j)
            {
                if (i & (1 << j))
                {
                    temp.push_back('1');
                }
                else
                {
                    temp.push_back('0');
                }
            }
            if (s.find(temp) == string::npos)
            {
                return false;
            }
        }
        return true;
    }
};

class Solution
{

    // Time Limit Exceeded

    // "1011110111001001101001110001100111101111010101011100111001110010010001000111010110101110000110101001011100100010100110
    // 011101011110001000100010101101011"
    // 20
public:
    bool hasAllCodes(string s, int k)
    {
        // Create a vector of all the possible binary of size k
        vector<string> bin;
        for (int i = 0; i < (1 << k); ++i)
        {
            string temp;
            for (int j = 0; j < k; ++j)
            {
                if (i & (1 << j))
                {
                    temp.push_back('1');
                }
                else
                {
                    temp.push_back('0');
                }
            }
            bin.emplace_back(temp);
        }
        // All the possible binary are stored in the bin (Edit : No need to save the shit)
        // check if each binary exists in given string
        for (int i = 0; i < bin.size(); ++i)
        {
            if (s.find(bin[i]) == string::npos)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}