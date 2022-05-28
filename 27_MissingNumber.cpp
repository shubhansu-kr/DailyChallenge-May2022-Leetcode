// https://leetcode.com/problems/missing-number/

// Given an array nums containing n distinct numbers in the
// range [0, n], return the only number in the range that is missing
// from the array.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        for (int a : nums)
        {
            sum -= a;
        }
        return sum;
    }
};

int main()
{

    return 0;
}