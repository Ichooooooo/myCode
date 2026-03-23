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
    int n, m;
    cin >> n;
    vector<int> a; a.reserve(1LL << 16);
    m = (1LL << n) - 1;
    a.push_back(m);
    for(int i = n - 1; i >= 0; i --) {
        m ^= (1LL << i);
        for(int j = 0; j < (1LL << (n - 1 - i)); j ++) {
            a.push_back(m + (j << (i + 1)));
        }
    }
    for(int & i : a) cout << i << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}