
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int s, m; cin >> s >> m;

    auto check = [&](int mid) -> bool {
        int cnt = 0;
        for (int i = 0; i <= 60; i ++) {
            int d = (1LL << i);
            if (m & d) cnt += mid;
            if (s & d) {
                cnt --;
                if (cnt < 0) return false;
            }

            cnt >>= 1;
        }

        return true;
    };

    int l = 0, r = s;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check (mid))  r = mid - 1;
        else  l = mid + 1;
    }

    int ans = l;
    if (l > s) ans = -1;
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}