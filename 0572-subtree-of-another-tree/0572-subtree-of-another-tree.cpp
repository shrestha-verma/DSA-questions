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
    bool isIdentical(TreeNode* root,TreeNode* subroot){
        if(root==NULL&&subroot==NULL) return true; //checking both nodes are null then return true;
        if(root==NULL||subroot==NULL) return false;  //checking if either of them is null than return false;
        if(root->val==subroot->val){
            return isIdentical(root->left,subroot->left)&& isIdentical(root->right,subroot->right);
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(subroot==NULL) return true;
        if(root==NULL) return false;

        if(isIdentical(root,subroot)) return true;

        return isSubtree(root->left,subroot)||isSubtree(root->right,subroot);
    }
};