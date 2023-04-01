class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n < 1)
            return {};

        return generateTree(1, n);
    }

    vector<TreeNode*> generateTree(int min, int max) {
        if (min > max)
            return {nullptr};

        vector<TreeNode*> ans;
        
        for (int i = min; i <= max; ++i) {
            auto left = generateTree(min, i - 1);
            auto right = generateTree(i + 1, max);
            for (auto l : left) {
                for (auto r : right) {
                    ans.push_back(new TreeNode(i));
                    ans.back()->left = l;
                    ans.back()->right = r;
                }
            }
        }

        return ans;
    }
};
