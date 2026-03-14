#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    string s;
    cin >> s;
    int cnt = 0;
    for (char & i : s) {
        if (i == 'i' || i == 'j') {
            cnt ++;
        }
    }

    cout << cnt <<endl;
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