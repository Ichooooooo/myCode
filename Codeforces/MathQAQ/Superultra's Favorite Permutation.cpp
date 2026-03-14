#include<bits/stdc++.h>
#define int long long 
#define endl '\n' 
#define INF 0x3f3f3f3f3f3f3f3f
#define pi acos(-1)
#define fi first 
#define se second 
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define si(x) (int)(x.size())
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod=998244353;
const double eps = 1e-10;

void solve(){   
    int n;
    cin >> n;
    if(n <= 4){
        cout << -1 << endl;
    }else{
        for(int i = 1; i <= n; i += 2){
            if(i == 5){
                continue;
            }
            cout << i << ' ';
        }
        cout << 5 << ' ' << 4 <<  ' ';
        for(int i = 2; i <= n; i += 2){
            if(i == 4){
                continue;
            }
            cout << i << ' ';
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
