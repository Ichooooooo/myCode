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
    int n, m, cnt = 0;
    cin >> n >> m;
    vector<int> a(n), b(m);
    unordered_map<int, int> st;
    for(int & i : a){
        cin >> i;
        st[i] ++;
    }
    for(int & j : b) {
        cin >> j;
        if(st[j]) {
            cnt ++;
        }
    }
    // 客家话客家话
    // cout << "cnt : " << cnt << endl; 
    n -= cnt;  m-= cnt;
    if(n > m){
        cout << 2 * m + 2 << endl;
    }else {
        cout << 2 * n + 1 << endl;
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
