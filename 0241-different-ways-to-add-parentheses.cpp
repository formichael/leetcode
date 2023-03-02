class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ways;

        for (int i = 0; i < expression.size(); ++i) {
            const char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                auto lefts = diffWaysToCompute(expression.substr(0, i));
                auto rights = diffWaysToCompute(expression.substr(i + 1));
                for (auto left : lefts) {
                    for (auto right : rights) {
                        switch (c) {
                        case '+':
                            ways.push_back(left + right);
                            break;
                        case '-':
                            ways.push_back(left - right);
                            break;
                        case '*':
                            ways.push_back(left * right);
                            break;
                        }
                    }
                }
            }
        }

        if (ways.empty()) {
            ways.push_back(stoi(expression));
        }

        return ways;
    }
};
