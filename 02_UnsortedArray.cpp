// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

// Given an integer array nums, you need to find one continuous
// subarray that if you only sort this subarray in ascending order,
// then the whole array will be sorted in ascending order.

// Return the shortest such subarray and output its length.

#include <bits/stdc++.h>
using namespace std;

class Solution1
{

public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        // Min track Approach
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
        if (end != -1)
        {
            // find min and max between front and end
            int minS = INT_MAX, maxS = INT_MIN;
            for (int i = front; i <= end; ++i)
            {
                minS = min(minS, nums[i]);
                maxS = max(maxS, nums[i]);
            }
            // Now we have min and max, and we have toh find the end points
            // in nums array so that they can match
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] > minS)
                {
                    front = i;
                    break;
                }
            }
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                if (nums[i] < maxS)
                {
                    end = i;
                    break;
                }
            }
        }
        return end - front + 1;
    }
};

class Solution
{
    // Brute force approach :
    // Sort and compare : O(NlogN + 2N) time , O(N) space
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        // Approach 1  : Sort the array and find the difference
        vector<int> temp = nums;
        sort(nums.begin(), nums.end());
        if (temp == nums)
        {
            return 0;
        }
        int front, end;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != temp[i])
            {
                front = i;
                break;
            }
        }
        for (int i = nums.size() - 1; i > 0; --i)
        {
            if (nums[i] != temp[i])
            {
                end = i;
                break;
            }
        }
        return end - front + 1;
    }
};

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