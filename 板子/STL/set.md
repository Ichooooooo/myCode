```cpp
struct Node {
    int x, y;
    int frc;

    bool operator<(const Node& it) const {
        return tie (frc, x, y) > tie (it.frc, it.x, it.y);
    }
};

set <Node> st;

st.insert({i, j, sum});

st.erase({xx, yy, b[xx][yy]});