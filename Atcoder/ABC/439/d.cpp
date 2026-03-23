#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

int generate(vector<int> a) {
    map <int, int> mp;
    ll ans = 0;
    for (int i = 0; i < a.size(); i ++) {
        mp[a[i]] ++;
        if (a[i] % 5 != 0) continue;
        int x = a[i] / 5;
        int c1 = mp[x * 7], c2 = mp[x * 3];
        ans += c1 * c2; 
    }
    return ans;
}

void solve(){   
    int n;
    cin >> n;
    vector<int> a(n);                  
    for (int & i : a) cin >> i;      

    ll ans = 0;
    ans += generate(a);
    ranges :: reverse(a);
    ans += generate(a);
    cout << ans << endl;
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