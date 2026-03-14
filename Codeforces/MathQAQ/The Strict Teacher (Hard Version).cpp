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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(m);
    for(int & i : a){
        cin >> i;
    }
    sort(a.begin(), a.end());
    int x;
    while(q --){
        cin >> x;
        int p = lower_bound(a.begin(), a.end(), x) - a.begin();
        if(p == 0){
            cout << a[0] - 1 << endl;
        }else if(p > m - 1){
            cout << n - a[m - 1] << endl;
        }else {
            cout << (a[p] - a[p - 1]) / 2 << endl;
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
