#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }
//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM =
//             chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };


void ovo(){   
    int n, s; cin >> n >> s;
    vector <int> a (n);
    for (int & i : a) cin >> i;
    
    if (s == 0) {
        cout << 1 << '\n';
        return;
    }

    int x = n / 2, y = n - x;
    vector <int> l; l.reserve(1 << x);
    for (int i = 0; i < (1 << x); i ++) {
        int sum = 0;
        for (int b = 0; b < x; b ++) {
            if (i & (1 << b)) sum += a[b];
        }
        l.push_back(sum);
    }

    vector <int> r; r.reserve(1 << y);
    unordered_map <int, int> mp;
    mp.reserve(1 << 20);
    for (int i = 0; i < (1 << y); i ++) {
        int sum = 0;
        for (int b = 0; b < y; b ++) {
            if (i & (1 << b)) sum += a[x + b];
        }
        r.push_back(sum);
    }

    ranges :: sort (r);
    int ans = 0;
    for (int i = 0; i < l.size(); i ++) {
        int x = lower_bound(r.begin(), r.end(), s - l[i]) - r.begin();
        int y = upper_bound(r.begin(), r.end(), s - l[i]) - r.begin();
        ans += (y - x);
    }

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}