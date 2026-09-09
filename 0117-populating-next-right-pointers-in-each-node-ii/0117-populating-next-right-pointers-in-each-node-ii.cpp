class Solution {
public:
    Node* connect(Node* root) {
        Node* current = root; // Points to the current node we are processing
        
        while (current != nullptr) {
            Node* dummy = new Node(0); // Dummy node to track the head of the next level
            Node* prev = dummy;        // Pointer used to link nodes in the next level
            
            // Traverse all nodes on the current level
            while (current != nullptr) {
                if (current->left) {
                    prev->next = current->left;
                    prev = prev->next;
                }
                if (current->right) {
                    prev->next = current->right;
                    prev = prev->next;
                }
                
                // Move to the next node in the current level
                current = current->next;
            }
            
            // Move to the start of the next level
            current = dummy->next;
            delete dummy; // Clean up the dummy node to avoid memory leaks
        }
        
        return root;
    }
};