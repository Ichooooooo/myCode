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
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    vector<int> b(10, 0);
    unordered_map<int,int> mp;
    for(int & i : a){
        cin >> i;
        b[i] ++;
        if(! mp[i]){
            mp[i] ++;
        }else{
            cnt ++;
            mp.clear();
            mp[i] ++;
        }
    }
    if(!mp.empty()){
        cnt ++;
    }
    cout << cnt << ' ' << n  << endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n=1;
	cin>>n;
	while(n--){
		solve();
	}
	return 0;
}