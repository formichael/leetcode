class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> out;
        int left = 0, right = numbers.size() - 1, sum = 0;

        while (left < right) {
            sum = numbers[left] + numbers[right];
            if (sum == target) {
                out.push_back(left + 1);
                out.push_back(right + 1);
                break;
            }
            else if (sum < target) {
                ++left;
            }
            else { // sum > target
                --right;
            }
        }

        return out;
    }
};
