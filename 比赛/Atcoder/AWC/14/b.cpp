
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, v;  cin >> n >> v;
    vector <int> d (n + 1), pre(n + 1);
    for (int i = 1; i < n; i ++) {
        cin >> d[i];
        pre[i + 1] = d[i] + pre[i];
    }

    vector <int> t (n + 1); 
    int cnt = 0;
    for (int i = 2; i <= n; i ++) {
        cin >> t[i];
        double tm = pre[i] / v;
        if (t[i] > tm) {
            cnt ++;
            cout << i << ' ';
        }
    }
    if (cnt == 0) {
        cout << -1 << '\n';
    } else {
        cout << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}