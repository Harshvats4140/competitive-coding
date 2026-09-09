#include <vector>
#include <queue>

class Solution {
public:
    std::vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> result;
        if (!root) return result;
        
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            double levelSum = 0; // Use double to prevent overflow and ensure precise division
            
            // Process all nodes at the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                levelSum += node->val;
                
                // Add children to the queue for the next level
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            
            // Calculate the average and add it to the result
            result.push_back(levelSum / levelSize);
        }
        
        return result;
    }
};