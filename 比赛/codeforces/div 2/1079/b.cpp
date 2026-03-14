
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

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

void ovo(){   
    int n;  cin >> n;
    vector <int> p (n), a (n);
    unordered_map<long long, int, custom_hash> mp;
    mp.reserve(n);
    mp.max_load_factor(0.7);
    for (int i = 0; i < n; i ++) {
        cin >> p[i];
        mp[p[i]] = i;
    }
    for (int & j : a)  cin >> j;

    int ps = mp[a[0]];
    for (int i = 1; i < n; i ++) {
        int now = mp[a[i]];
        if (now < ps) {
            cout  << "NO" << '\n';
            return;
        } else {
            ps = now;
        }
    }

    cout << "YES" << '\n';


}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}