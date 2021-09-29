/* 
欧拉函数定义：f(n)表示1-n中与n互质的数的个数。
n = p1^{a1} * p2^{a2} * ... * pk^{ak}。
f(n) = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk)。
证明是容斥原理。
时间复杂度：求整数n的质因子是根号n的时间复杂度，假设质因子是m个m次计算得到结果，时间复杂度是根号n的(m << n)。
*/

#include <iostream>
using namespace std;

int main()
{
    int q;
    cin >> q;
    
    while (q -- ){
        int n;
        cin >> n;
        
        int res = n;
        for (int i = 2; i <= n / i; i ++ )
            if (n % i == 0){
                res = res / i * (i - 1);
                while (n % i == 0) n /= i;
            }
        if (n > 1) res = res / n * (n - 1);
        
        cout << res << endl;
    }
    return 0;
}
