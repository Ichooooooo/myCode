
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

const int MAXN = 2e7;
int mnp[MAXN]; // 记录每个数 i 的最小质因子 (Smallest Prime Factor)
vector<int> primes;
int ans;

void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (mnp[i] == 0) { // i 是质数
            mnp[i] = i;
            ans += i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > mnp[i] || i * p > n) break;
            mnp[i * p] = p; // 每一个合数 i*p 都是被其最小质因子 p 筛掉的
        }
    }
}

void ovo() {
    const int N = 2e6;
    sieve(N);

    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}