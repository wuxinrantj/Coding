/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
 *
 * https://leetcode-cn.com/problems/interval-list-intersections/description/
 *
 * algorithms
 * Medium (61.17%)
 * Likes:    44
 * Dislikes: 0
 * Total Accepted:    5.3K
 * Total Submissions: 8.5K
 * Testcase Example:  '[[0,2],[5,10],[13,23],[24,25]]\n[[1,5],[8,12],[15,24],[25,26]]'
 *
 * 给定两个由一些闭区间组成的列表，每个区间列表都是成对不相交的，并且已经排序。
 * 
 * 返回这两个区间列表的交集。
 * 
 * （形式上，闭区间 [a, b]（其中 a <= b）表示实数 x 的集合，而 a <= x <=
 * b。两个闭区间的交集是一组实数，要么为空集，要么为闭区间。例如，[1, 3] 和 [2, 4] 的交集为 [2, 3]。）
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 
 * 输入：A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
 * 输出：[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 * 注意：输入和所需的输出都是区间对象组成的列表，而不是数组或列表。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= A.length < 1000
 * 0 <= B.length < 1000
 * 0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        if(A.size() == 0 || B.size() == 0) {
            return {};
        }
        vector<vector<int>> res;
        int i = 0;
        int j = 0;

        while(i < A.size() && j < B.size()) {
            auto a0 = A[i][0];
            auto a1 = A[i][1];
            auto b0 = B[j][0];
            auto b1 = B[j][1];
            if(a0 <= b1 && a1 >= b0) {
                res.push_back({max(a0, b0), min(a1, b1)});
            }
            if(a1 < b1) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};
// @lc code=end

