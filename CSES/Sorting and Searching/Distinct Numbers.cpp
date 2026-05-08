#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
 
 
void ovo() {
    int n; cin >> n;
    // unordered_map <int, int> mp;
    // map <int, int> mp;
 
 
    unordered_map<long long, int, custom_hash> mp;
    // 估计会插入 m 个不同 key：
    mp.reserve(n + 5);
    mp.max_load_factor(0.7);
 
    vector <int> a (n);
    for (int i =0; i < n; i ++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    
    // sort (a.begin(), a.end());
    // // cout << mp.size() << '\n';
    // int cnt = 1;
    // for (int i = 1; i < n; i ++) {
    //     if (a[i] != a[i - 1]) {
    //         cnt++;
    //     }
    // }
 
    cout << mp.size() << '\n';
}
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;
 
    while (_--) ovo();
}