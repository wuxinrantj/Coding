#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int origColor = grid[r0][c0];
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
        refill(grid, r0, c0, origColor, color, visited);
        
        return grid;
    }

    int refill(vector<vector<int>>& image, int x, int y, int origColor, int newColor, vector<vector<bool>>& visited) {
        if(x < 0 || x >= image.size() || y < 0 || y >= image[0].size()) {
            return 0;
        }
        if (visited[x][y]) {
            return 1;
        }
        if(image[x][y] != origColor) {
            return 0;
        }
        
        visited[x][y] = true; //打标记，避免重复；
        //区域边界上的坐标，⾄少有⼀个⽅向不是 origColor，⽽区域内部的坐标，四⾯都是 origColor，
        int around = refill(image, x - 1, y, origColor, newColor, visited) + 
                     refill(image, x + 1, y, origColor, newColor, visited) +
                     refill(image, x, y - 1, origColor, newColor, visited) +
                     refill(image, x, y + 1, origColor, newColor, visited);
        if (around < 4) {
            image[x][y] = newColor;
        }

        // image[x][y] == origColor 
        return 1;
    }

};

int main() {
    vector<vector<int>> image{{1,2,2},{2,3,2}};
    int sr = 0;
    int sc = 1;
    int newColor = 3;
    Solution so;
    auto ans = so.colorBorder(image, sr, sc, newColor);
    for(int i = 0; i < ans.size(); ++i) {
        for(int j = 0; j < ans[0].size(); ++j) {
            cout << ans[i][j] << ',';
        }
        cout << endl;
    }
    return 0;
}