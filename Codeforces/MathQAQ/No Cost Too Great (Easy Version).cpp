
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

const int MAXN = 200005;
int mnp[MAXN]; // 记录每个数 i 的最小质因子 (Smallest Prime Factor)
vector<int> primes;

void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (mnp[i] == 0) { // i 是质数
            mnp[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > mnp[i] || i * p > n) break;
            mnp[i * p] = p; // 每一个合数 i*p 都是被其最小质因子 p 筛掉的
        }
    }
}

// 配合这个函数，可以快速分解质因数
void get_unique_factors(int n, map <int, int> & mp) {
    // vector<int> factors;
    while (n > 1) {
        int p = mnp[n];
        mp[p] ++;
        while (n % p == 0) n /= p; // 去掉所有相同的质因子
    }
}

void ovo() {   
    int n; cin >> n;
    vector <int> a (n);
    map <int, int> mp;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        get_unique_factors(a[i], mp);
        if (a[i] % 2 == 0) cnt ++;
    }

    if (mp.lower_bound(2) != mp.end() || cnt >= 2) {
        cout << 0 << '\n';
        return;
    }
    
    if (cnt > 0) {
        cout << 1 << '\n';
        return;
    }

    for (int i = 0; i < n; i ++) {
        get_unique_factors(a[i] + 1, mp);
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    sieve(MAXN);
    while(_--)  ovo();  return 0;
}