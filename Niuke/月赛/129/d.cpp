
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int m, c, q;
    cin >> m >> c >> q;

    vector <int> a (m);
    for (int & i : a) cin >> i;

    while (q --) { // 一定注意这里是在函数体内部的while语句, 用continue
        int x; cin >> x;

        if (x > c) { cout << "No\n"; continue; }
        if (x == c) { cout << "Yes\n"; continue; }

        vector <int> fir (m, -1); // 是否出现过
        vector <int> path, num;  // 记录路径和刚到达路径的值

        int pos = 0, nm = x, ok = 0;
        while (fir[nm % m] == -1) {
            fir[nm % m] = pos; pos ++;
            path.push_back(a[nm % m]);
            num.push_back(nm);
            nm += a[nm % m];

            if (nm == c) {ok = 1; break;}
            if (nm > c) {ok = 2; break;}
        }
        if (ok) {
            if (ok == 1)
            cout << "Yes" << '\n';
            else
            cout << "No" << '\n';
            continue;
        }

        int rep = nm % m, srt = fir[rep], end = pos - 1;
        int cir = 0;
        for (int i = srt; i <= end; i ++) cir += path[i];

        if (cir == 0) {
            cout << "No" << '\n';
            continue;
        }

        int okk = 0;
        for (int i = srt; i <= end; i ++) {
            if ((c - num[i]) % cir == 0) {
                okk = 1; break;
            }
        }

        if (okk) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        } 

        
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}