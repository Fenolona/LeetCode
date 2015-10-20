/**
 * @author          johnsondu
 * @problem         Binary Tree Inorder Traversal
 * @url             https://leetcode.com/problems/binary-tree-inorder-traversal/
 * @timeComlexity   O(n)
 * @spaceComplexity O(n)
 * @strategy        left child -> root -> right child
 * @status          Accepted, defeated 12.90% cpp submissions.
 * @time            10:11, Oct 20 2015
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& vec) {
        if(root->left != NULL) inorder(root->left, vec);
        vec.push_back(root->val);
        if(root->right != NULL) inorder(root->right, vec);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        if(root == NULL) return vec;
        inorder(root, vec);
        return vec;
    }
};