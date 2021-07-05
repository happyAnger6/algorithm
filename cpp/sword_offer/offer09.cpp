#include <stack>

using namespace std;

class CQueue {
stack<int> head, tail;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        tail.push(value);
    }
    
    int deleteHead() {
        if(head.empty()) {
            while(!tail.empty()) {
                head.push(tail.top());
                tail.pop();
            }
        }

        if(head.empty()) {
            return -1;
        }
        else {
            int ret = head.top();
            head.pop();
            return ret;
        }
    }
};