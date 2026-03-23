#include <bits/stdc++.h>
#define pi acos(-1)
#define fi first 
#define se second 
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;
const int MAX = 2e5 + 5;

void solve(){   
    int n;
    cin >> n;
    int x, p; char y;
    bool vis[MAX][4] = {0};
    vector<vector<int>> a(MAX);
    for (int i = 1; i <= n; i ++) {
        cin >> x >> y;
        p = y - 'A';
        if(vis[x][p]) continue;
        a[x].push_back(i);
        vis[x][p] = 1;
    }
    vector<int> ans;
    ans.reserve(MAX);
    for (int i = 1; i < MAX; i ++) {
        if(a[i].size() < 2) continue;
        ans.push_back(a[i][0]);
        ans.push_back(a[i][1]);
        if(a[i].size() < 4) continue;
        ans.push_back(a[i][2]);
        ans.push_back(a[i][3]);
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i += 2) {
        cout << ans[i] << ' ' << ans[i + 1] << endl;
    }
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
