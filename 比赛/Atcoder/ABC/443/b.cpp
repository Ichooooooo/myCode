#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, m;  cin >> n >> m;
    int sum = 0, cur = n, cnt = 0;
    while (sum < m) {
		sum += cur;
		cur ++;
		cnt ++;
//		cout << sum << endl;
	}
	
	cout << cnt - 1 << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
//    cin>>_;

    while(_--){
        solve();
    }
    return 0;
}