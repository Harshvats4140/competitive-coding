#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;
        if (!root) return result;
        
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            // Traverse all nodes at the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = q.front();
                q.pop();
                
                // If this is the last node in the current level, add it to our result
                if (i == levelSize - 1) {
                    result.push_back(currentNode->val);
                }
                
                // Push children to the queue for the next level
                if (currentNode->left) {
                    q.push(currentNode->left);
                }
                if (currentNode->right) {
                    q.push(currentNode->right);
                }
            }
        }
        
        return result;
    }
};