
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    string s; cin >> s;
    int n = s.size();
    int cnt = ranges :: count (s, '0');
    if (s.find('0') != string :: npos || (cnt != 0 && cnt != (n - 1) && s.find('5') != string :: npos) || (cnt == 0 && s.find('5') != string :: npos)) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}