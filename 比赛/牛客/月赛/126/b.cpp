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
    int n, m;
    cin >> n;
    bool vis[9] = {0};
    while(n --) {cin >> m; vis[m] = 1;}
    ll ans = 0, back, ok = 1;
    vector<int> a;
    for(int i = 1; i <= 8; i ++) {
        if(vis[i]) a.push_back(i);
    }
    back = a[a.size() - 1];
    for(int i = 0; i < a.size() - 1; i ++) {
        if((8 - back) + a[i] < (a[i + 1] - a[i]) && ok) {
            ans += (8 - back) + a[i];
            back = a[i];
            ok = 0;
        }else if(ok) {
            ans += a[i + 1] - a[i];
        }else {
            if(a[i + 1] - a[i] > (a[i] - back)) {
                ans += (a[i] - back);
                back = a[i];
            }else {
                ans += a[i + 1] - a[i];
            }
        }
        // cout << back << ' ' << ans << endl;
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