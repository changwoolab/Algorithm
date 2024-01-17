// https://leetcode.com/problems/min-stack/solutions/4580942/c-easy-solution-using-2-vectors/

class MinStack {
private:
    vector<int> stack;
    vector<int> minStack;

public:
    MinStack() {
    }
    
    void push(int val) {
        if (minStack.empty()) {
            minStack.push_back(val);
        } else {
            int _min = min(minStack.back(), val);
            if (_min >= val) minStack.push_back(val);
        }
        stack.push_back(val);
    }
    
    void pop() {
        if (stack.back() == minStack.back()) minStack.pop_back();
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};
