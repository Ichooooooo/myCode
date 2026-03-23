#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int q;  cin >> q;

    int opt, x; deque <int> dq;
    while (q --) {
        cin >> opt;
        if (opt == 1) {
            cin >> x;
            dq.push_front(x);
        } else if (opt == 2) {
            cin >> x;
            dq.push_back(x);
        } else if (opt == 3) {
            cout << dq.front() << endl;
            dq.pop_front();
        } else {
            cout << dq.back() << endl;
            dq.pop_back();
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