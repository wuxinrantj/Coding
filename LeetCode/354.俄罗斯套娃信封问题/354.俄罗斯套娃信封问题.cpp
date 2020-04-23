/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 *
 * https://leetcode-cn.com/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (34.41%)
 * Likes:    132
 * Dislikes: 0
 * Total Accepted:    9.4K
 * Total Submissions: 27.1K
 * Testcase Example:  '[[5,4],[6,4],[6,7],[2,3]]'
 *
 * 给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h)
 * 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
 * 
 * 请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
 * 
 * 说明:
 * 不允许旋转信封。
 * 
 * 示例:
 * 
 * 输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
 * 输出: 3 
 * 解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
 * 
 * 
 */

// @lc code=start
//先对宽度 w 进⾏升序排序，如果遇到 w 相同的情况，则按照⾼度 h 降序排序。之后把所有的 h 作为⼀个数组，在这个数组上计算 LIS 的⻓度
class Solution {
public:
    static bool cmp(vector<int>& p, vector<int>& q) {
        if(p[0] == q[0]) {
            return p[1] > q[1];
        }
        return p[0] < q[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size() == 0) return 0;
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> height;
        for(int i = 0; i < envelopes.size(); ++i){
            height.push_back(envelopes[i][1]);
        }
        return LIS(height);
    }

    int LIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
    
};
// @lc code=end

