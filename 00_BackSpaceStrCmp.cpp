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
    // Discussion solution
public:
    bool backspaceCompare(string s, string t)
    {
        int i = s.length() - 1, j = t.length() - 1;
        int skips = 0, skipt = 0;
        while (i >= 0 || j >= 0)
        {
            while (i >= 0)
            {
                if (s[i] == '#')
                    skips++, i--;
                else if (skips > 0)
                    skips--, i--;
                else
                    break;
            }
            while (j >= 0)
            {
                if (t[j] == '#')
                    skipt++, j--;
                else if (skipt > 0)
                    skipt--, j--;
                else
                    break;
            }
            if (i >= 0 && j >= 0 && s[i] != t[j])
                return false;
            // One string gets empty, unequal length string also result in false
            if (i >= 0 ^ j >= 0)
                return false;
            i--, j--;
        }
        return true;
    }
};

class Solution
{
    // Try solving using stack
    // Wrong solution
public:
    void edit(string &s)
    {
        stack<char> p;
        for (auto a : s)
        {
            p.push(a);
        }
        s.clear();
        while (!s.empty())
        {
            if (p.top() == '#')
            {
                p.pop();
                p.pop();
            }
            else
            {
                s.push_back(p.top());
                p.pop();
            }
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