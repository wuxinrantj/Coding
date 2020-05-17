/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 *
 * https://leetcode-cn.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (46.13%)
 * Likes:    267
 * Dislikes: 0
 * Total Accepted:    41.3K
 * Total Submissions: 88.5K
 * Testcase Example:  '"25525511135"'
 *
 * 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
 * 
 * 有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: "25525511135"
 * 输出: ["255.255.11.135", "255.255.111.35"]
 * 
 */

// @lc code=start
// 回溯
class Solution {
public:
    bool isValid(string ip){
        int val = stoi(ip);  // stoi（字符串，起始位置，n进制），将 n 进制的字符串转化为十进制
        if (val > 255)    return false;
        if (ip.size() >= 2 && ip[0] == '0')    return false;
        return true;
    }

    void dfs(string& s, int pos, vector<string> &path, vector<string>& res) {
        //4组，每组最多3位数字
        int maxLen = (4 - path.size()) * 3;
        if (s.size() - pos > maxLen)    return;
        if (path.size() == 4 && pos == s.size()) { //放 . 
            string ans = "";
            for (int i = 0; i < 4; ++i) {
                ans += path[i];
                if (i != 3)    ans += ".";
            }
            res.push_back(ans);
            return;
        }
        //回溯算法的典型模式，循环递归
        for (int i = pos; i < s.size() && i <= pos + 2; ++i) {
            string ip = s.substr(pos, i - pos + 1);
            if (!isValid(ip))    continue;
            path.push_back(ip);
            dfs(s, i + 1, path, res);
            path.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s){
        vector<string> res;
        if (s.size() == 0 || s.size() < 4)    return res;
        vector<string> path;//存储从根开始的到叶子节点的满足条件的路径,因为最多3位数字一组，所以同一层横向循环时尝试最多3个位的长度
        dfs(s, 0, path, res);
        return res;
    }
};
// @lc code=end

