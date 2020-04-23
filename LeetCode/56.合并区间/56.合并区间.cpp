/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (40.63%)
 * Likes:    406
 * Dislikes: 0
 * Total Accepted:    90.3K
 * Total Submissions: 213.1K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 示例 1:
 * 
 * 输入: [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 */

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int>& p, vector<int>& q) {
        return p[0] < q[0];   //按start排序
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) {
            return {};
        }
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), cmp);
        res.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); ++i) {
            auto cur = intervals[i];
            auto last = res.back();
            if(cur[0] <= last[1]) {
                res.back()[1] = max(last[1], cur[1]);
            } else {
                res.push_back(cur);
            }
        }
        return res;
    }
};
// @lc code=end

