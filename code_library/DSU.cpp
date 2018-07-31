// Basic DSU with compression

struct DSU {
    vector<int>u_list, u_set;        // u_list[x] : the size of a set x,  u_set[x] : the root of x
    DSU() {}
    DSU(int SZ) { init(SZ); }
    int unionRoot(int n) {                          // Union making with dynamic compression
        if(u_set[n] == n) return n;
        return u_set[n] = unionRoot(u_set[n]);      // Directly set the actual root of this set as root (Compress)
    }
    int makeUnion(int a, int b) {                   // Union making with compression
        int x = unionRoot(a), y = unionRoot(b);
        if(x == y) return x;                        // If both are in same set
        else if(u_list[x] > u_list[y]) {            // Makes x root (y -> x)
            u_set[y] = x;
            u_list[x] += u_list[y];                 // Root's size is increased
            return x;
        }
        else {                                      // Makes y root (x -> y)
            u_set[x] = y;
            u_list[y] += u_list[x];                 // Root's size is increased
            return y;
    }}
    void init(int len) {                            // Initializer
        u_list.resize(len+5);
        u_set.resize(len+5);
        for(int i = 0; i <= len+3; i++)
            u_set[i] = i, u_list[i] = 1;            // Each node contains itself, so size of each node set to 1
    }
    bool isRoot(int x) {                            // Returns true if this is a root (May contain one or many nodes)
        return u_set[x] == x;
    }
    bool isRootContainsMany(int x) {                // If the root contains more than one value (Actual Root)
        return (isRoot(x) && (u_list[x] > 1));
    }
    bool isSameSet(int a, int b) {                  // If a and b is in same set/component
        return (unionRoot(a) == unionRoot(b));
}};

// Bipartite DSU (Tested)

struct BipartiteDSU {
    vector<int>u_list, u_set, u_color;
    vector<bool>missmatch;                                  // Bicolor missmatch
    
    BipartiteDSU() {}
    BipartiteDSU(int SZ) { init(SZ); }
    
    pll unionRoot(int n) {                                  // Union making with dynamic compression
        if(u_set[n] == n) return {n, u_color[n]};
        pll root = unionRoot(u_set[n]);
        if(missmatch[u_set[n]] or missmatch[n])
            missmatch[n] = missmatch[u_set[n]] = 1;
        u_color[n] = (u_color[n] + root.second)&1;
        u_set[n] = root.first;                              // Directly set the actual root of this set as root (Compress)
        return {u_set[n], u_color[n]};
    }
    int makeUnion(int a, int b) {                                   // Union making with compression
        int x = unionRoot(a).first, y = unionRoot(b).first;
        if(x == y) {                                                // If both are in same set and bipartite missmatch exists
            if(u_color[a] == u_color[b]) missmatch[x] = 1;
            return x;
        }
        if(missmatch[x] or missmatch[y])                            // Checks if Bipartite missmatch exists
            missmatch[x] = missmatch[y] = 1;
        if(u_list[x] < u_list[y]) {                                 // Makes x root (y -> x)
            u_set[x] = y;
            u_list[x] += u_list[y];                                 // Root's size is increased
            u_color[x] = (u_color[a]+u_color[b]+1)&1;               // Setting color of component y according to the color of a & b
            return y;
        }
        else {                                          // Makes y root (x -> y)
            u_set[y] = x;
            u_list[y] += u_list[x];                     // Root's size is increased
            u_color[y] = (u_color[a]+u_color[b]+1)&1;   // Setting color of component y according to the color of a & b
            return x;
    }}
    void init(int len) {                // Initializer
        u_list.resize(len+5);
        u_set.resize(len+5);
        u_color.resize(len+5);
        missmatch.resize(len+5);
        for(int i = 0; i <= len+3; i++)
            u_set[i] = i, u_list[i] = 1, u_color[i] = 0, missmatch[i] = 0;
    }
    bool isRoot(int x) {                // Returns true if this is a root (May contain one or many nodes)
        return u_set[x] == x;
    }
    bool isRootContainsMany(int x) {    // If the root contains more than one value (Actual Root)
        return (isRoot(x) && (u_list[x] > 1));
    }
    bool isSameSet(ll a, ll b) {        // If a and b is in same set/component
        return (unionRoot(a).first == unionRoot(b).first);
    }
    int getColor(ll u) {                // Color of node u (DONT get the color of root)
        return u_color[u];
    }
    bool hasMissmatch(int x) {          // If there is bipartite missmatch in this set/component
        return missmatch[x];
}};

// Dynamic Weighted DSU (Checked, Not Tested)

struct WeightedDSU {
    vector<int>u_list, u_set, u_weight, weight;
    WeightedDSU() {}
    WeightedDSU(int SZ) { init(SZ); }
    int unionRoot(int n) {                                  // Union making with compression
        if(u_set[n] == n) return n;
        return u_set[n] = unionRoot(u_set[n]);              // Directly set the actual root of this set as root (Compress)
    }
    void changeWeight(int u, int w, bool first = 1) {       // Change any component's weight (Dynamic)
        if(first) w = w - weight[u];
        u_weight[u] += w;
        if(u_set[u] != u)
            changeWeight(u_set[u], w, 0);
    }
    int makeUnion(int a, int b) {                           // Union making with compression
        int x = unionRoot(a), y = unionRoot(b);
        if(x == y) return x;
        if(u_list[x] > u_list[y]) {                         // Makes x root (y -> x)
            u_set[y] = x;
            u_list[x] += u_list[y];                         // Root's size is increased
            u_weight[x] += u_weight[y];                     // Root's weight is increased
            return x;
        }
        else {                                              // Makes y root (x -> y)
            u_set[x] = y;
            u_list[y] += u_list[x];                         // Root's size is increased
            u_weight[y] += u_weight[x];                     // Root's weight is increased
            return y;
    }}
    void init(int len) {                                    // Initializer
        u_list.resize(len+5);
        u_set.resize(len+5);
        u_weight.resize(len+5);
        weight.resize(len+5);
        for(int i = 0; i <= len+3; i++)
            u_set[i] = i, u_list[i] = 1, u_weight[i] = weight[i] = 0;
    }
    bool isRoot(int x) {                // Returns true if this is a root (May contain one or many nodes)
        return u_set[x] == x;
    }
    bool isRootContainsMany(int x) {            // If the root contains more than one value (Actual Root)
        return (isRoot(x) && (u_list[x] > 1));
    }
    bool isSameSet(int a, int b) {              // If a and b is in same set/component
        return (unionRoot(a) == unionRoot(b));
    }
    void setWeight(int u, int w) {              // Set weight of node u to w, run before union
        u_weight[u] = w;
        weight[u] = w;
    }
    int getComponentWeight(int u) {             // Get weight sum of the set/comopnent
        return u_weight[unionRoot(u)];
}};
