class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        if (len % 2 != 0) {
            return false;
        }

        std::stack<char> stk;
        for (auto c : s) {
            if (stk.empty()) {
                stk.push(c);
                continue;
            }

            char t = stk.top();
            if ( (t == '(' && c == ')') ||
                 (t == '[' && c == ']') ||
                 (t == '{' && c == '}') ) {
                stk.pop();
            } else {
                stk.push(c);
            }
        }

        return stk.empty();
    }
};
