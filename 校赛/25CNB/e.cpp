#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
#define pi acos(-1)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define si(x) (int)(x.size())
using ll = long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;
int ko = 1, koo = 0, kooo = 0, ok = 0;

bool check(string a, string c){
	if(a.size() == c.size()){
		return false;
	}
	if(a.size() > c.size()){
		swap(a, c);
	}
	string b;
	for(int i = 0; i < c.size(); i ++){
		if(c[i] != '0'){
			b = c.substr(i, c.size());
			break;
		}
	}
	if(a.size() == b.size()){
		koo = 1;
		for(int i = 0; i < a.size(); i ++){
			if(a[i] != b[i]){
				ko = 0;
			}
		}
		if(koo && ko){
			return true;
		}
	}
	b = c;
	for(int i = 0; i < a.size(); i ++){
		if(a[i] > b[i]){
			return true;
		}else if(a[i] < b[i]){
			return false;
		}else {
			continue;
		}
	}
	return true;
}

void solve(){
	string a, b;
	cin >> a >> b;
	int ok1 = 0, ok2 = 0, pos1, pos2;
	if((pos1 = a.find(".")) == string :: npos){
		ok1 = 1;
	}
	if((pos2 = b.find(".")) == string :: npos){
		ok2 = 1;
	}
	if(ok1 || ok2){
		cout << "ni shi dui de"	<< endl;
		return;
	}
	string ma = a.substr(pos1 + 1, a.size());
	string mb = b.substr(pos2 + 1, b.size());
	string na = a.substr(0, pos1);
	string nb = b.substr(0, pos2); 
//	cout << ma << " " << mb << " " << na << " " << nb << endl;
	if(na == nb && check(ma, mb)){
		if(ko && koo){
			cout << "ni cuo le, ying gai shi =" << endl;
			return;
		}
		if(ma.size() > mb.size()){
			cout << "ni cuo le, ying gai shi >" << endl;
		}else{
			cout << "ni cuo le, ying gai shi <" << endl;
		}
	}else{
		cout << "ni shi dui de" << endl;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int _ = 1;
//	cin >> _;
	while(_ --){
		solve();
	}
	return 0;
}