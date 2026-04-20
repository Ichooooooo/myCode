```cpp
void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> e(n + 1);
    vector<int> ru(n + 1, 0);

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        ru[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (ru[i] == 0) q.push(i);
    }

    vector<int> tpsort;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        tpsort.push_back(u);

        for (int v : e[u]) {
            ru[v]--;
            if (ru[v] == 0) q.push(v);
        }
    }

    if ((int)tpsort.size() != n) {
        cout << -1 << '\n'; // 有环
        return;
    }

    for (int x : tpsort) {
        cout << x << ' ';
    }
    cout << '\n';
}