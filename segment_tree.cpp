#include <bits/stdc++.h>
using namespace std;
struct segtree {
    struct node {
        long long mx = 0;
        long long sum = 0;
        long long add = 0;
        long long xr = 0;

        void apply(int l, int r, long long v) {
            if(v > mx)mx = v;
            sum += (r - l + 1) * v;
            if((r - l + 1)%2)xr ^= v;
            add += v;
        }
    };

    static node unite(const node &a, const node &b) {
        node res;
        res.mx = max(a.mx, b.mx);
        res.sum = a.sum + b.sum;
        res.xr = a.xr ^ b.xr;
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
    int find_first(int ll, int rr, const function<bool(const node &)> &f) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return find_first(ll, rr, f, 0, 0, n - 1);
    }
};
int sum_lower_bound(segtree &t, int ll, int rr, long long sum) {
    long long sumSoFar = 0;
    return t.find_first(ll, rr, [&](const segtree::node &node) {
        if (sumSoFar + node.sum >= sum)
            return true;
        sumSoFar += node.sum;
        return false;
    });
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" ,stdin);
    freopen("output.txt" , "w" , stdout);
#endif
    segtree p(5);
    p.modify(1 , 1 , 1);
    p.modify(2 , 2 , 2);
    cout<<p.get(1,2).xr<<'\n';
#ifndef ONLINE_JUDGE
    cout << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
}
