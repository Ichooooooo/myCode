
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, a, b; cin >> n >> a >> b;
    int all = 0; int t;
    while (n --) {
        cin >> t;
        all += t;
    }

    int to = (b - a) * 60;
    if (all <= to) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}