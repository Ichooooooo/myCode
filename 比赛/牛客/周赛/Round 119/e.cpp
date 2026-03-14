#include<bits/stdc++.h>
#define int long long 
#define INF 0x3f3f3f3f3f3f3f3f
#define pi acos(-1)
#define fi first 
#define se second 
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod=998244353;
const double eps = 1e-10;

void solve(){   
    int n;
    cin >> n;
    vector<int> g;
    vector<int> d;
    ll a, b, mn, cnt = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a >> b;
        if(b >= 3) {
            cnt ++;
        }
    }
    sort(g.begin(), g.end());
    int pa, pb, pc;
    for(int i = 0; i < g.size() - 2; i ++){
        if(i > 0 && g[i] == pa) {
            continue;
        }else {
            pa = g[i];
        }
        for(int j = i + 1; j < g.size() - 1; j ++) {
            if(j > i + 1 && g[j] == pb) {
                continue;
            }else {
                pb = g[j];
            }
            if(lower_bound(g.begin(), g.end(), g[i] + g[j]) != g.end()){
                cnt += lower_bound(g.begin(), g.end(), g[i] + g[j]) - g.begin() - 1 - j;
            }else {
                cnt += g.size() - 1 - j;
            }
            cout << g[i] << ' ' << g[j] << ' ' << cnt << endl;
        }
    }
    cout << cnt << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n=1;
    cin>>n;
    while(n--){
        solve();
    }
    return 0;
}
