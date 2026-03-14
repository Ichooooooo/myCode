#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;

    if (n == m && a != b) {
        cout << "NO" << endl;
        return;
    } 

    int a1 = count(a.begin(), a.end(), '1'), b1 = n - a1;
    int a2 = count(b.begin(), b.end(), '1'), b2 = n - a2;

    int x1, y1;
    if ((a1 - a2) < 0 || (a1 - a2) % 2 != 0) {
        cout << "NO" <<  endl;
    } else {
        x1 = (a1 - a2) / 2;
        if (x1 + b1 < b2) {
            cout << "NO" << endl;
        } else {
            
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        solve();
    }
    return 0;
}