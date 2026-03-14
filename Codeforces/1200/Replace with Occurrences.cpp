#include<bits/stdc++.h>
#define int long long 
#define endl '\n' 
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
    vector<int> b(n);
    unordered_map<int, int> mp;
    vector<vector<int>> a(n + 1);
    for (int i = 0; i < n; i ++) {
        cin >> b[i];
        mp[b[i]] ++;
        a[b[i]].push_back(i);
    }
    for (auto &[x, y] : mp) {
        if (y % x) {
            cout << -1 << endl;
            return;
        }
    }
    int m = 1, p, cnt;
    for(int i = 1; i <= n; i ++){
        if(a[i].empty()) {
            continue;
        }else {
            cnt = i;
            for(int j = 0; j < a[i].size(); j ++){
                p = a[i][j];
                b[p] = m;
                if((j + 1) % cnt == 0) {
                    m ++;
                }
            }
        }
    }
    for(int i = 0; i < n; i ++) {
        cout << b[i] << ' ';
    }
    cout << endl;
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
