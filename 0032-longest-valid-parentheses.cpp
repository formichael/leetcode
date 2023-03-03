class Solution {
public:
    int longestValidParentheses(string s) {
       int cnt = 0;
       stack<int> stk;
       stk.push(-1);

       for (int i = 0; i < s.size(); ++i) {
           if (s[i] == '(') {
               stk.push(i);
           } else {
               stk.pop();

               if (stk.empty()) {
                   stk.push(i);
               } else {
                   cnt = max(cnt, i - stk.top());
               }
           }
       }

       return cnt;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
       int cnt = 0;
       int open = 0, close = 0;

       for (int i = 0; i < s.size(); ++i) {
           if (s[i] == '(') {
               ++open;
           } else {
               ++close;
           }

           if (open == close) {
               cnt = max(cnt, open + close);
           }

           if (open < close) {
               open = 0;
               close = 0;
           }
       }

        open = 0;
        close = 0;

       for (int i = s.size(); i >= 0; --i) {
           if (s[i] == ')') {
               ++close;
           } else {
               ++open;
           }

           if (open == close) {
               cnt = max(cnt, open + close);
           }

           if (open > close) {
               open = 0;
               close = 0;
           }
       }

       return cnt;
    }
};
