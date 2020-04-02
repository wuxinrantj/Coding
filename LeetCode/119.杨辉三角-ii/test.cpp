
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<int> res(rowIndex + 1, 1);
        for(int i = 0; i <= rowIndex; ++i) {
            for(int j = i; j > 1; --j) {
                res[j - 1] = res[j - 2] + res[j - 1];
            }
        }
        return res;
        
    }
};

int main()
{
    int n = 2;
    vector<int> ans;
    Solution so;
    ans = so.getRow(n);

    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << ",";
    }	

    return 0;
}
