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
    int n; ll x, y, xx = 0, yy = 0, sum = 0;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    int cnt = count(s.begin(), s.end(), '0');
    vector<int> p(n);
    for(int & i : p) {cin >> i; sum += i;}
    if(sum > (x + y)) {
        // cout << 1 << endl;
        cout << "No" << endl; return;
    }
    for(int i = 0; i < n; i ++) {
        if(s[i] == '0') {
            xx += (p[i] / 2 + 1);
        }else {
            yy += (p[i] / 2 + 1);
        }
        if(x < xx || y < yy) {
            // cout << 2 << endl;
            cout << "No" << endl;
            return;
        }
    }
    if(cnt == n) {
        // cout << 3 << endl;
        if(x >= xx && x >= y + n) {
            cout << "Yes" << endl;
        }else { 
            cout << "No" << endl; 
        }
    }else if(cnt == 0){
        if(y >= yy && y >= x + n) {
            cout << "Yes" << endl;
        }else {
            cout << "No" << endl;
        }
    }else {
        cout << "Yes" << endl;
    }

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