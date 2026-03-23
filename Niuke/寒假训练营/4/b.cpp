#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int n, q, s;
    cin >> n >> q >> s;
    vector <int> t (n + 1), pre (n + 1);
    pre[0] = s - 1;
    for (int i = 1; i <= n; i ++) {
        cin >> t[i];
        pre[i] = pre[i - 1] + t[i];
    }

    int x, y;
    while (q --) {
        cin >> x >> y;
        cout << pre[x - 1] + y << '\n'; 
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}