// https://leetcode.com/problems/sort-array-by-parity/

// Given an integer array nums, move all the even integers at the
// beginning of the array followed by all the odd integers.

// Return any array that satisfies this condition.

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        // Approach 1 : insert and erase ;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                int temp = nums[i];
                nums.erase(nums.begin() + i, nums.begin() + i + 1);
                nums.insert(nums.begin(), temp);
            }
        }
        return nums;
    }
};

class Solution
{
    // 210 ms : Really slow 
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        // Approach 1 : insert and erase ;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                int temp = nums[i];
                nums.erase(nums.begin() + i, nums.begin() + i + 1);
                nums.insert(nums.begin(), temp);
            }
        }
        return nums;
    }
};

int main()
{

    return 0;
}