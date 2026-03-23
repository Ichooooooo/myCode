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
    vector<int> b;
    vector<int> c;
    int t, m = 0;
    for(int i = 0; i < n; i ++){
        cin >> t;
        if(t & 1){
            b.push_back(t);
        }else{
            c.push_back(t);
        }
    }
    // cout << "b : " << b.size() << endl;
    if(c.size() == 0){
        sort(b.rbegin(), b.rend());
        for(int i = 0; i < n; i ++){
            m = b[0];
            if(i & 1){
                cout << 0 << ' ';
            }else{
                cout << m << ' ';
            }
        }
    }else if(b.size() == 0) {
        for(int i = 0; i < n; i ++){
            cout << 0 << ' ';
        }
    }else {
        sort(b.rbegin(), b.rend());
        sort(c.rbegin(), c.rend());
        int mx = b[0], mn = c[c.size() - 1];
        cout << mx << ' ';
        for(int & i : c) {
            mx += i;
            cout << mx << ' ';
        }
        for(int i = 1; i < b.size(); i ++) {
            if(i & 1 && i + 1 < b.size()) {
                cout << mx - mn << ' ';
            }else if(i & 1) {
                cout << 0 << ' ';
            }else {
                cout << mx << ' ';
            }
        }
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
