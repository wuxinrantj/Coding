
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits.back() += 1;

        for(int i = digits.size() - 1; i > 0; --i){
            if(digits[i] > 9){
                digits[i] -= 10;
                digits[i - 1] += 1;
            }
        }
        if(digits[0] > 9){
            digits[0] -= 10;
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};

int main(void)
{
    vector<int> digits{9,9};
    vector<int> ans;
    Solution so;
    ans = so.plusOne(digits);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans.at(i) << ',';

    return 0;
}
