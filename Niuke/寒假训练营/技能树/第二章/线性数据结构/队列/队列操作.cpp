#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n; cin >> n;

    int opt, x;
    queue <int> qe;
    while (n --) {
        cin >> opt;
        if (opt == 1) {
            cin >> x;
            qe.push(x);
        } else if (opt == 2) {
            if (qe.empty()) {
                cout << "ERR_CANNOT_POP" << endl;
            } else {
                qe.pop();
            }
        } else if (opt == 3) {
            if (qe.empty()) {
                cout << "ERR_CANNOT_QUERY" << endl;
            } else {
                cout << qe.front() << endl;
            } 
        } else {
            cout << qe.size() << endl;
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