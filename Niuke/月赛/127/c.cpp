#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;
    cin >> n;
    if (n == 1 || n == 2) {
        cout << -1 << endl;
    } else {
        if (n & 1) {
            for (int i = 1; i <= (n + 1)/ 2; i ++) {
                cout << i << ' ';
            }
            for (int i = n / 2; i >= 1; i --) {
                cout << i << ' ';
            }
            cout << endl;
        } else {
            int yz = n / 2;
            if (yz & 1) {
                for (int j = 1; j <= 2; j ++) {
                    for (int i = 1; i <= (yz + 1)/ 2; i ++) {
                        cout << i << ' ';
                    }
                    for (int i = yz / 2; i >= 1; i --) {
                        cout << i << ' ';
                    }
                }
                cout << endl;
            } else {
                int a = yz + 1, b = yz - 1;
                if (a == 1 || b == 1) {
                    cout << -1 << endl;
                } else {
                    for (int i = 1; i <= (a + 1)/ 2; i ++) {
                        cout << i << ' ';
                    }
                    for (int i = a / 2; i >= 1; i --) {
                        cout << i << ' ';
                    }
                    for (int i = 1; i <= (b + 1)/ 2; i ++) {
                        cout << i << ' ';
                    }
                    for (int i = b / 2; i >= 1; i --) {
                        cout << i << ' ';
                    }
                }
            }
        }
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