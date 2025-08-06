class Solution {
public:
    void dfs(vector<vector<int>>& arr, int sr, int sc, int curr, int newColor) {
        int n = arr.size();
        int m = arr[0].size();
        if (sr < 0 || sc < 0 || sr >= n || sc >= m)
            return;
        if (arr[sr][sc] != curr)
            return;
        arr[sr][sc] = newColor;
        dfs(arr, sr + 1, sc, curr, newColor);
        dfs(arr, sr - 1, sc, curr, newColor);
        dfs(arr, sr, sc + 1, curr, newColor);
        dfs(arr, sr, sc - 1, curr, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        if(color==image[sr][sc]) return image;                          
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
};