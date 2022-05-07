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
        int s3 = INT_MIN;
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (nums[i] < s3)
                return true;
            else
                while (!st.empty() && nums[i] > st.top())
                {
                    s3 = st.top();
                    st.pop();
                }
            st.push(nums[i]);
        }
        return false;
    }
};

class Solution
{
    // Brute Force : Time Limit Exceeded :()
public:
    bool find132pattern(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] > nums[i])
                {
                    for (int k = j + 1; k < nums.size(); k++)
                    {
                        if (nums[k] > nums[i] && nums[k] < nums[j])
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};

class Solution
{
    // Wrong answer : i, j, k are not consecutive.
public:
    bool find132pattern(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;
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
    cout << "[";
    for (int i = 0; i < 1000; i++)
    {
        cout << i << ", ";
    }
    cout << "1000]";
    return 0;
}