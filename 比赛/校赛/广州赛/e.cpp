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

bool isprimes(int a){
    if(a == 1 || a == 2)    return true;
    for(int i = 2; i * i <= a; i ++){
        if(a % i == 0)  return false;
    }
    return true;
}

void solve(){   
	int a, b;
    cin >> a >> b;
    string n, m;
    int a[4] = {0};
    for(int i = 0; i < 4; i ++){
        n += a % 10 + '0';
        m += b % 10 + '0'; 
        a /= 10;
        b /= 10;
    }
    reverse(n.begin(), n.end());
    reverse(m.begin(), m.end());
    
    for(int i = 0; i < 4; i ++){
        for(int j = 0; j < 4; j ++){
            
        }
    }
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