#include <stack>

using namespace std;

class MinStack {
public:
    stack<int> data_stack;
    stack<int> min_stack;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        data_stack.push(x);
        if (min_stack.empty() || x <= min_stack.top())
                min_stack.push(x);
    }
    
    void pop() {
        int top = data_stack.top();
        if (min_stack.top() == top)
            min_stack.pop();
        data_stack.pop();
    }
    
    int top() {
        return data_stack.top();
    }
    
    int min() {
        return min_stack.top();
    }
};