#include<bits/stdc++.h>
#define pi acos(-1)
#define fi first 
#define se second 
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){    
    int n, m = 0;
    cin >> n;
    vector<int> v(n);
    for (int & i : v) cin >> i;

    vector<int> f; f.reserve(n);
    int ans = n;
    for (int i = 0; i < n; i ++) {
        f.push_back(v[i]);
        m = f.size();
        if (m >= 4 && f[m] == f[m - 1] && f[m - 1] == f[m - 2] && f[m - 2] == f[m - 3]) {
            f.pop_back(); f.pop_back(); f.pop_back(); f.pop_back();
            ans -= 4;
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        solve();
    }
    return 0;
}