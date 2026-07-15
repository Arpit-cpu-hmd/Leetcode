class Solution {
private:
    int idx = -1; 

    
    void helper(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }

        helper(root->left, result);          
        result.push_back(root->val);        
        helper(root->right, result);         
    }

public:
    TreeNode* buildTree(const vector<int>& nodes) {
        idx++;
        if (idx >= nodes.size() || nodes[idx] == -1) {
            return nullptr;
        }

        TreeNode* currnode = new TreeNode(nodes[idx]);
        currnode->left = buildTree(nodes);
        currnode->right = buildTree(nodes);

        return currnode;
    }

    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result); 
        return result;        
    }
};