#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;  cin >> n;
    vector <int> p (n + 1), id (n + 1), d (n + 1);
    map <int, int> mp;

    for (int i = 1; i <= n; i ++)  cin >> p[i];
    for (int i = 1; i <= n; i ++)  cin >> id[i];
    for (int i = 1; i <= n; i ++) {
        cin >> d[i];  mp[d[i]] = i;
    }
    set <int> st;
    for (int i = 1; i <= n; i ++) {
        
        int x = p[id[i]];
        while (st.find(x) == st.end()) {
            st.insert(x);
            x = p[mp[x]];
        }

        cout << st.size() << ' ';
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