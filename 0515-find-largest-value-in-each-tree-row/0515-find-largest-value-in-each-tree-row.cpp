#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

class Solution {
public:
    std::vector<int> largestValues(TreeNode* root) {
        std::vector<int> result;
        if (!root) return result;
        
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            int currentMax = INT_MIN; // Start with the minimum possible integer
            
            // Process all nodes at the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                // Update the maximum value found on this row
                currentMax = std::max(currentMax, node->val);
                
                // Push children to the queue for the next level
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            
            // Add the row's maximum value to the result
            result.push_back(currentMax);
        }
        
        return result;
    }
};