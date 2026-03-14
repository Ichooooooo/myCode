#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n; cin >> n;
    string s; cin >> s;
    
    vector<int> a(n + 1), b(n + 1);
    for (int i = 0; i < n; i ++) {
        a[i + 1] = a[i]; b[i + 1] = b[i];
        if (s[i] == 'A') a[i + 1] ++;
        else if (s[i] == 'B') b[i + 1] ++;
    }

    vector <int> cnt (2 * n + 1);
    int pre = 0, ans = 0;

    
    for (int i = 1; i <= n; i ++) {

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