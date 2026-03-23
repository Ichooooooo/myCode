#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;
    cin >> n;
    vector<int> a(n);

    for (int & i : a) cin >> i;
    for (int i = 0; i < n - 2; i ++) {
        int t = max(a[i], a[i + 2]);
        if (a[i + 1] > t) {
            a[i + 1] = t;
        }
    }

    for(int & i : a) cout << i << ' ';
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