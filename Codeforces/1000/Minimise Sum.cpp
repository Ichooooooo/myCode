/* 
看题解写的, 可恶QAQ
思维题, 关键在通过表达式看出来其实最优只与前两个有关
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n; cin >> n;
    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];

    cout << a[1] + min (a[1], a[2]) << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        solve();
    }
    return 0;
}