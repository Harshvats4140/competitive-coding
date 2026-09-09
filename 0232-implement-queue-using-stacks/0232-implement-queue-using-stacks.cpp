#include <stack>

class MyQueue {
private:
    std::stack<int> in_stack;
    std::stack<int> out_stack;

    // Helper method to move elements when out_stack is empty
    void transferIfNeeded() {
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
    }

public:
    MyQueue() {
        
    }
    
    // Pushes element x to the back of the queue.
    void push(int x) {
        in_stack.push(x);
    }
    
    // Removes the element from the front of the queue and returns it.
    int pop() {
        transferIfNeeded();
        int front_element = out_stack.top();
        out_stack.pop();
        return front_element;
    }
    
    // Returns the element at the front of the queue.
    int peek() {
        transferIfNeeded();
        return out_stack.top();
    }
    
    // Returns true if the queue is empty, false otherwise.
    bool empty() {
        return in_stack.empty() && out_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */