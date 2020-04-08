#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
 //sort()必须是静态成员函数
    static bool cmp(vector<int>& p, vector<int>& q) {
        return p[1] < q[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), cmp);
        int count = 0;
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i) {
            int start = intervals[i][0];
            if(start < end) {
                count ++;
            } else {
                end = intervals[i][1];
            }
            
        }
        return count;
    }
};

int main()
{
    vector<vector<int>> intervals{{1,2}, {2,3}, {3,4}, {1,3}};
    Solution so;
    auto ans = so.eraseOverlapIntervals(intervals);

    cout << ans << endl;

    return 0;
}
