/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 *
 * https://leetcode-cn.com/problems/rotate-image/description/
 *
 * algorithms
 * Medium (67.37%)
 * Likes:    435
 * Dislikes: 0
 * Total Accepted:    71K
 * Total Submissions: 104.3K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个 n × n 的二维矩阵表示一个图像。
 * 
 * 将图像顺时针旋转 90 度。
 * 
 * 说明：
 * 
 * 你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
 * 
 * 示例 1:
 * 
 * 给定 matrix = 
 * [
 * ⁠ [1,2,3],
 * ⁠ [4,5,6],
 * ⁠ [7,8,9]
 * ],
 * 
 * 原地旋转输入矩阵，使其变为:
 * [
 * ⁠ [7,4,1],
 * ⁠ [8,5,2],
 * ⁠ [9,6,3]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 给定 matrix =
 * [
 * ⁠ [ 5, 1, 9,11],
 * ⁠ [ 2, 4, 8,10],
 * ⁠ [13, 3, 6, 7],
 * ⁠ [15,14,12,16]
 * ], 
 * 
 * 原地旋转输入矩阵，使其变为:
 * [
 * ⁠ [15,13, 2, 5],
 * ⁠ [14, 3, 4, 1],
 * ⁠ [12, 6, 8, 9],
 * ⁠ [16, 7,10,11]
 * ]
 * 
 * 
 */

// @lc code=start
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
// @lc code=end

