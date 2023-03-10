class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }

    void dfs(vector<vector<int>>& image, int i, int j, int oldColor, int color) {
        if (i >= image.size() || i < 0 || j >= image[i].size() || j < 0 ||
            image[i][j] == color || image[i][j] != oldColor)
            return;
        
        image[i][j] = color;

        dfs(image, i, j - 1, oldColor, color);
        dfs(image, i + 1, j, oldColor, color);
        dfs(image, i, j + 1, oldColor, color);
        dfs(image, i - 1, j, oldColor, color);
    }
};
