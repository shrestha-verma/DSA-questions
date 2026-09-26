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
    public:
vector<vector<int>> levelOrder(TreeNode* root) {
        // 1. Final answer 2D vector 
        vector<vector<int>> ans;

        // Base case: root is null
        if (root == NULL) {
            return ans;
        } 

        // 2. Queue pointer type TreeNode* 
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> curans; // temproaory vector to store node data of that particular level. 

            for (int i = 0; i < size; i++) {
                // storing q.front() in curr variable.
                TreeNode* curr = q.front();
                q.pop(); //imprtant to pop so that queue get empty. 

                // storing value oin curans. 
                curans.push_back(curr->val);

                // pushing left and right child. 
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }

            // final answer will be puhed in ans, important it will be added after for loop so that all value did not get added in same queue.  
        
            ans.push_back(curans);
        }

        return ans;
    }
};