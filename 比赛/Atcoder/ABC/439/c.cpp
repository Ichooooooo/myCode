#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;
const int MAX = 1e7;

void solve(){   
    ll n;
    cin >> n;
    vector<int> cnt(n + 1, 0);
    vector<int> a; a.reserve(MAX);
    for (int i = 1; i * i <= n; i ++) {
        a.push_back(i * i);
    }

    for (int i = 0; i < a.size() - 1; i ++) {
        for (int j = i + 1; j < a.size(); j ++) {
            ll s = a[i] + a[j];
            if (s <= n) cnt[s]++;
            else break;
        }
    }

    ll cn = count(cnt.begin(), cnt.begin() + n + 1, 1);
    cout << cn << endl;
    for (int i = 1; i <= n; i ++) {
        if (cnt[i] == 1) {
            cout << i << ' ';
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}