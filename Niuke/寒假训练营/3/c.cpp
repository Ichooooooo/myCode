#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int n;  cin >> n;
    string s;  cin >> s;

    int cn0 = 0, cn1 = 0, cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i ++) {
        if ((i & 1 != 0) && (s[i] != '0')) {
            if (cn0 > 0) {cn0 --; cn1 ++; }
            else { cn1 ++; }
        } else if ((i & 1 != 0)) {
            if (cnt1 > 0) {cnt1 --; cnt0 ++;}
            else cnt0 ++;
        } else if (s[i] != '1') {
            if (cn1 > 0) {cn1 --; cn0 ++;}
            else cn0 ++;
        } else {
            if (cnt0 > 0) {cnt0 --; cnt1 ++;}
            else cnt1 ++; 
        }
    }

    cout << min (cn0 + cn1, cnt0 + cnt1) << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}