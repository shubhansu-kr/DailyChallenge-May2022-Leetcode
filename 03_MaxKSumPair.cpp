// https://leetcode.com/problems/max-number-of-k-k-pairs/

// You are given an integer array nums and an integer k.

// In one operation, you can pick two numbers from the array
// whose k equals k and remove them from the array.

// Return the maximum number of operations you can perform
// on the array.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Discussion solution 
public:
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (int e : nums)
            freq[e]++;
        int ans = 0;
        for (auto &[u, v] : freq)
        {
            if (2 * u == k)
                ans += v / 2, v -= v / 2 * 2;
            else if (v > 0 && freq.count(k - u) && freq[k - u] > 0)
            {
                int pair_cnt = min(v, freq[k - u]);
                ans += pair_cnt;
                v -= pair_cnt;
                freq[k - u] -= pair_cnt;
            }
        }
        return ans;
    }
};

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        // Using Hashing
        unordered_map<int, int> p;
        for (auto a : nums)
            p[a]++;
        int count = 0;
        for (auto &a : p)
        {
            if (2 * a.first  == k)
            {
                count += a.second / 2;
                a.second -= a.second / 2 * 2;
            }
            else if (a.second > 0 && p.count(k - a.first) && p[k - a.first] > 0)
            {
                // code
                int c = min(a.second, p[k - a.first]);
                count += c;
                a.second -= c;
                p[k - a.first] -= c;
            }
        }
        return count;
    }
};

class Solution
{
    // Brute Force: Without sort  (TLE)
public:
    int maxOperations(vector<int> &nums, int k)
    {
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