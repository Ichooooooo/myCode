
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    string s;
    cin >> s;
    int n = s.size();
    if (s[0] == s[n - 1]) {
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