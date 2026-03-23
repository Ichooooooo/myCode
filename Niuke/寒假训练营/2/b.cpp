#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int n; cin >> n;
    vector <int> a (n);map <int, int> mp;
    for (int & i : a)  {
        cin >> i;
        mp[i] ++;
    }

    int m = mp.size(), p = 0;
    vector <PII> cnt(m);
    for (auto [a, b] : mp) {
        // cout << p << ' ' << a << ' ' << b << endl;
        cnt[p].first = a;
        cnt[p].second = b;
        p ++;
    }

    int pos, ok = 0;
    if ((cnt[m - 1].second & 1) == 0) {
        ok = 1;
        // cout << "Ok";
    }
    // for (int i = m - 1; i >= 0; i--) {
    //     if (cnt[i].second & 1 == 0) {
    //         pos = cnt[i].first;
    //         break;
    //     }
    // }

    map <int, int> ans;
    for (int i = 0; i < m; i ++) {
        auto [a, b] = cnt[i];
        if (ok && i != (m - 1)) {
            mp[a] = 1;
        } else if (i == (m - 1) && !ok) {
            mp[a] = 1;
        } else {
            mp[a] = 0;
        }
    }

    for (int & i : a) cout << mp[i];
    cout << endl;
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