#include <iostream>
#include <vector>

using namespace std;
//回溯
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int origColor = image[sr][sc];
        refill(image, sr, sc, origColor, newColor);
        return image;
    }

    void refill(vector<vector<int>>& image, int x, int y, int origColor, int newColor) {
        if(x < 0 || x >= image.size() || y < 0 || y >= image[0].size()) {
            return;
        }
        if(image[x][y] != origColor) {
            return;
        }
        if(image[x][y] == -1) {
            return;
        }

        image[x][y] = -1; //打标记，避免重复；
        refill(image, x - 1, y, origColor, newColor);
        refill(image, x + 1, y, origColor, newColor);
        refill(image, x, y - 1, origColor, newColor);
        refill(image, x, y + 1, origColor, newColor);
        image[x][y] = newColor;
    }

};

int main() {
    vector<vector<int>> image{{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1;
    int sc = 1;
    int newColor = 2;
    Solution so;
    auto ans = so.floodFill(image, sr, sc, newColor);
    for(int i = 0; i < ans.size(); ++i) {
        for(int j = 0; j < ans.size(); ++j) {
            cout << ans[i][j] << ',';
        }
        cout << endl;
    }
    return 0;
}