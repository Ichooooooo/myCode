#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int n, m;  cin >> n >> m;
    vector <int> a (n);
    
    for (int & i : a) cin >> i;
    
    int ans = 0, r = 0;
    set <int> st;
    st.insert(-1e9); st.insert(2e9);
    for (int l = 0; l < n; l ++) {
        while (r < n) {
            auto it = st.lower_bound(a[r]);
            if (*it - a[r] < m) break;
            it --;
            if (a[r] - *it < m) break;
            st.insert(a[r]);
            r ++;
            
        }
        ans += (r - l);
        st.erase(a[l]);
    }
    cout << ans << "\n";
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