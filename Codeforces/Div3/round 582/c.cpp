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

vector<vector<ll>> a(10, vector<ll>(11));
void seta() {
    for (int i = 0; i < 10; i ++) {
        a[i][0] = 0;
        for (int j = 1; j <= 10; j ++) {
            a[i][j] = a[i][j - 1] + (j * i) % 10;
        }
    }
}

void solve(){   
    int q; ll n, m, cnt, ans;
    cin >> q;
    seta();
    while (q --) {
        cin >> n >> m;
        // cnt = (n / m / 10) + (n / m % 10);
        // cout << n / m / 10 << ' ' << a[m % 10][10] << ' ' <<  a[m % 10][n / m % 10] << endl;
        cout << (n / m / 10) * a[m % 10][10] + a[m % 10][n / m % 10] << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}