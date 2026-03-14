#include<bits/stdc++.h>
#define int long long 
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
    vector<int> a(n);
    for(int & i : a){
        cin >> i;
    }
    sort(a.begin(), a.end());
    int p1 = a[0], p2 = -1;
    for(int i = 1; i < n; i ++){
        if(a[i] % p1 != 0 && p2 == -1){
            p2 = a[i];
        }else {
            if(a[i] % p1 != 0 && a[i] % p2 != 0){
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
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
