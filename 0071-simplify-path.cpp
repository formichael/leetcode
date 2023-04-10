class Solution {
public:
    string simplifyPath(string path) {
        int start = 0, end = 0;
        stack<string> stk;
        stk.push("/");
        path.append("/");

        while ((end = path.find("/", start)) != std::string::npos) {
            if (end == start) {
                start++;
                continue;
            }

            string sub = path.substr(start, end - start);
            if (sub == "." || sub == "/") {

            } else if (sub == "..") {
                if (stk.size() > 1) {
                    stk.pop();
                }
            } else {
                stk.push(sub);
            }

            start = end + 1;
        }

        vector<string> tmp;
        while (!stk.empty()) {
            tmp.push_back(stk.top());
            stk.pop();
        }

        stringstream ss;
        for (int i = tmp.size() - 1; i >= 0; i--) {
            if (i == tmp.size() - 1 || i == 0)
                ss << tmp[i];
            else
                ss << tmp[i] << "/";
        }

        return ss.str();
    }
};
