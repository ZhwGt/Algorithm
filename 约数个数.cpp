/* 
约数定理：
任何一个整数都可以表示为：N = p1^{a} * p2^{b} * p3^{c} * pk^{k}
整数N的约数个数是(a + 1) * (b + 1) * (c + 1) * ... * (pk + 1)
*/

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
typedef long long LL;
int main()
{
    int q;
    cin >> q;
    
    unordered_map<int, int> hash;
    while(q -- ){
        int n;
        cin >> n;
        
        for (int i = 2; i <= n / i; i ++ )
            while (n % i == 0) n /= i, hash[i] ++ ;
        
        if (n > 1) hash[n] ++ ;
    }
    
    LL res = 1;
    for (auto &x : hash) res = res * (x.second + 1) % mod;
    
    cout << res << endl;
    
    return 0;
}
