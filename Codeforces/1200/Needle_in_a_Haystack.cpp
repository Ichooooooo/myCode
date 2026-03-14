#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    string x, y;  cin >> x >> y;

    queue <char> qu;
    vector <int> a(26);
    for (char & j : x) a[j - 'a'] ++;
    for (char & i : y) {
        qu.push(i);
        a[i - 'a'] --;
        if (a[i - 'a'] < 0) {
            cout << "Impossible" << endl;
        }
    }
    
    for (int i = 0; i < 26; i ++) {
        char t = i + 'a';
        while (!qu.empty() && qu.front() <= t) {
            cout << qu.front();
            qu.pop();
        }
        int cn = a[i];
        while (cn --) cout << t;
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
