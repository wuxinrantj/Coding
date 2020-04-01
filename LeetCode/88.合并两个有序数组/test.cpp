
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0; i < n; ++i) {
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(),nums1.end());
    }
};

int main(void)
{
    int m = 3;
    vector<int> nums1{1,2,3,0,0,0};
    int n = 3;
    vector<int> nums2{2,5,6};

    Solution so;
    so.merge(nums1, m , nums2, n);
    for (int i = 0; i < nums1.size(); ++i)
        cout << nums1.at(i) << ',';

    return 0;
}
