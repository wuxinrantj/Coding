/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 *
 * https://leetcode-cn.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (41.85%)
 * Likes:    314
 * Dislikes: 0
 * Total Accepted:    40.7K
 * Total Submissions: 97.3K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord
 * 的最短转换序列的长度。转换需遵循如下规则：
 * 
 * 
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 * 
 * 
 * 说明:
 * 
 * 
 * 如果不存在这样的转换序列，返回 0。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 输出: 5
 * 
 * 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * ⁠    返回它的长度 5。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * 输出: 0
 * 
 * 解释: endWord "cog" 不在字典中，所以无法进行转换。
 * 
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(wordSet.count(endWord) == 0) return 0;//list中没有要查找单词

        unordered_set<string> upTodown({beginWord});
        unordered_set<string> downToup({endWord});
        int word_size = beginWord.size();
        int list_size = wordList.size();
        vector<int> flag(list_size, 0);//标记是否已经找到过 避免形成环
        int res = 2;
        while(!upTodown.empty()){
            unordered_set<string> next;//下一层元素
            for(auto& word : upTodown){
                for(int i=0; i<list_size; ++i){//在list中找差一个字母的单词
                    int count = 0;
                    for(int j=0; j<word_size; ++j){
                        if(word[j] != wordList[i][j]) count++;
                        if(count > 1) break;
                    }
                    if(count == 1){//只差一个字母
                        if(downToup.count(wordList[i]) != 0) return res;//该单词在从下至上 有了 返回结果
                        if(flag[i] == 0) next.insert(wordList[i]);//没用过的再添加
                        flag[i] = 1;
                    }
                } 
            }
            res++;
            upTodown = next;
            if(upTodown.size() > downToup.size()) swap(upTodown, downToup);//双dfs 每次从元素少的开始找
        }
        return 0;
    }
};
// @lc code=end

