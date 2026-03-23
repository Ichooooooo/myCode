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
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    vector<vector<int>> cha(n + 1, vector<int>(26));
    vector<vector<int>> chb(n + 1, vector<int>(26));
    for(int i = 0; i < n; i ++){
        cha[i + 1][a[i] - 'a']++;
        chb[i + 1][b[i] - 'a']++;
        for(int j = 0; j < 26; j ++) {
            cha[i + 1][j] += cha[i][j];
            chb[i + 1][j] += chb[i][j];
        }
    }
    ll l, r, t = 0;
    while(q --) {
        cin >> l >> r;
        for(int j = 0; j < 26; j ++) {
            t += abs(cha[r][j] - cha[l - 1][j] - (chb[r][j] - chb[l - 1][j]));
        }
        cout << t / 2 << endl;
        t = 0;
    }
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
