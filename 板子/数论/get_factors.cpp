#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

const int MAXN = 200005;
int min_prime[MAXN]; // 记录每个数 i 的最小质因子 (Smallest Prime Factor)
vector<int> primes;

void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (min_prime[i] == 0) { // i 是质数
            min_prime[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > min_prime[i] || i * p > n) break;
            min_prime[i * p] = p; // 每一个合数 i*p 都是被其最小质因子 p 筛掉的
        }
    }
}

// 配合这个函数，可以快速分解质因数
vector<int> get_unique_factors(int n) {
    vector<int> factors;
    while (n > 1) {
        int p = min_prime[n];
        factors.push_back(p);
        while (n % p == 0) n /= p; // 去掉所有相同的质因子
    }
    return factors;
}

void solve ()
{
    
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}   