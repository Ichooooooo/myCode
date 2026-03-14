#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;  cin >> n;
    string s; int x; stack <int> st; 
    
    while (n --) {
        cin >> s;
        if (s == "push") {
            cin >> x;
            st.push(x);
        } else if (s == "pop") {
            if (st.empty()) {
                cout << "Empty" << endl;
            } else {
                st.pop();
            }
        } else if (s == "query") {
            if (st.empty()) {
                cout << "Empty" << endl;
            } else {
                cout << st.top() << endl;
            }
        } else {
            cout << st.size() << endl;
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