#include<bits/stdc++.h>
#define int long long 
// #define endl '\n' 
#define INF 0x3f3f3f3f3f3f3f3f
#define pi acos(-1)
#define fi first 
#define se second 
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod=998244353;
const double eps = 1e-10;

void solve(int n){   
    if(n != 0){
        vector<int> a(n + 1);
        stack<int> st;
        for(int i = 1; i <= n; i ++){
            cin >> a[i];
        }
        int p = 1;
        for(int i = 1; i <= n; i ++){
            st.push(i);
            while(!st.empty() && st.top() == a[p]){
                st.pop();
                p ++;
            }
        }
        if(st.empty()){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n=1;
    // cin>>n;
    while(cin >> n){
        if(n == 0){
            cout << endl << endl;
        }else{
            solve(n);
        }
    }
    return 0;
}
