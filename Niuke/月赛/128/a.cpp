#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;  cin >> n;
    string s1, s2;  cin >> s1 >> s2;

    auto jug = [](char a, char b) -> bool {
        if (a == b) return true;
        else if ((a == 'O' && b == '0') || (a == '0' && b == 'O')) return true;
        else if ((a == 'I' || (a == '1' || a == 'l')) && (b == 'I' || (b == '1' || b == 'l'))) return true;
        else return false;
    };

    for (int i = 0; i < n; i ++) {
        if (!jug(s1[i], s2[i])) {
            // cout << i << endl;
            cout << "NO" << endl;
            return;
        } 
    }
    cout << "YES" << endl;
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