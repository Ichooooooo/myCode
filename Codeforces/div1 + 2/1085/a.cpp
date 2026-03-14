
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n; cin >> n;
    string s; cin >> s;
    
    if (n < 3) {
        int cnt = ranges :: count (s, '1');
        cout << cnt << ' ' << cnt << '\n';
        return;
    }

    string t = s;
    for (int i = 1; i < n - 1; i ++) {
        if (t[i - 1] == '1' && t[i + 1] == '1') t[i] = '1';
    }
    
    int c1 = ranges :: count(t, '1');

    for (int i = 1; i < n - 1; i ++) {
        if (t[i - 1] == '1' && t[i + 1] == '1') t[i] = '0';
    }

    int c2 = ranges :: count(t, '1');

    cout << c2 << ' ' << c1 << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}