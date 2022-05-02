// https://leetcode.com/problems/sort-array-by-parity/

// Given an integer array nums, move all the even integers at the
// beginning of the array followed by all the odd integers.

// Return any array that satisfies this condition.

#include <bits/stdc++.h>
using namespace std;

class Solution3
{
    // Swapping
public:
    vector<int> sortArrayByParity(vector<int> &nums) {
        int l = 0, r = nums.size() -1 ;
        while ( l < r) {
            if (nums[l] % 2 != 0) {
                swap (nums[l], nums[r]);
                --r ;
            }
            else {
                ++l ;
            }
        } 
        return nums ;
    }
};

class Solution2
{

public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        // Approach 1 : Erase odd
        int flag = 0;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (flag)
            {
                if (nums[i] % 2 != 0)
                {
                    nums.push_back(nums[i]);
                    nums.erase(nums.begin() + i, nums.begin() + i + 1);
                }
            }
            else
            {
                if (nums[i] % 2 == 0)
                {
                    flag = 1;
                }
            }
        }
        return nums;
    }
};
class Solution2
{
    // Wrong answer : Infinitive loop :(
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        // Approach 1 : Erase odd
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 != 0)
            {
                nums.push_back(nums[i]);
                nums.erase(nums.begin() + i, nums.begin() + i + 1);
                // Since we are adding at the end and erasing from the front need to correct
                // the index
                --i;
            }
        }
        return nums;
    }
};

class Solution1
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        // Approach 1 : Using stack
        stack<int> odd, even;
        for (auto a : nums)
        {
            if (a % 2 == 0)
            {
                even.push(a);
            }
            else
            {
                odd.push(a);
            }
        }
        nums.clear();
        while (!even.empty())
        {
            nums.push_back(even.top());
            even.pop();
        }
        while (!odd.empty())
        {
            nums.push_back(odd.top());
            odd.pop();
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