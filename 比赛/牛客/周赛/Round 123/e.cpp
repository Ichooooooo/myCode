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
    int n;cin >> n;
    vector<int> a(n);
    int vis[n + 1] = {0};
    // for(auto & i : vis) cout << i << ' ';
    for(int & i : a)cin >> i;
    int ans = 0, ok = 0;
    for (int i = 0; i < n; i ++) {
        vis[a[i]] ++;
        ans ++;
        if(a[i] < n && vis[a[i] + 1]) {
            ans--; vis[a[i] + 1] --; ok = 1;
        } 
        if(a[i] > 1 && vis[a[i] - 1]) {
            ans--; vis[a[i] - 1] --; ok = 1;
        }
        if(ok) vis[a[i]] --;
        cout << ans << ' ';
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n=1;
    // cin>>n;
    while(n--){
        solve();
    }
    return 0;
}
