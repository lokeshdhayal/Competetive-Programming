#include <bits/stdc++.h>


using namespace std;
struct segtree {
    struct node {
        // initial values for leaves
        long long mx = 0;
        long long sum = 0;
        long long add = 0;

        void apply(int l, int r, long long v) {
            mx += v;
            sum += (r - l + 1) * v;
            add += v;
        }
    };

    static node unite(const node &a, const node &b) {
        node res;
        res.mx = max(a.mx, b.mx);
        res.sum = a.sum + b.sum;
        return res;
    }

    void push(int x, int l, int r) {
        int m = (l + r) >> 1;
        int y = x + ((m - l + 1) << 1);
        if (tree[x].add != 0) {
            tree[x + 1].apply(l, m, tree[x].add);
            tree[y].apply(m + 1, r, tree[x].add);
            tree[x].add = 0;
        }
    }

    void pull(int x, int y) { tree[x] = unite(tree[x + 1], tree[y]); }

    int n;
    vector<node> tree;

    void build(int x, int l, int r) {
        if (l == r) {
            return;
        }
        int m = (l + r) >> 1;
        int y = x + ((m - l + 1) << 1);
        build(x + 1, l, m);
        build(y, m + 1, r);
        pull(x, y);
    }

    template <class T>
    void build(int x, int l, int r, const vector<T> &v) {
        if (l == r) {
            tree[x].apply(l, r, v[l]);
            return;
        }
        int m = (l + r) >> 1;
        int y = x + ((m - l + 1) << 1);
        build(x + 1, l, m, v);
        build(y, m + 1, r, v);
        pull(x, y);
    }

    node get(int x, int l, int r, int ll, int rr) {
        if (ll <= l && r <= rr) {
            return tree[x];
        }
        int m = (l + r) >> 1;
        int y = x + ((m - l + 1) << 1);
        push(x, l, r);
        node res;
        if (rr <= m) {
            res = get(x + 1, l, m, ll, rr);
        } else {
            if (ll > m) {
                res = get(y, m + 1, r, ll, rr);
            } else {
                res = unite(get(x + 1, l, m, ll, rr), get(y, m + 1, r, ll, rr));
            }
        }
        pull(x, y);
        return res;
    }

    template <class T>
    void modify(int x, int l, int r, int ll, int rr, const T &v) {
        if (ll <= l && r <= rr) {
            tree[x].apply(l, r, v);
            return;
        }
        int m = (l + r) >> 1;
        int y = x + ((m - l + 1) << 1);
        push(x, l, r);
        if (ll <= m) {
            modify(x + 1, l, m, ll, rr, v);
        }
        if (rr > m) {
            modify(y, m + 1, r, ll, rr, v);
        }
        pull(x, y);
    }

    segtree(int _n) : n(_n) {
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1);
    }

    template <class T>
    segtree(const vector<T> &v) {
        n = v.size();
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1, v);
    }

    node get(int ll, int rr) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return get(0, 0, n - 1, ll, rr);
    }

    node get(int p) {
        assert(0 <= p && p <= n - 1);
        return get(0, 0, n - 1, p, p);
    }

    template <class T>
    void modify(int ll, int rr, const T v) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        modify(0, 0, n - 1, ll, rr, v);
    }

    int find_first(int ll, int rr, const function<bool(const node &)> &f, int x, int l, int r) {
        if (ll <= l && r <= rr && !f(tree[x])) {
            return -1;
        }
        if (l == r) {
            return l;
        }
        push(x, l, r);
        int m = (l + r) >> 1;
        int y = x + ((m - l + 1) << 1);
        int res = -1;
        if (ll <= m) {
            res = find_first(ll, rr, f, x + 1, l, m);
        }
        if (rr > m && res == -1) {
            res = find_first(ll, rr, f, y, m + 1, r);
        }
        pull(x, y);
        return res;
    }

    // calls all FALSE elements to the left of the sought position exactly once
    int find_first(int ll, int rr, const function<bool(const node &)> &f) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return find_first(ll, rr, f, 0, 0, n - 1);
    }
};

// Returns min(p | p<=rr && sum[ll..p]>=sum). If no such p exists, returns -1
int sum_lower_bound(segtree &t, int ll, int rr, long long sum) {
    long long sumSoFar = 0;
    return t.find_first(ll, rr, [&](const segtree::node &node) {
        if (sumSoFar + node.sum >= sum)
            return true;
        sumSoFar += node.sum;
        return false;
    });
}


class HeavyLight {
   public:
    vector<vector<int>> tree;
    bool valuesOnVertices;  // true - values on vertices, false - values on edges
    segtree segment_tree;
    vector<int> parent;
    vector<int> depth;
    vector<int> pathRoot;
    vector<int> in;

    HeavyLight(const vector<vector<int>> &t, bool valuesOnVertices)
        : tree(t),
          valuesOnVertices(valuesOnVertices),
          segment_tree(t.size()),
          parent(t.size()),
          depth(t.size()),
          pathRoot(t.size()),
          in(t.size()) {
        int time = 0;
        parent[0] = -1;

        function<int(int)> dfs1 = [&](int u) {
            int size = 1;
            int maxSubtree = 0;
            for (int &v : tree[u]) {
                if (v == parent[u])
                    continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                int subtree = dfs1(v);
                if (maxSubtree < subtree) {
                    maxSubtree = subtree;
                    swap(v, tree[u][0]);
                }
                size += subtree;
            }
            return size;
        };

        function<void(int)> dfs2 = [&](int u) {
            in[u] = time++;
            for (int v : t[u]) {
                if (v == parent[u])
                    continue;
                pathRoot[v] = v == t[u][0] ? pathRoot[u] : v;
                dfs2(v);
            }
        };

        dfs1(0);
        dfs2(0);
    }

    segtree::node get(int u, int v) {
        segtree::node res;
        process_path(u, v, [this, &res](int a, int b) { res = segtree::unite(res, segment_tree.get(a, b)); });
        return res;
    }

    void modify(int u, int v, long long delta) {
        process_path(u, v, [this, delta](int a, int b) { segment_tree.modify(a, b, delta); });
    }

    void process_path(int u, int v, const function<void(int x, int y)> &op) {
        for (; pathRoot[u] != pathRoot[v]; v = parent[pathRoot[v]]) {
            if (depth[pathRoot[u]] > depth[pathRoot[v]])
                swap(u, v);
            op(in[pathRoot[v]], in[v]);
        }
        if (u != v || valuesOnVertices)
            op(min(in[u], in[v]) + (valuesOnVertices ? 0 : 1), max(in[u], in[v]));
    }
};

#define ll long long
#define F first 
#define S second

// usage example
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
//    freopen("input.txt" , "r" ,stdin);
  //  freopen("output.txt" , "w" , stdout);
#endif
    ll t , n , u , v , w , k , p;
    t = 1;
    while(t--){
        cin>>n>>k;
        vector<vector<int> > adj(n);
        vector<ll> a(n);
        for(int i = 0;i < n;i++){cin>>a[i];}
        for(int i = 0;i < n - 1;i++){
            cin>>u>>v;
            u--;v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        HeavyLight he(adj , 1);
        for(int i = 0;i < n;i++){
            he.modify(i , i , a[i]);
        }
        while(k--){
            cin>>p;
            if(p == 2){
                cin>>v;
                v--;
                cout<<he.get(0 , v).sum<<'\n';
            }
            else{
                cin>>u>>v;
                u--;
                int p = he.get(u , u).sum;
                he.modify(u , u , v - p);
            }
        }
    }
#ifndef ONLINE_JUDGE
    cout << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
}
