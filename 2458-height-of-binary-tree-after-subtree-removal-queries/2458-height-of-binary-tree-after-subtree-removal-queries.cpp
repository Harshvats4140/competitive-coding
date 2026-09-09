#include <vector>
#include <algorithm>

class Solution {
private:
    // Array to store the max tree height if the node with value 'i' is removed.
    // Constraints say n <= 10^5, so 100005 is safe.
    int max_height_without[100005]; 
    int current_max;

    void traverseLeftToRight(TreeNode* node, int depth) {
        if (!node) return;
        
        // The max height without this node (looking at nodes to its left)
        max_height_without[node->val] = current_max;
        
        // Update the max depth seen so far
        current_max = std::max(current_max, depth);
        
        // Standard Left-then-Right traversal
        traverseLeftToRight(node->left, depth + 1);
        traverseLeftToRight(node->right, depth + 1);
    }

    void traverseRightToLeft(TreeNode* node, int depth) {
        if (!node) return;
        
        // The max height without this node is the max of the left-side traversal
        // and the right-side traversal (current_max).
        max_height_without[node->val] = std::max(max_height_without[node->val], current_max);
        
        // Update the max depth seen so far
        current_max = std::max(current_max, depth);
        
        // Mirrored Right-then-Left traversal
        traverseRightToLeft(node->right, depth + 1);
        traverseRightToLeft(node->left, depth + 1);
    }

public:
    std::vector<int> treeQueries(TreeNode* root, std::vector<int>& queries) {
        // First pass
        current_max = 0;
        traverseLeftToRight(root, 0);
        
        // Second pass
        current_max = 0;
        traverseRightToLeft(root, 0);
        
        // Answer all queries in O(1) time each
        std::vector<int> result;
        result.reserve(queries.size());
        for (int q : queries) {
            result.push_back(max_height_without[q]);
        }
        
        return result;
    }
};