class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> todo;
        for (const auto & token : tokens) {
            if(token == "+"){
                int b = todo.top();
                todo.pop();
                int a = todo.top();
                todo.pop();
                todo.push(a + b);
            }
            else if(token == "-"){
                int b = todo.top();
                todo.pop();
                int a = todo.top();
                todo.pop();
                todo.push(a - b);
            }
            else if(token == "*"){
                int b = todo.top();
                todo.pop();
                int a = todo.top();
                todo.pop();
                todo.push(a * b);
            }
            else if(token == "/"){
                int b = todo.top();
                todo.pop();
                int a = todo.top();
                todo.pop();
                todo.push(a / b);
            }
            else{
                todo.push(stoi(token));
            }
        }
        return todo.top();
    }

};