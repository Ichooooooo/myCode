#include<bits/stdc++.h>
#define int long long 
#define endl '\n' 
#define INF 0x3f3f3f3f3f3f3f3f
#define pi acos(-1)
#define fi first 
#define se second 
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod=998244353;
const double eps = 1e-10;

void solve(){   
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    stack<int> st;
    int an = n, t;
    for(int i = 1; i <= n; i ++){
        st.push(a[i]);
        while(st.top() == an){
            cout << st.top() << ' ';
            st.pop();
            an --;
        }
    }
    while(! st.empty()){
        cout << st.top() << ' ';
        st.pop();
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n=1;
    // cin>>n;
    while(n--){
        solve();
    }
    return 0;
}
