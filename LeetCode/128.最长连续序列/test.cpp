#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
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

int main() {
    vector<int> nums{100, 4, 200, 1, 3, 2};
    Solution so;
    auto ans = so.longestConsecutive(nums);
    cout << ans;
    return 0;
}