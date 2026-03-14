#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;  cin >> n;
    vector <int> a (n + 1);

    for (int i = 1; i <= n; i ++)  cin >> a[i];

    __int128 answ = 0;
    for (int i = 0; i < 30; i ++) {
        int sumb = 0, cn1 = 0, cn0 = 1, cur = 0, b = 0;
        for (int j = 1; j <= n; j ++) {
            b =  (a[j] >> i) & 1LL;
            sumb += b;
            cur ^= b;
            if (cur == 1) cn1 ++;
            else cn0 ++;
        }

        __int128 bitAns = (__int128)cn0 * cn1 - sumb;
        answ += bitAns * ((__int128)1 << i);
    }

    // long long out = (long long)answ;
    cout << out << "\n";
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