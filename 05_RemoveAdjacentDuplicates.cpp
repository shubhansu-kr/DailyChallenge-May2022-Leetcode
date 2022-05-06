// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

// You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal
// letters from s and removing them, causing the left and the right
// side of the deleted substring to concatenate together.

// We repeatedly make k duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have
// been made. It is guaranteed that the answer is unique.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Discusison solution 
public:
    string removeDuplicates(string s, int k)
    {
        int n = s.size();
        if (n < k)
            return s;

        stack<pair<char, int>> stk;
        for (int i = 0; i < n; ++i)
        {
            if (stk.empty() || stk.top().first != s[i])
                stk.push({s[i], 1});
            else
            {
                auto prev = stk.top();
                stk.pop();
                stk.push({s[i], prev.second + 1});
            }
            if (stk.top().second == k)
                stk.pop();
        }

        string ans = "";
        while (!stk.empty())
        {
            auto cur = stk.top();
            stk.pop();
            while (cur.second--)
            {
                ans.push_back(cur.first);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution
{
    // Runtime error 
public:
    string removeDuplicates(string s, int k)
    {
        // Using stack
        stack<pair<char, int>> p;
        p.push({s[0], 1});
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == p.top().first)
            {
                ++p.top().second;
            }
            else
            {
                p.push({s[i], 1});
            }
            if (p.top().second == k)
            {
                p.pop();
            }
        }
        // Reconstruct the string
        s.clear();
        while (!p.empty())
        {
            if (p.top().second)
            {
                s.push_back(p.top().first);
                --p.top().second;
            }
            else
            {
                p.pop();
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

class Solution
{
    // Time limit Exceeded
public:
    string removeDuplicates(string s, int k)
    {
        // Two pointer approach

        while (s.length() >= k)
        {
            int flag = 1;
            int i = 0, len = 0;
            for (int j = 0; j < s.length(); j++)
            {
                if (s[i] == s[j])
                {
                    ++len;
                    if (len == k)
                    {
                        s.erase(i, len);
                        j = i;
                        len = 1, flag = 0;
                    }
                }
                else
                {
                    if (len == k)
                    {
                        s.erase(i, len);
                        j = i, flag = 0;
                    }
                    else
                    {
                        i = j;
                    }
                    len = 1;
                }
            }
            if (flag)
            {
                break;
            }
        }
        return s;
    }
};

int main()
{

    return 0;
}