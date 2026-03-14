#include<bits/stdc++.h> 
using namespace std;
#define int long long
#define double long double
using ll = long long;
const ll mod = 998244353;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
#define x first 
#define y second 

void solve(){
	ll q;
    cin >> q;
    unordered_map<int, int> mp;
    int p, a, b;
    int ps = 0;
    int t = 0;
    while(q --){
        cin >> p;
        if(ps == p && p == 3){
            continue;
        }else{
            ps = p;
        }
        if(p == 1){
            cin >> a >> b;
            mp[a] += b;
        }else if(p == 2){
            cin >> a >> b;
            if(mp[a] - b > 0){
                mp[a] -= b;
            }else{
                mp[a] = 0;
            }
        }else if(p == 3){
            for(auto & p : mp){
                if(p.y > 1)
                p.y = 1;
            }
        }else if(p == 4){
            cin >> a;
            t = mp[a];
            cout << t << endl;
        }
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