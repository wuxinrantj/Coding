#include <iostream>
#include <vector>

using namespace std;
//单调栈
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    int res = 0;
    vector<int> stack;
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
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
    vector<int> heights{2,1,5,6,2,3};
    Solution so;
    auto ans = so.largestRectangleArea(heights);
    cout<< ans;
    return 0;
}