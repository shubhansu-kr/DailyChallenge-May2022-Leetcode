// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        return original == nullptr ? nullptr : original == target                                ? cloned
                                           : getTargetCopy(original->left, cloned->left, target) ?
                                                                                                 : getTargetCopy(original->right, cloned->right, target);
    }
};

int main()
{

    return 0;
}