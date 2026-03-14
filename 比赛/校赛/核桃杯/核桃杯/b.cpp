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
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, m, k;
    cin >> n >> m >> k;
    if((n - 1) / 2 * ((m - 1) / 2) < k) {
        cout << "No" << '\n';
    }else {
        cout << "Yes" << endl;
        int t = 1;
        if(k == 0) {
            for(int i = 1; i <= n; i ++) {
                for(int j = 1; j <= m; j ++) {
                    cout << t << ' ';
                    t ++;
                }
                cout << endl;
            }
        } else {
            int r = 2, c = 2, cn = 0, ok = 0;
            t = n * m;
            int arr[n + 1][m + 1] = {0};
            for(int i = r; i < n; i += 2) {
                for(int j = c; j < m; j += 2) {
                    arr[i][j] = t;
                    t --;
                    cn ++;
                    if(cn == k) {
                        ok = 1;
                        break;
                    }
                }
                if(ok) {
                    break;
                }
            }
            t = 1;
            for(int i = 1; i <= n; i ++) {
                for(int j = 1; j <= m; j ++) {
                    if(!arr[i][j]){
                        arr[i][j] = t;
                        t ++;
                    }
                }
            }
           for(int i = 1; i <= n; i ++) {
                for(int j = 1; j <= m; j ++) {
                    cout << arr[i][j] << ' ';
                }
                cout << endl;
            }
        }
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
