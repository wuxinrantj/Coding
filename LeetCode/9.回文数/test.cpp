
#include <iostream>
#include <math.h>
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

        int i = 0;
        int y = x;
        while (x != 0)
        {
            x /= 10;
            i++;
        }

        while (i > 0)
        {
            if (y % 10 != int (y / pow(10 , (i - 1))))
            {
                return false;
            }
            y = y % int(pow(10 , (i - 1))) / 10;
            i -= 2;
        }
        
        return true;
    }
};

int main(void)
{

    int x = 12231;
    bool ans;
    Solution so;
    ans = so.isPalindrome(x);
    cout << boolalpha << ans << endl;

    return 0;
}
