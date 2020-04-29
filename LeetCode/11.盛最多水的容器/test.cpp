#include <iostream>
#include <vector>

using namespace std;

//每次选定围成水槽两板高度中的短板，向中间收窄 1 格。
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0, j = height.size() - 1;
        while(i < j) {
            auto s = 0;
            
            if(height[i] < height[j]) {
                s = height[i] * (j - i);
                ++i;
            } else {
                s = height[j] * (j - i);
                --j;
            }
            res = max(res, s);
        }

        return res;
    }
};

int main() {
    vector<int> height{1,8,6,2,5,4,8,3,7};
    Solution so;
    auto ans = so.maxArea(height);
    cout << ans << endl;

    return 0;
}