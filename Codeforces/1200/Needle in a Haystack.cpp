#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    string s, t;  cin >> s >> t;

    vector <int> cnt (26);
    for (char & i : t) {
        cnt[i - 'a'] ++;
    }

    queue <char> qu;
    for (char & j : s) {
        qu.push(j);
        cnt[j - 'a'] --;
        if (cnt[j - 'a'] < 0) {
            cout << "Impossible" << '\n';
            return;
        }
    }

    for (int i = 0; i < 26; i ++) {
        char t = i + 'a';
        if (t == qu.front()) {
            while (!qu.empty() && qu.front() <= t) {
                cout << qu.front();
                qu.pop();
            }
        }

        while (cnt[i] --) cout << t;
    }

    cout << '\n';
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