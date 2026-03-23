
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n; cin >> n;
    vector <string> ss(n);
    vector <int> len(n);
    for (int i = 0; i < n; i ++) {
        cin >> ss[i];
        len[i] = ss[i].size();
    }

    int mx = ranges :: max (len);
    for (int i = 0; i < n; i ++) {
        int t = mx - len[i];
        for (int j = 0; j < t / 2; j ++) cout << '.';
        cout << ss[i];
        for (int j = 0; j < t / 2; j ++) cout << '.';
        cout << '\n';
    }
    
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}