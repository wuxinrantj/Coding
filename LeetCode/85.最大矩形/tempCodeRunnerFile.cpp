#include <iostream>
#include <vector>

using namespace std;
// 参考84，求出每一层的 heights[] 然后传给上一题的函数
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        vector<int> heights(matrix[0].size() + 2, 0);
        int maxArea = 0;
        for (int row = 0; row < matrix.size(); row++) {
            //遍历每一列，更新高度
            for (int col = 0; col < matrix[0].size(); col++) {
                if (matrix[row][col] == '1') {
                    heights[col + 1] += 1;
                } else {
                    heights[col + 1] = 0;
                }
            }
            //调用上一题的解法，更新函数
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        vector<int> stack;
        // heights.insert(heights.begin(), 0);
        // heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            while (!stack.empty() && heights[stack.back()] > heights[i]) {
                int cur = stack.back();
                stack.pop_back();
                int left = stack.back() + 1;
                int right = i - 1;
                res = max(res, (right - left + 1) * heights[cur]);
            }
            stack.push_back(i);
        }
        return res;
    }
};

int main() {
    vector<vector<char>> matrix{{'1','0'},
                                {'1','0'}};
    Solution so;
    auto ans = so.maximalRectangle(matrix);
    cout << ans;
    return 0;
}