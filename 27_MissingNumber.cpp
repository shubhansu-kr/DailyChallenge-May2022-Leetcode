// https://leetcode.com/problems/missing-number/

// Given an array nums containing n distinct numbers in the
// range [0, n], return the only number in the range that is missing
// from the array.

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // Bit Manipulation
public:
    int missingNumber(vector<int> &nums)
    {
        int result = nums.size(); // initialize result to size of vector
        int i = 0;                // initialize i to 0
        for (int num : nums)
        {                  // for each number in vector
            result ^= num; // XOR result with number
            result ^= i;   // XOR result with i
            i++;           // increment i
        }
        return result; // return result that is the missing number
    }
};

class Solution
{
    // Brute Force: (Intution)
    // Time Complexity : O(N)
    // Space complexity : O(1)
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