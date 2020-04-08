#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//同435
class Solution {
public:
    static bool cmp(vector<int>& p, vector<int>& q) {
        return p[1] < q[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) {
            return 0;
        }

        sort(points.begin(), points.end(), cmp);
        int count = 0;
        int end = points[0][1];
        for(int i = 1; i < points.size(); ++i) {
            int start = points[i][0];
            if(start <= end) {
                count ++;
            } else {
                end = points[i][1];
            }
            
        }
        return points.size() - count;
    }
};

int main()
{
    vector<vector<int>> points{{10,16}, {2,8}, {1,6}, {7,12}};
    Solution so;
    auto ans = so.findMinArrowShots(points);

    cout << ans << endl;

    return 0;
}
