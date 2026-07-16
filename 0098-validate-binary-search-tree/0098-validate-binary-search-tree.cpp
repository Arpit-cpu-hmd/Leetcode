/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    // Helper function with correct braces and boundary logic
    bool validateHelper(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (root == nullptr) {
            return true;
        }

        // The current node's value must be strictly greater than the min node's value
        if (minNode != nullptr && root->val <= minNode->val) {
            return false;
        }

        // The current node's value must be strictly less than the max node's value
        if (maxNode != nullptr && root->val >= maxNode->val) {
            return false;
        }

        // Recursively check the left and right subtrees with updated constraints
        return validateHelper(root->left, minNode, root) && 
               validateHelper(root->right, root, maxNode);
    }

public:
    bool isValidBST(TreeNode* root) {
        // Start the recursion with no limits (nullptr)
        return validateHelper(root, nullptr, nullptr);
    }
};
