#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int n; cin >> n;
    
    vector <vector <int>> a (n + 1, vector <int> (n + 1));
    if (n & 1) {
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= i; j ++) {
                if (i & 1) {
                    a[i][j] = 0; a[j][i] = 0;
                } else {
                    a[i][j] = 1; a[j][i] = 1;
                }
            }
        }
    } else {
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= i; j ++) {
                if (i & 1) {
                    a[i][j] = 1; a[j][i] = 1;
                } else {
                    a[i][j] = 0; a[j][i] = 0;
                }
            }
        }
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}