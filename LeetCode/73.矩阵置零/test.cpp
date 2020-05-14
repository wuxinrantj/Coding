#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool rowflag = false;
        bool colflag = false;

        for(int i = 0; i < matrix.size(); ++i) {
            if(matrix[i][0] == 0) {
                colflag = true;
                break;
            }
        }

        for(int j = 0; j < matrix[0].size(); ++j) {
            if(matrix[0][j] == 0) {
                rowflag = true;
                break;
            }
        }

        for(int i = 1; i < matrix.size(); ++i) {
            for(int j = 1; j < matrix[0].size(); ++j) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < matrix.size(); ++i) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < matrix[0].size(); ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for(int j = 1; j < matrix[0].size(); ++j) {
            if(matrix[0][j] == 0) {
                for(int i = 1; i < matrix.size(); ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(colflag) {
            for(int i = 0; i < matrix.size(); ++i) {
                matrix[i][0] = 0;
            }
        }

        if(rowflag) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                matrix[0][j] = 0;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix{ {0,1,2,0},
                                {3,4,5,2},
                                {1,3,1,5}};
    Solution so;
    so.setZeroes(matrix);
    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] <<',';
        }
        cout << endl;
    }
    return 0;
}