class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    /** Push element x onto stack. */
    void push(int x) {
        //常にq１をスタクとして使う。q２は一時的な置き場所
        q2.push(x);

        while(q1.size() > 0){
            q2.push(q1.front());
            q1.pop();
        }

        while(q2.size() > 0){
            q1.push(q2.front());
            q2.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = q1.front();
        q1.pop();
        return top;
    }

    /** Get the top element. */
    int top() {
        int top = q1.front();

        return top;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.size() == 0 && q2.size() == 0;
    }
};

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

        while(s1.size() > 0){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(s2.size() > 0){
            s1.push(s2.top());
            s2.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = peek();
        s1.pop();
        return val;
    }

    /** Get the front element. */
    int peek() {
        return s1.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.size() == 0;
    }
};


bool isValid(string s) {

    stack<char> brackets_stack;

    unordered_set<char> left_brackets;
    left_brackets.insert('(');
    left_brackets.insert('[');
    left_brackets.insert('{');

    unordered_set<char> right_brackets;
    right_brackets.insert(')');
    right_brackets.insert(']');
    right_brackets.insert('}');

    unordered_map<char, char> pairs;
    pairs[')'] = '(';
    pairs[']'] = '[';
    pairs['}'] = '{';

    for(int i = 0; i < s.size(); i++){

        if(left_brackets.find(s[i]) != left_brackets.end()){
            brackets_stack.push(s[i]);
        }else{
            if(brackets_stack.size() == 0) return false;
            if(pairs[s[i]] == brackets_stack.top()){
                brackets_stack.pop();
            }else{
                return false;
            }
        }
    }

    return brackets_stack.size() == 0;

}
