#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int n, m;  cin >> n >> m;
    vector <string> a (n);
    int cnt = 0;
    for (string & i : a) {
        cin >> i;
        cnt += count(i.begin(), i.end(), '1');
    }

    for (string & i : a) {
        for (char & j : i) {
            if (j == '1' && cnt == 1) cout << 'N';
            else if (j == '0' && cnt == (n * m - 1)) {
                cout << 'N';
            } else {
                cout << 'Y';
            }
        }
        cout << '\n';
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