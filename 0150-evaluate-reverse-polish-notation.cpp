class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        stack<int> stk;

        for (auto &token : tokens) {
            if (token == "+") {
                assert(stk.size() > 1);
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(a + b);
            }
            else if (token == "-") {
                assert(stk.size() > 1);
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(b - a);
            }
            else if (token == "*") {
                assert(stk.size() > 1);
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(a * b);
            }
            else if (token == "/") {
                assert(stk.size() > 1);
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(b / a);
            }
            else {
                stk.push(stoi(token));
            }
        }

        if (!stk.empty())
            ans = stk.top();
        
        return ans;
    }
};
