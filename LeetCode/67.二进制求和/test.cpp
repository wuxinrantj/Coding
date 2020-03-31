
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size()){
            return addBinary(b,a);
        }
        
        for(int i = b.size() - 1; i >= 0; --i){
            a[a.size() - b.size() + i] += b[i] - '0';
        }
        for(int j = a.size() - 1; j > 0; --j){
            if(a[j] > '1'){
                a[j] -= 2;
                a[j - 1] += 1;
            }
        }
        if(a[0] > '1'){
            a[0] -= 2;
            a = '1' + a;
        }
        return a;
    }
};

int main(void)
{
    string a = "1111";
    string b = "1111";
    string ans;
    Solution so;
    ans = so.addBinary(a, b);
    cout << ans << endl;

    return 0;
}
