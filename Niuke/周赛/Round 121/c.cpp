#include<bits/stdc++.h>
#define int long long 
#define endl '\n' 
#define INF 0x3f3f3f3f3f3f3f3f
#define pi acos(-1)
#define fi first 
#define se second 
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod=998244353;
const double eps = 1e-10;

void solve(){   
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0, x = 1;
    unordered_map<char, int> mp;
    for(int i = 0; i < s.size(); i ++){
        mp[s[i]] ++;
    }
    for(char i = 'a'; i <= 'x'; i ++){
        if(! mp[i]) continue;
        for(char j = i + 1; j <= 'y'; j ++){
            if(!mp[j]) continue;
            for(char k = j + 1; k <= 'z'; k ++){
                if(!mp[k])  continue;
                x = ((mp[i] * mp[j]) % mod  * mp[k]) % mod * 6;
                x %= mod;
                ans += x;
            }
        }
    }
    cout << ans % mod << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n=1;
    // cin>>n;
    while(n--){
        solve();
    }
    return 0;
}
