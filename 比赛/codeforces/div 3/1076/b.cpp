#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;  cin >> n;
    vector <PII> a (n + 1);
    vector <int>  b (n + 1);

    for (int i = 1; i <= n; i ++) {
        cin >> a[i].first; a[i].second = i;
        b[i] = a[i].first;
    }

    ranges :: sort (a | views :: drop(1));
    reverse (a.begin() + 1, a.end());

    int mx = n, pos;

    for (int i = 1; i <= n; i ++) {
        if (a[i].second == i) {
            continue;
        } else {
            reverse (b.begin() + i, b.begin() + a[i].second + 1);
            break;
        }
    }

    for (int i = 1; i <= n; i ++) {
        cout << b[i] << ' ';
    }
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        solve();
    }
    return 0;
}