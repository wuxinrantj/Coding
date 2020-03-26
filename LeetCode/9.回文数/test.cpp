
#include <iostream>
#include <math.h>
#include<cmath>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }
        if (x < 10)
        {
            return true;
        }

        int i;
        i = log10(x) + 1;

        while (i > 0)
        {
            if (x % 10 != int (x / pow(10 , (i - 1))))
            {
                return false;
            }
            x = x % int(pow(10 , (i - 1))) / 10;
            i -= 2;
        }
        
        return true;
    }
};

int main(void)
{

    int x = 121;
    bool ans;
    Solution so;
    ans = so.isPalindrome(x);
    cout << boolalpha << ans << endl;

    return 0;
}
