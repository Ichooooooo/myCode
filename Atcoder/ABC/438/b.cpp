#include<bits/stdc++.h>
#define pi acos(-1)
#define fi first 
#define se second 
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

int check(string a, string b) {
    int an = 0;
    for (int i = 0; i < a.size(); i ++) {
        if (a[i] >= b[i]) {
            an += (a[i] - b[i]);
        } else {
            an += (10 - (b[i] - '0')) + (a[i] - '0');
        }
        // cout << a[i] << ' ' << an << endl;
    }
    return an;
}

void solve(){   
    int n, m;
    string s, t;
    cin >> n >> m;
    cin >> s >> t;

    auto check = [&] (string a, string b) -> int {
        int an = 0;
        for (int i = 0; i < a.size(); i ++) {
            if (a[i] >= b[i]) {
                an += (a[i] - b[i]);
            } else {
                an += (10 - (b[i] - '0')) + (a[i] - '0');
            }
            // cout << a[i] << ' ' << an << endl;
        }
        return an;
    };

    if (s.find(t) != string::npos) {
        cout << 0 << endl;
    } else {
        int cn, cnt = 1e7;
        for (int i = 0; i < n - m + 1; i ++) {
            string ss = s.substr(i, m);
            cn = check(ss, t);
            // cout << ss << ' ' << cnt << ' ' <<  cn << endl;
            cnt = min(cnt, cn);
        }
        cout << cnt << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}