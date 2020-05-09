#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() <= 1) {
			return;
		}
		int a = 0;//左上角，列
		int b = 0;//左上角，行
		int c = matrix[0].size() - 1;//右下角，列
		int d = matrix.size() - 1;//右下角，行
		while(a<=c && b<=d){
			rotateEdge(matrix, a++, b++, c--, d--);
		}
	}
	void rotateEdge(vector<vector<int>>& matrix, int a, int b, int c, int d){
		for (int i = 0; i < c - a; i++) {
			int temp = matrix[b][a+i];
			matrix[b][a+i] = matrix[d-i][a];
			matrix[d-i][a] = matrix[d][c-i];
			matrix[d][c-i] = matrix[b+i][c];
			matrix[b+i][c] = temp;
		}
	}
};

int main() {
    vector<vector<int>> matrix{ {15,13, 2, 5},
                                {14, 3, 4, 1},
                                {12, 6, 8, 9},
                                {16, 7,10,11}};
    Solution so;
    so.rotate(matrix);
    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << ',';
        }
        cout << endl;
    }
    return 0;
}