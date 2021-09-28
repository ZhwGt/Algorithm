/* 
约数之和
整数的表示形式 N = p1^{a} + p2^{b} + p3^{c} + ... 
约数之和定理: sum = (p1^{0} + p1^{1} + ... p1^{a}) * (p2^{0} + p2^{1} + p2^{b}) * ... 
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
    while (q -- ){
        int n;
        cin >> n;
        
        for (int i = 2; i <= n / i; i ++ )
            while (n % i == 0) n /= i, hash[i] ++ ;
        if (n > 1) hash[n] ++ ;
    }
    
    LL res = 1;
    for (auto [a, b] : hash){
        LL t = 1;
        while (b -- ) t = (t * a + 1) % mod;
        
        res = res * t % mod;
    }
    
    cout << res << endl;
    
    return 0;
}
