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
    int t;
    for(int i = 0; i < n - 2; i ++){
        if(a[i] < 0){
            cout << "No" << endl;
            return;
        }else if(a[i] == 0){
            continue;
        }else {
            t = a[i];
            a[i] -= t;
            a[i + 1] -= 2 * t;
            a[i + 2] -= t;
        }
    }
    if(a[n - 1] == 0 && a[n - 2] == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
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
