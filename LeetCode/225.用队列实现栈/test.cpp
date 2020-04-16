#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q;
    int topelem = 0;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        topelem = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        for(int i = q.size(); i > 1; --i) {
            q.push(q.front());
            q.pop();
        }
        topelem = q.back();
        auto x = q.front();
        q.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return topelem;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack so;
    so.push(1);
    so.push(2);
    so.push(3);
    int param_2 = so.pop();
    int param_3 = so.top();
    bool param_4 = so.empty();
    cout << param_2 << endl;
    cout << param_3 << endl;
    cout << boolalpha << param_4 << endl;
}
