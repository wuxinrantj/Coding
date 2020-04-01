
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m + n - 1;

        while (m > 0 && n > 0) {
            if(nums1[m - 1] > nums2[n - 1]) {
                nums1[p] = nums1[m - 1];
                --p;--m;
            } else {
                nums1[p] = nums2[n -1];
                --p;--n;
            }
        }
        
        while (n > 0) {
            nums1[p] = nums2[n - 1];
            --p;--n;
        }
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
