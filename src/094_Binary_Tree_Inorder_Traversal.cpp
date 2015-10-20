/**
 * @author          johnsondu
 * @problem         Binary Tree Inorder Traversal
 * @url             https://leetcode.com/problems/binary-tree-inorder-traversal/
 * @timeComlexity   O(n)
 * @spaceComplexity O(n)
 * @strategy        left child -> root -> right child, recursive
 * @status          Accepted, defeated 12.90% cpp submissions.
 * @version         recursive
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
        if(root == NULL) return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        inorder(root, vec);
        return vec;
    }
};


/**
 * @author          johnsondu
 * @problem         Binary Tree Inorder Traversal
 * @url             https://leetcode.com/problems/binary-tree-inorder-traversal/
 * @timeComlexity   O(n)
 * @spaceComplexity O(n)
 * @strategy        left child -> root -> right child, stack to store
 * @status          Accepted, defeated 12.90% cpp submissions.
 * @version         iteration
 * @time            18:36, Oct 20 2015
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        if(root == NULL) return vec;
        
        stack<TreeNode*> st;
        TreeNode *cur = root;
        while(!st.empty() || cur != NULL) {
            while(cur != NULL) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            vec.push_back(cur->val);
            cur = cur->right;
        }
        return vec;
    }
};
