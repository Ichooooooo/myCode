
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n; cin >> n;
    vector <int> a (n);
    for (int & i : a) cin >> i;

    ranges :: sort (a);
    
    int cnt = 1;
    for (int i = 1; i < n; i ++) {
        if (a[i] == a[i - 1] + 1) continue;
        else cnt ++;
    }

    cout << cnt << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}