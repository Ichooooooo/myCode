#include<bits/stdc++.h> 
using namespace std;
#define int long long
#define double long double
using ll = long long;
const ll mod = 998244353;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

const ll lim = 1e9;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> b;
    unordered_set<int> st;
    int ok = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
         st.insert(a[i]);
        if(a[i] != 1){
            b.push_back(a[i]);
        }else{
            ok = 1;
        }
       
    }
    // for(int & i : b) cout << i << " ";
    
    for(int i = 0; i < b.size(); i ++){
        ll x = b[i];
        for(int j = i + 1; j < b.size(); j ++){
            x *= b[j];
            // cout << "x: " <<  x << " ";
            if(x > lim){
                break;
            }
            st.insert(x);
        }
    }
    ll x;
    while(q --){
        cin >> x;
        if (st.count(x)) {
            cout << "Yes" << '\n';
        }else {
            cout << "No" << '\n';
        }
        // cout << (st.count(x) || (x == 1 && ok ) ? "YES" : "NO") << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int _=1;
	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}