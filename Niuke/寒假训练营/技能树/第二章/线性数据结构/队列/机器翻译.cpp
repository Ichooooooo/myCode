#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;
const int N = 1000;

void solve(){   
    int m, n, t;  cin >> m >> n;

    int cnt = 0;
    queue <int> qe; vector <int> vis (N);
    while (n --) {
        cin >> t;
        if (! vis[t]) {
            cnt ++;
            if (qe.size() < m) {
                qe.push(t); vis[t] = 1;
            } else {
                vis[qe.front()] = 0; qe.pop();
                qe.push(t); vis[t] = 1;
            }
        }
    }

    cout << cnt << endl;
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