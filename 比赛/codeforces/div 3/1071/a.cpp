#include<bits/stdc++.h>
#define pi acos(-1)
#define fi first 
#define se second 
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;
    cin >> n;
    vector<int> a(n);
    for(int & i : a)cin >> i;
    vector<int> b(n, 0);
    for(int i = 1; i < n; i ++) {
        b[i] = a[i] - a[i - 1];
    }
    ll sum = 0, ok = 0, mxi = -1, mxz;
    for(int i = 1; i < n; i ++) {
        if (i + 1 < n && b[i] * b[i + 1] < 0) {
            if(mxi == -1) {
                mxz = abs(b[i]) + abs(b[i + 1]);
                mxi = i;    
            }else {
                if((abs(b[i]) + abs(b[i + 1])) > mxz) {
                    mxz = abs(b[i]) + abs(b[i + 1]);
                    mxi = i;
                }
            }
        }
        sum += abs(b[i]);
    }
    if(mxi == -1) {
        if(abs(b[1]) > abs(b[n])) {
            sum -= abs(b[1]);
        }else {
            sum -= abs(b[n - 1]);
        }
    }else {
        sum -= (abs(b[mxi]) + abs(b[mxi + 1]));
        sum += abs(b[mxi] + b[mxi + 1]);
    }
    cout << sum << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n=1;
    cin>>n;
    while(n--){
        solve();
    }
    return 0;
}
