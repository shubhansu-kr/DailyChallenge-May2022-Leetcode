// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

// Given an integer array nums, you need to find one continuous
// subarray that if you only sort this subarray in ascending order,
// then the whole array will be sorted in ascending order.

// Return the shortest such subarray and output its length.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Incomplete approach : Wrong answer. 
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        // Approach 1 : find the i and j of the sub array
        // traverse twice and find i once and find j once

        int front = 0, end = -1;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] > nums[i + 1])
            {
                front = i;
                break;
            }
        }
        for (int i = nums.size() - 1; i > 0; --i)
        {
            if (nums[i] < nums[i - 1])
            {
                end = i;
                break;
            }
        }
        return (end - front + 1);
    }
};

int main()
{

    return 0;
}