// https://leetcode.com/problems/132-pattern/

// Given an array of n integers nums, a 132 pattern is a
// subsequence of three integers nums[i], nums[j] and nums[k] s
// uch that i < j < k and nums[i] < nums[k] < nums[j].

// Return true if there is a 132 pattern in nums, otherwise, return false.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        if (nums.size() < 3) return false ;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] < nums[i + 1] && nums[i] < nums[i + 2] && nums[i + 1] > nums[i + 2])
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{

    return 0;
}