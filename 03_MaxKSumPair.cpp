// https://leetcode.com/problems/max-number-of-k-sum-pairs/

// You are given an integer array nums and an integer k.

// In one operation, you can pick two numbers from the array
// whose sum equals k and remove them from the array.

// Return the maximum number of operations you can perform
// on the array.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Brute Force: Without sort  (TLE)
public:
    int maxOperations(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= k)
                continue;
            if (nums[i])
            {
                for (int j = i + 1; j < nums.size(); j++)
                {
                    if (nums[j])
                    {
                        int s = nums[i] + nums[j];
                        if (nums[j] >= k || s > k)
                            continue;
                        if (s == k)
                        {
                            ++count;
                            nums[j] = 0;
                            break;
                        }
                    }
                }
            }
        }
        return count;
    }
};

class Solution
{
    // Brute force : Time Limit Exceeded 
public:
    int maxOperations(vector<int> &nums, int k)
    {
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= k)
                break;
            if (nums[i])
            {
                for (int j = i + 1; j < nums.size(); j++)
                {
                    if (nums[j])
                    {
                        int s = nums[i] + nums[j];
                        if (nums[j] >= k || s > k)
                            break;
                        if (s == k)
                        {
                            ++count;
                            nums[j] = 0;
                            break;
                        }
                    }
                }
            }
        }
        return count;
    }
};

int main()
{
    return 0;
}