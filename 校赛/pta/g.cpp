#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;
    cin >> n;
    string s;
    cin >> s;

    int t;
    while (n --) {
        cin >> t;
        if (t == 1) {
            string a;
            cin >> a;
            if (s.find(a) != string :: npos) {
                cout << (int)(s.find(a)) << endl;
            } else {
                cout << -1 << endl;
            }
        } else if(t == 2) {
            string a, b;
            cin >> a >> b;
            cout << s << endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}