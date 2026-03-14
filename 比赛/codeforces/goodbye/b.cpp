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
    string s;
    cin >> s;
    int cnt = 0, n = s.size();
    if(s[0] == 'u') {
        cnt ++;
        s[0] = 's';
    }
    if(s[n - 1] == 'u') {
        cnt ++;
        s[n - 1] = 's';
    }
    if(s.find('u') == string::npos) {
        cout << cnt << endl;
        return;
    }
    for(int i = 1; i < n - 1; i ++) {
        if(s[i] == 'u') {
            if(s[i - 1] != 's') {
                cnt ++;
                s[i - 1] = 's';
            }
            if(s[i + 1] != 's') {
                cnt ++;
                s[i + 1] = 's';
            }
        } 
    }
    cout << cnt << endl;
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