#include<bits/stdc++.h> 
using namespace std;
#define int long long
#define double long double
using ll = long long;
const ll mod = 998244353;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int MAX = 1e4;

ll gcd(int n, int m){
	if (n < m){
		swap(n , m);
	}
	while (n % m){
		int t = n;
		n = m;
		m = t % m;
	}
	return m;
}

void solve(){
	int n, m;
	cin >> n >> m;
	string s1, s2;
	cin >> s1 >> s2;
	vector<int> r(MAX);
	int len = n * m / gcd(n, m);
	string sn, sm;
	for(int i = 0; i < len / n; i ++){
		sn += s1;
	}
	for(int i = 0; i < len / m; i ++){
		sm += s2;
	}
	int carry = 0;
	for(int i = len - 1; i >= 0; i --){
		int a = sn[i] - '0' + carry;
		int b = sm[i] - '0';
		if(a < b){
			carry = -1;
			r[i] = (a + 10 - b);
		}else{
			carry = 0;
			r[i] = (a - b);
		}
	}
	if(carry == -1 && r[0] > 0){
		r[0] --;
		cout << len << endl;
		for(int i = 0; i < len; i ++){
			cout << r[i];
		}
		cout << endl;
	}else if(carry == 0){
		cout << len << endl;
		for(int i = 0; i < len; i ++){
			cout << r[i];
		}
		cout << endl;
	}else{
		carry = -1;
		for(int i = len - 1; i >= 0; i ){
			int a = sn[i] - '0' + carry;
			int b = sm[i] - '0';
			if(a < b){
				carry = -1;
				r[i] = a + 10 - b;
			}else{
				carry = 0;
				r[i] = a - b;
			}
		}
		cout << len << endl;
		for(int i = 0; i < len; i ++){
			cout << r[i];
		}
		cout << endl;
	}
}
signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int _=1;
	// cin>>_;
	while(_--){
		solve();
	}
	return 0;
}