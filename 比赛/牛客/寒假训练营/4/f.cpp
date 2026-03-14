#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int a, b;
    cin >> a >> b;
    if (a == 0) {
        while (b --) cout << 1;
    } else if (b == 0) {
        while (a --) cout << 0;
    } else if (a > b) {
        int bl = a / (b + 1);
        vector <int> ans (b + 1, bl);
        int res = a % (b + 1);
        for (int i = 0; i < res; i ++) ans[i] ++;

        for (int i = 0; i < b + 1; i ++) {
            for (int j = 0; j < ans[i]; j ++) {
                cout << 0;
            }
            if (i != b) cout << 1;
        }
    } else {
        swap (a, b);
        int bl = a / (b + 1);
        vector <int> ans (b + 1, bl);
        int res = a % (b + 1);
        for (int i = 0; i < res; i ++) ans[i] ++;

        for (int i = 0; i < b + 1; i ++) {
            for (int j = 0; j < ans[i]; j ++) {
                cout << 1;
            }
            if (i != b) cout << 0;
        }
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