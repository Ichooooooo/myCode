
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n;
    cin >> n;
    vector <int> a (n);
    for (int & i : a) cin >> i;
    int mx = ranges :: max (a);
    int cnt = ranges :: count (a, mx);

    cout << cnt << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}