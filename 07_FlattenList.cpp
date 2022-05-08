// https://leetcode.com/problems/flatten-nested-list-iterator/

#include <bits/stdc++.h>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator
{
    vector<int> nums;
    int i = -1;
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        flatten(nestedList);
    }

    void flatten(vector<NestedInteger> a)
    {
        for (auto x : a)
        {
            if (x.isInteger())
                nums.push_back(x.getInteger());
            else
                flatten(x.getList());
        }
        return;
    }

    int next()
    {
        return nums[++i];
    }

    bool hasNext()
    {
        return (i+1 < nums.size()) ;
    }
};

int main()
{
    /*
     * Your NestedIterator object will be instantiated and called as such:
     * NestedIterator i(nestedList);
     * while (i.hasNext()) cout << i.next();
     */
    return 0;
}