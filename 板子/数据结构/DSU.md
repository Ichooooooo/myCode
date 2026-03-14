```cpp
class DSU {
    public: 
        vector <int> fa, rk, sz;
        DSU (int n = 0) {
            init(n); 
        }

        void init (int n) {
            fa.resize(n + 1);
            rk.assign(n + 1, 1);
            sz.assign(n + 1, 1);
            ranges::iota(fa, 0LL);
        }

        int find (int x) {
            return x == fa[x] ? x : (fa[x] = find(fa[x]));
        }

        bool merge (int i, int j) {
            int x = find(i), y = find(j);
            if (x == y) return false;
            if (rk[x] < rk[y]) swap(x, y);
            fa[y] = x;
            sz[x] += sz[y]; 
            if (rk[x] == rk[y]) rk[x]++;
            return true;
        }

        int size (int x) {
            return sz[find(x)];
        }
};
```

```cpp
class WDSU {
    public: 
        vector <int> fa, rk;
        vector <int> dist;
        WDSU (int n = 0) { init(n); }

        void init (int n) {
            fa.resize(n + 1);
            rk.assign(n + 1, 1);
            dist.assign(n + 1, 0);
            iota(fa.begin(), fa.end(), 0LL);
        }

        int find (int x) {
            if (fa[x] == x) return x;
            int t = fa[x];
            fa[x] = find(fa[x]);
            dist[x] += dist[t];
            return fa[x];
        }

        bool merge (int x, int y, int diff) {
            int rx = find(x), ry = find(y);
            if (rx == ry) return (dist[y] - dist[x] == diff);

            if (rk[rx] < rk[ry]) {
                fa[rx] = ry;
                dist[rx] = dist[y] - dist[x] - diff;
            }else {
                fa[ry] = rx;
                dist[ry] = dist[x] - dist[y] + diff;
                if (rk[rx] == rk[ry]) rk[rx]++;
            }
            return true;
        }

        bool same (int x, int y) { return (find(x) == find(y) ? 1 : 0); }

        int query (int x, int y) {
            return dist[y] - dist[x];
        };  
};
```