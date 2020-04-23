#include <iostream>
#include <vector>

using namespace std;
//Sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrim(n, true);
        for(int i = 2; i * i < n; ++i) {
            if(isPrim[i]) {
                for(int j = i * i; j < n; j += i) {
                    isPrim[j] = false;
                }
            }
        }
        int count = 0;
        for(int k = 2; k < n; ++k) {
            if(isPrim[k]) count ++;
        }
        return count;
    }
};

int main() {
    int n = 10;
    Solution so;
    auto ans = so.countPrimes(n);
    cout << ans << endl;
    return 0;
}