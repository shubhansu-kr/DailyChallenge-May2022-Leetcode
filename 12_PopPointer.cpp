// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

// Given a binary tree

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If 
// there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.


#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        Node *start = root, *dummy = new Node();
        while (start)
        {
            Node *prev = dummy, *cur = start;
            while (cur)
            {
                if (cur->left)
                    prev->next = cur->left, prev = cur->left;
                if (cur->right)
                    prev->next = cur->right, prev = cur->right;
                cur = cur->next;
            }
            start = dummy->next;
            dummy->next = nullptr;
        }
        delete dummy;
        return root;
    }
};

int main()
{

    return 0;
}