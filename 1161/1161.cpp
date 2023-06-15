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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);
        
        int sumAtCurrentLevel;
        int maxSum = INT_MIN, ans, level = 1;
        while (!bfsQueue.empty()) {
            int n = bfsQueue.size();
            sumAtCurrentLevel = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* curr = bfsQueue.front();
                bfsQueue.pop();
                
                if (curr->left != NULL)
                    bfsQueue.push(curr->left);
                if (curr->right != NULL)
                    bfsQueue.push(curr->right);
                
                sumAtCurrentLevel += curr->val;
            }
            
            if (sumAtCurrentLevel > maxSum) {
                maxSum = sumAtCurrentLevel;
                ans = level;
            }
            
            level++;
        }
        
        return ans;
    }
};
