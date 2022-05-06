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