
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
using arr3 = array <int, 3>;
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
    int n, x; 
    cin >> n >> x;

    vector <int> a (n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    unordered_map <int, int, custom_hash> mp;

    for (int i = 0; i < n; i ++) {
        if (mp.find(x - a[i]) != mp.end()) {
            cout << mp[x - a[i]] + 1 << ' ' << i + 1 << '\n';
            return;
        }

        mp[a[i]] = i;
    }

    cout << "IMPOSSIBLE" << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}