class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() < 3)
            return true;

        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];
        int dx = coordinates[1][0] - x1;
        int dy = coordinates[1][1] - y1;

        for (int i = 2; i < coordinates.size(); i++) {
            if (dx * (coordinates[i][1] - y1) != dy * (coordinates[i][0] - x1))
                return false;
        }

        return true;
    }
};
