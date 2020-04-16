#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        auto x = peek();
        s2.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
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
int main() {
    MyQueue so;
    so.push(2);
    so.push(3);
    int param_2 = so.pop();
    int param_3 = so.peek();
    bool param_4 = so.empty();
    cout << param_2 << endl;
    cout << param_3 << endl;
    cout << boolalpha << param_4 << endl;
}