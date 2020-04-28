/*
 * @lc app=leetcode.cn id=LCP 11 lang=cpp
 *
 * [LCP 11] 期望个数统计
 *
 * https://leetcode-cn.com/problems/qi-wang-ge-shu-tong-ji/
 *
 * algorithms
 * Easy (48.39%)
 * Likes:    2
 * Dislikes: 0
 * Total Accepted:    1.5K
 * Total Submissions: 3.1K
 * 
 *
 * 某互联网公司一年一度的春招开始了，一共有 n 名面试者入选。每名面试者都会提交一份简历，公司会根据提供的简历资料产生一个预估的能力值，
 * 数值越大代表越有可能通过面试。小 A 和小 B 负责审核面试者，他们均有所有面试者的简历，并且将各自根据面试者能力值从大到小的顺序浏览。
 * 由于简历事先被打乱过，能力值相同的简历的出现顺序是从它们的全排列中等可能地取一个。现在给定 n 名面试者的能力值 scores，设 X 代表
 * 小 A 和小 B 的浏览顺序中出现在同一位置的简历数，求 X 的期望。
 *
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入：scores = [1,2,3]
 * 输出：3
 * 解释：由于面试者能力值互不相同，小 A 和小 B 的浏览顺序一定是相同的。X的期望是 3 。
 * 
 * 
 * 示例 2:
 * 
 * 输入：scores = [1,1]
 * 输出：1
 * 解释：设两位面试者的编号为 0, 1。由于他们的能力值都是 1，小 A 和小 B 的浏览顺序都为从全排列 [[0,1],[1,0]] 中等可能地取一个。如果
 * 小 A 和小 B 的浏览顺序都是 [0,1] 或者 [1,0] ，那么出现在同一位置的简历数为 2 ，否则是 0 。所以 X 的期望是 (2+0+2+0) * 1/4 = 1
 * 
 * 
 * 示例 3:
 * 
 * 输入：scores = [1,1,2]
 * 输出：2
 * 
 */

// @lc code=start
// n个数字随机进行排列，位置没变的数字总数的期望为1
class Solution {
public:
    int expectNumber(vector<int>& scores) {
        sort(scores.begin(),scores.end());
        scores.erase(unique(scores.begin(),scores.end()),scores.end());
        return scores.size();
    }
};
// @lc code=end
