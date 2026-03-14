
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, r, t;
    cin >> n >> r >> t;

    vector <int> p (n);
    for (int i = 0; i < n; i ++) {
        int wt; cin >> wt;
        int an = min (t / wt, r);
        cout << an << " \n"[i == n - 1];
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}