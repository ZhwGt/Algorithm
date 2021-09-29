/* 
求1-n所有数的欧拉函数和。
筛法时间复杂度是O(n).

筛法就是在求1-n所有质数时，顺便把所有的数的欧拉函数求一遍。
f(n) = n * (1 - 1/p1) * ... , p1, p2..pn是质数

*/

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 1000010;

int primes[N], cnt;
int phi[N];
bool st[N];

void get_eulers(int n)
{
    phi[1] = 1;
    for (int i = 2; i <= n; i++) //求解2-n的质数
    {
        if (!st[i]) //质数
        {
            primes[cnt++] = i;
            phi[i] = i - 1; //质数的欧拉函数 
        }
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true; //被最小质因子筛掉
            if (i % primes[j] == 0)
            {
                phi[primes[j] * i] = phi[i] * primes[j]; // prime[j]质因子已经被计算法，仅扩大n的作用
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1); //筛掉数的欧拉函数
        }
    }
}

int main()
{
    int n;
    cin >> n;

    get_eulers(n);

    LL res = 0;
    for (int i = 1; i <= n; i++) res += phi[i];
    printf("%lld\n", res);

    return 0;
}
