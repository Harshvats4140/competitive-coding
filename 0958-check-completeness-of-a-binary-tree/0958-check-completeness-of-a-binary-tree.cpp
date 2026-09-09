#include <queue>

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        
        std::queue<TreeNode*> q;
        q.push(root);
        bool pastNull = false;
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node == nullptr) {
                // We encountered the first null node
                pastNull = true;
            } else {
                // If we find a real node after seeing a null, it's not complete
                if (pastNull) {
                    return false;
                }
                
                // Push children to the queue (including nulls)
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return true;
    }
};