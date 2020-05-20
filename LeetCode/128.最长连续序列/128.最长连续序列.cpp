/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (48.26%)
 * Likes:    330
 * Dislikes: 0
 * Total Accepted:    39.5K
 * Total Submissions: 80.6K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组，找出最长连续序列的长度。
 * 
 * 要求算法的时间复杂度为 O(n)。
 * 
 * 示例:
 * 
 * 输入: [100, 4, 200, 1, 3, 2]
 * 输出: 4
 * 解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 */

// @lc code=start
// 并查集
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        for(int i: nums) parent[i] = i, count[i] = 1;
        int ans = 1;
        for(int i: nums){
            if(parent.count(i+1)) ans = max(ans, merge(i, i+1));
        }
        return ans;
    }

private:
    unordered_map<int,int> parent, count;
    
    /* 返回某个节点 x 的根节点 */
    int find(int x) {
        // 根节点的 parent[x] == x
        while (parent[x] != x) {
            // 路径压缩
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    int merge(int x, int y){
        x = find(x); y = find(y);
        if(x == y) return count[x];
        parent[y] = x;
        //更新合并之后的连通分量的元素个数
        count[x] += count[y];
        return count[x];
    }

};
// @lc code=end

