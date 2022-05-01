// https://leetcode.com/problems/backspace-string-compare/

// Given two strings s and t, return true if they are equal
// when both are typed into empty text editors. '#' means a
// backspace character.

// Note that after backspacing an empty text, the
// text will continue empty.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void edit(string &s)
    {
        int i = 0;
        while (i < s.length())
        {
            if (s[i] == '#')
            {
                if (i > 0)
                {
                    s.erase(i - 1, 2);
                    --i;
                }
                else
                {
                    s.erase(i, 1);
                }
                continue;
            }
            ++i;
        }
    }
    bool backspaceCompare(string s, string t)
    {
        edit(s);
        edit(t);
        return s == t;
    }
};

class Solution
{
    // Wrong answer :
    // "sh##" "s#f#" -> Expected : true , output : false
public:
    bool backspaceCompare(string s, string t)
    {
        // Using extra space
        string ss, st;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] != '#' && s[i + 1] != '#')
            {
                ss.push_back(s[i]);
            }
        }
        for (int i = 0; i < t.length() - 1; i++)
        {
            if (t[i] != '#' && t[i + 1] != '#')
            {
                st.push_back(t[i]);
            }
        }
        if (s.back() != '#')
        {
            ss.push_back(s.back());
        }
        if (t.back() != '#')
        {
            st.push_back(t.back());
        }
        return ss == st;
    }
};

int main()
{

    return 0;
}