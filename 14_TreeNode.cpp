// https://leetcode.com/problems/deepest-leaves-sum/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int sum = 0;
    int deep = 0;

    void dfs(TreeNode *root, int depth)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
        {
            if (depth == deep)
            {
                sum += root->val;
            }
            else if (depth > deep)
            {
                sum = root->val;
                deep = depth;
            }
        }

        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

    int deepestLeavesSum(TreeNode *root)
    {
        dfs(root, 0);
        return sum;
    }
};

int main()
{

    return 0;
}