#include <queue>
#include <algorithm>

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        long long maxWidth = 0;
        // Queue stores pairs of (Node pointer, index)
        std::queue<std::pair<TreeNode*, long long>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            int levelSize = q.size();
            long long levelMinIndex = q.front().second; 
            long long firstIndex = 0, lastIndex = 0;
            
            // Process all nodes at the current level
            for (int i = 0; i < levelSize; ++i) {
                // Subtract levelMinIndex to prevent integer overflow
                long long currentIndex = q.front().second - levelMinIndex;
                TreeNode* node = q.front().first;
                q.pop();
                
                // Track the first and last indices of the current level
                if (i == 0) firstIndex = currentIndex;
                if (i == levelSize - 1) lastIndex = currentIndex;
                
                // Push children with their respective formula-based indices
                if (node->left) {
                    q.push({node->left, 2 * currentIndex});
                }
                if (node->right) {
                    q.push({node->right, 2 * currentIndex + 1});
                }
            }
            
            // Update the maximum width found so far
            maxWidth = std::max(maxWidth, lastIndex - firstIndex + 1);
        }
        
        return maxWidth;
    }
};