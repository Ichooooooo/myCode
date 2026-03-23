#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    string s; cin >> s;
    int n = s.size();
    int pos = -1;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '0') pos ++;
        else break;
    }

    if (pos == -1) {
        cout << s << '\n';
    } else {
        s = s.substr(pos + 1);
        cout << s << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}