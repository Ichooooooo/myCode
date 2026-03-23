
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo() {   
    int h, w;
    cin >> h >> w;
    vector <string> a (h);
    for (string & i : a) cin >> i;

    string s;
    vector <vector <int>> visr (h, vector <int> (26));
    vector <vector <int>> visc (w, vector <int> (26));
    for (int i = 0; i < h; i ++) {
        for (int j = 0; j < w; j ++) {
            int x = a[i][j] - 'a';
            visr[i][x]++;
            visc[j][x]++;
        }
    }

    for (int i = 0; i < h; i ++) {
        for (int j = 0; j < w; j ++) {
            int x = a[i][j] - 'a';
            if (visr[i][x] == 1 && visc[j][x] == 1) {
                s += a[i][j];
            }
        }
    }

    cout << s << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}