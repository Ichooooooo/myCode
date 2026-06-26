// 卡常数(卡时间) : 1. 卡map的log
// 2. 卡unorsered_map两个, 两个常数翻倍
// 3. 卡custom_hash的reserve
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

    // mp1 : canto, mp2 : cnt
    // unordered_map <int, pair <int, int> > mp;
    unordered_map <int, pair <int, int> , custom_hash> mp;
    mp.reserve (40 * n);
    mp.max_load_factor(0.7);

    for (int i = 1; i <= n; i ++) {
        int x; cin >> x;

        int ok = 0;
        if (x == 2) ok = 1;
        // cerr << "i : " << x << '\n';
        mp[x].first++;

        int cn = 0;
        while (x != 1) {
            if (x & 1) {
                x++;
            } else {
                x /= 2;
            }
            if (x == 2) ok = 1;
            cn++; 

            // cerr << "now : " << x << ' ' << cn << '\n';
            mp[x].first++;
            mp[x].second += cn;
        }

        if (!ok) {
            cn++;
            mp[2].first++;
            mp[2].second+=cn;
        }
    }

    const int INF = 1e17;
    int mn = INF;
    for (auto [x,y] : mp) {
        // cerr << "mp : " << x << ' ' << y << '\n';
        auto [a, b] = y;
        if (a == n) {
            mn = min (mn, b);
        }
    }

    cout << mn << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}