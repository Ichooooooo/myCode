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
    int n, m, q;
    cin >> n >> m >> q;
    int b[2], x;
    cin >> b[0] >> b[1];
    sort(b, b + 1);
    cin >> x;
    if(x > b[1]){
        cout << n - b[1] << endl;
    }else if(x < b[0]){
        cout << b[0] - 1 << endl;
    }else {
        // cout << (long long)(b[0] + b[1]) / 2  - b[0] << endl;
        cout << (b[1] - b[0]) / 2 << endl;
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
