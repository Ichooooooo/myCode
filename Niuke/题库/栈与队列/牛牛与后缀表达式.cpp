#include<bits/stdc++.h>
#define int long long 
#define endl '\n' 
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

void solve(){   
    string s, t;
    cin >> s;
    stack<int> st;
    int a, b, x = 0;
    for(int i = 0; i < s.size() - 1; i ++){
        if(s[i] >= '0' && s[i] <= '9'){
            x = x * 10 + (s[i] - '0');
        }else if(s[i] == '+'){
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(a + b);
        }else if(s[i] == '-'){
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b - a);
        }else if(s[i] == '*'){
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b * a);
        }else if(s[i] == '.') {
            st.push(x);
            x = 0;
        }else if(s[i] == '/'){
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b / a);
        
        }
    }
     cout << st.top() << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n=1;
    // cin>>n;
    while(n--){
        solve();
    }
    return 0;
}
