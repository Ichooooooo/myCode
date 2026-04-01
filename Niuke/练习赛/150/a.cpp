
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    vector <int> a (n);
    multiset <int, greater <int> > sta, stb;

    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        if (a[i] & 1) sta.insert (a[i]);
        else stb.insert (a[i]);
    }

    int nowa = 0, nowb = 0;
    if (!sta.empty()) nowa = *sta.begin();
    if (!stb.empty()) nowb = *stb.begin();

    cout << max (nowa, nowb) << ' ';
    for (int i = 1; i <= n - 1; i++) {
        if (stb.empty()) nowa = 0;
        else {
            auto itb = stb.begin();
            nowa += *itb;
            stb.erase(itb);

            // cerr << *itb << '\n';
        }

        if (sta.empty()) nowb = 0;
        else {
            auto ita = sta.begin();
            nowb += *ita;
            sta.erase(ita);
            //  cerr << *ita << '\n';
        }

        cout << max (nowa, nowb) << ' ';
    }

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}