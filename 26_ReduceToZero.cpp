// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

// Given an integer num, return the number of steps to reduce it to zero.

// In one step, if the current number is even, you have to divide
// it by 2, otherwise, you have to subtract 1 from it.

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // Discussion solution 
public:
    int numberOfSteps(int num)
    {
        return num ? __builtin_popcount(num) + 31 - __builtin_clz(num) : 0;
    }
};

class Solution
{
    // Brute force
public:
    int numberOfSteps(int num)
    {
        int count = 0;
        while (num)
        {
            if (num % 2 == 0)
            {
                num /= 2;
            }
            else
            {
                --num;
            }
            ++count;
        }
        return count;
    }
};

int main()
{

    return 0;
}