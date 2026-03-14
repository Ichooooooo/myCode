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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int m = 0, x = 0;
    for(int i = 0; i < n; i ++){
        if(s[i] == '1'){
            m = 0;
        }else{
            m ++;
            if(m == k){
                cout << i << ' ';
                x ++;
                s[i] = '1';
                m = 0;
            }
            
        }
    }
    while(x <= n){
        cout << n << ' ';
        x ++;
    }
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
