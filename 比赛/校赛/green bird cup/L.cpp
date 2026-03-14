#include<bits/stdc++.h>
#define int long long 
#define endl '\n' 
#define INF 0x3f3f3f3f3f3f3f3f
#define pi acos(-1)
#define fi first 
#define se second 
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define si(x) (int)(x.size())
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod=998244353;
const double eps = 1e-10;

void solve(){   
    int n, a, b;
    cin >> n;
    vector<vector<int>> les(8, vector<int>(7, 0));
    while(n --){
        cin >> a >> b;
        les[a][b] = 1;
    }
    ll ans = 0;
    for(int c = 1; c <= 6; c ++){
        if(les[1][c]) {continue;}
        for(int d = 1; d <= 6; d ++){
            if(les[2][d] || d == c) {continue;}
            for(int e = 1; e <= 6; e ++){
                if(les[3][e] || e == d) {continue;}
                for(int f = 1; f <= 6; f ++){
                    if(les[4][f] || f == e) {continue;}
                    for(int g = 1; g <= 6; g ++){
                        if(les[5][g] || g == f) {continue;}
                        for(int h = 1; h <= 6; h ++){
                            if(les[6][h] || h == g) {continue;}
                            for(int i = 1; i <= 6; i ++){
                                if(les[7][i] || i == h) {continue;}
                                ans ++;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n=1;
    // cin>>n;
    while(n--){
        solve();
    }
    return 0;
}
