#include<bits/stdc++.h> 
using namespace std;
#define int long long
#define double long double
using ll = long long;
const ll mod = 998244353;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

void solve(){
    int n;
    cin >> n;
    int a, b;
    vector<vector<int>> enm(n + 1);
    for(int i = 0; i < n - 1; i ++){
        cin >> a >> b;
        enm[a].push_back(b);
        enm[b].push_back(a);
    }
    vector<int> frd(n + 1, 0);
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j < enm[i].size(); j ++){
            int t = enm[i][j];
            frd[i] += enm[t].size();
        }
        frd[i] -= enm[i].size();
    }
    int p = max_element(frd.begin() + 1, frd.end()) - frd.begin();
    cout << p << " " << *max_element(frd.begin() + 1, frd.end()) << endl;
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