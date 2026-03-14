#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, m;  cin >> n >> m;
    
    if (n == 0) {
		cout << m << endl;
		return;
	}
	
    vector <int> a (n + 1);
    
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    int cur = a[1], ans = a[1];
    for (int i = 2; i <= n; i ++) {
		if (a[i] > (cur + 100)) {
			ans += (a[i] - cur - 100);
			cur = a[i];
		} 
	}
		
//		cout << ans << ' ' << cur << endl;
	
	if (m > (cur + 100)) ans += (m - cur - 100);
	
	cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
//     cin>>_;

    while(_--){
        solve();
    }
    return 0;
}