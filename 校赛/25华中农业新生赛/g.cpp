#include<bits/stdc++.h>
#define int long long 
#define endl '\n' 
#define double long double
#define pi acos(-1)
#define x first 
#define y second 
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
typedef long long ll;
const int N=2e5+10;
const int M=2*N;
const int mod=998244353;
const int mod1 = 1e9 + 7 ;
const int mod2 = 1e9 + 9 ; 
const double eps = 1e-10;

void solve(){   
    int m ,n;
    cin >> m >> n;
    vector<int> a(m);
    vector<int> al(m, 0);
    int t = 0;
    for(int i = 0; i < m; i ++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < m; i ++){
        if(i == 0){
            al[i] = 0;
            continue;
        }
        al[i] = al[i - 1] + a[i];
    }
    // cout << "al : ";
    // for(int & i : al){
    //     cout << i << " ";
    // }cout << endl;
    vector<int> x(n);
    vector<int> y(n);
    for(int & i : x)    cin >> i;
    for(int & i : y)    cin >> i;
    int b, c;
    ll ans = 0;
    for(int i = 0; i < n; i ++){
        b = x[i];
        c = y[i];
        if(c > m){
            // cout << "m : " << m << "c : " << c << endl;
            cout << "No" << endl;
            return;
        }
        int p = b + 1 - c;
        ans += (p) * a[0];
        ans += al[c - 1];
    }
    int z;
    cin >> z;
    cout << ans << endl;
    if(z >= ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
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