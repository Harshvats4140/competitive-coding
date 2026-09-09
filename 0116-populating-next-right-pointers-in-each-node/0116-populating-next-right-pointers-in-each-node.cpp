class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        Node* head = root; // Points to the start of the current level
        
        // Loop until we reach the last level (which has no children)
        while (head->left != nullptr) {
            Node* current = head;
            
            // Traverse the current level using the next pointers
            while (current != nullptr) {
                // 1. Connect the left child to the right child
                current->left->next = current->right;
                
                // 2. Connect the right child to the next node's left child
                if (current->next != nullptr) {
                    current->right->next = current->next->left;
                }
                
                // Move to the next node on the current level
                current = current->next;
            }
            
            // Move to the start of the next level
            head = head->left;
        }
        
        return root;
    }
};