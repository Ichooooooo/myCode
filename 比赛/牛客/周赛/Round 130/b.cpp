#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int n; cin >> n;
    vector <PII> p;
    string s;
    int cnt = 0, x = 0;
    for (int i = 0; i < n; i ++) {
        cin >> s;
        if (s.find('*') == string :: npos) {
            continue;
        } else {
            int pos = s.find('*');
            int cn = 0;
            while (s[pos] == '*') {
                p.push_back({i, pos});
                pos ++; cn ++;
            }
            if (cn > cnt) {
                cnt = cn;
                x = i;
            }
        }
    }


    // cout << cnt << endl;
    if (cnt == 3) {
        int pp = 0, sum = 0;
        for (auto [a, b] : p) {
            if (a == x) {
                sum += b;
            } else {
                pp = b;
            }
        } 
        if (pp == sum / 3) {
            cout << 'T' << '\n';
        } else {
            cout << 'L' << '\n';
        }
    } else {
        int cn = 0;
        for (auto [a, b] : p) {
            if (a > x) cn ++;
        }
        // cout << x << ' ' << "cn : " << cn << endl;
        if (cn == 2 || cn == 0) {
            cout << 'L' << '\n';
        } else {
            cout << 'T' << '\n';
        }
    }
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