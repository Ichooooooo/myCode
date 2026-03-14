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
const int MAX = 2 * 1e7 + 10;

vector<bool> vis(MAX);
void setv() {
    for(int i = 1; i < 4472; i ++) {
        if (i * i > 2e7 + 2) break;
        for(int j = i; j < 4473; j ++) {
            if (i * i + j * j > 2e7 + 2) break;
            vis[i * i + j * j] = 1;
        }
    }
}

void solve(){   
    int q, x;
    cin >> q;
    setv();
    while(q --) {
        cin >> x;
        if(vis[x]) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n=1;
    // cin>>n;
    while(n--){
        solve();
    }
    return 0;
}
