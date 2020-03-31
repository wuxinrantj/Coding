/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (52.23%)
 * Likes:    331
 * Dislikes: 0
 * Total Accepted:    72.4K
 * Total Submissions: 138.3K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size()){
            return addBinary(b,a);
        }
        
        for(int i = b.size() - 1; i >= 0; --i){
            a[a.size() - b.size() + i] += b[i] - '0';
        }
        for(int j = a.size() - 1; j > 0; --j){
            if(a[j] > '1'){
                a[j] -= 2;
                a[j - 1] += 1;
            }
        }
        if(a[0] > '1'){
            a[0] -= 2;
            a = '1' + a;
        }
        return a;
    }
};
// @lc code=end

