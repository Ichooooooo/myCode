
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n; cin >> n;
    string s; cin >> s;
    
    int cnt = ranges :: count (s, '1'), cn = n - cnt;
    if (cnt == 0) {
        cout << 0 << '\n';
    } else if (cnt == n - 1) {
        int pos = s.find('0');
        cout << 1 << ' ' << pos << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}