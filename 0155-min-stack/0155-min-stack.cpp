class MinStack {
public:
    vector<int> elements;
    vector<int> mins;
    MinStack() {
        mins.push_back(INT_MAX);
    }

    void push(int val) {
        if (val <= mins.back()) {
            mins.push_back(val);
        }
        elements.push_back(val);
    }

    void pop() {
        if (elements.back() == mins.back()) {
            mins.pop_back();
        }
        elements.pop_back();
    }

    int top() {
        return elements.back();
    }

    int getMin() {
        return mins.back();
    }
};
