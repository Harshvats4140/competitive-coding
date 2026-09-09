#include <vector>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if (!root) return result;
        
        std::queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        
        while (!q.empty()) {
            int levelSize = q.size();
            // Pre-allocate the vector with the exact size of the current level
            std::vector<int> currentLevel(levelSize);
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                // Determine where to place the value based on the current direction
                int index = leftToRight ? i : (levelSize - 1 - i);
                currentLevel[index] = node->val;
                
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            
            // Toggle the direction for the next level
            leftToRight = !leftToRight;
            result.push_back(currentLevel);
        }
        
        return result;
    }
};