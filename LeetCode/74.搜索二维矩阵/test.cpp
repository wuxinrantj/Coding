#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0 || target < matrix[0][0]) return false;
        int up = 0;
        int down = matrix.size();
        int rowmid;
        int left = 0;
        int right = matrix[0].size();

        while(up < down) {
            rowmid = up + (down - up) / 2;
            if(matrix[rowmid][0] == target) {
                return true;
            } else if(matrix[rowmid][0] < target) {
                up = rowmid + 1;
            } else {
                down = rowmid;
            }
        }

        while(left < right) {
            int colmid = left + (right - left) / 2;
            if(matrix[up - 1][colmid] == target) {
                return true;
            } else if(matrix[up - 1][colmid] < target) {
                left = colmid + 1;
            } else {
                right = colmid;
            }
        }

        return false;
    }
};

int main() {
    vector<vector<int>> matrix{{1,3,5,7},{9,11,13,15},{17,19,21,23}};
    int target = 3;
    Solution so;
    auto ans = so.searchMatrix(matrix, target);
    cout << boolalpha << ans ;
    return 0;
}