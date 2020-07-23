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
    
    int ans;
    
    int dfs(TreeNode* node)
    {
        if(node==NULL) return 0;
        int left=dfs(node->left);
        int right=dfs(node->right);
        ans=max(ans,left+right+node->val);
        return max(0,node->val+max(left,right));
    }
    
public:
    int maxPathSum(TreeNode* root) {
        
        ans=INT_MIN;
        dfs(root);
        return ans;
        
    }
};