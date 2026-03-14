#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

const int N = 2 * 1e5;

void ovo(){   
    int n;  cin >> n;
    vector <int> a (n);
    for (int & i : a)  {
        cin >> i;
    }

    int mx = ranges :: max (a);
    vector <int> cf (mx + 5);
    for (int & i : a) {cf[1] ++; cf[i + 1] --;}

    vector <int> pre (mx + 10);
    for (int i = 1; i <= mx; i ++) {
        pre[i] = pre[i - 1] + cf[i]; 
    }

    for (int i = 1; i <= mx; i ++) {
        if (pre[i] >= 10) {
            int t = pre[i];
            pre[i] %= 10;
            pre[i + 1] += t / 10;
        }
    }

    int r = mx;
    if (pre[r + 1] != 0) {
        r ++;
        while (pre[r] >= 10) {
            int t = pre[r];
            pre[r] = t % 10;
            pre[r + 1] = t / 10;
            r ++;
        }
    }
    
    reverse(pre.begin() + 1, pre.begin() + r + 1);

    for (int i = 1; i <= r; i ++) {
        cout << pre[i];
    }

    cout << '\n';
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