#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;
using i128 = __int128_t;

void ovo(){   
    int n, q; cin >> n >> q;

    vector <int> a; a.reserve(n + 10);
    int bs = 1, cnt = 1;
    a.push_back(cnt);
    while (cnt < n) {
        bs <<= 1LL;
        cnt += bs;
        a.push_back(cnt);
        // cout << cnt << endl;Z`
    }

    int t;
    // cout << a.size() << endl;
    while (q --) {
        cin >> t;
        int pos = lower_bound(a.begin(), a.end(), t) - a.begin();
        // cout << pos << ' ';
        int x = a.size();
        if (pos == (x - 1)) {
            cout << (n - (1ULL << ((x - 1)) + 1)) << endl;
        } else {
            cout << (1ULL << (pos)) << endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}