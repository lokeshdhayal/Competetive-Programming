class UnionFind {
private: vi p, rank;
public:
    UnionFind(int N) { rank.assign(N, 0);
        p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
        int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {if (!isSameSet(i, j)) {
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) p[y] = x;
        else { p[x] = y;
            if (rank[x] == rank[y]) rank[y]++; }
        } 
    } 
    int count_val(){
        ll res = 0;
        for(int i = 0;i < p.size();i++){if(p[i] == i)res++;}
        return res;
    }
};


void dfs(int i , vi & low , vi & high , vb & vis , vi adj[] , vb & arti , int p){
    vis[i] = true;
    low[i] = high[i] = target++;
    int child = 0;
    for(auto j : adj[i]){
        if(j == p)continue;
        if(vis[j] == false){
            dfs(j , low , high , vis , adj , arti , i);
            if(low[j] >= high[i] && p != -1){
                arti[i] = true;
            }
            child++;
            low[i] = min(low[i] , low[j]);
        }
        else{
            low[i] = min(low[i] , high[j]);
        }
    }
    if(p == -1 && child > 1){
        arti[i] = true;
    }
}


class FenwickTree {
private: vi ft; // recall that vi is: typedef vector<int> vi;
public:FenwickTree(int n) { ft.assign(n + 1, 0); } 
int LSone(int k ){return (k & (-k));}
int rsq(int b) { // returns RSQ(1, b)
	int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
	return sum; } // note: LSOne(S) (S & (-S))
	int rsq(int a, int b) { // returns RSQ(a, b)
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }
// adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
void adjust(int k, int v) { // note: n = ft.size() - 1
for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
};



class SegmentTree {
private: vi st, A;
int n;
int left (int p) { return p << 1; }
int right(int p) { return (p << 1) + 1; }
void build(int p, int L, int R) {if (L == R) st[p] = L;else {
	build(left(p) , L , (L + R) / 2);
	build(right(p), (L + R) / 2 + 1, R );
	int p1 = st[left(p)], p2 = st[right(p)];
	st[p] = (A[p1] >= A[p2]) ? p1 : p2;}
	}
int rmq(int p, int L, int R, int i, int j) {if (i > R || j < L) return -1;
	if (L >= i && R <= j) return st[p];
	int p1 = rmq(left(p) , L , (L+R) / 2, i, j);
	int p2 = rmq(right(p), (L+R) / 2 + 1, R , i, j);
	if (p1 == -1) return p2;
	if (p2 == -1) return p1;
	return (A[p1] <= A[p2]) ? p1 : p2;
}
void update(int si , int ss , int se , int pos , int val){
	if(ss == se){
		st[si] = val;
	}
	else{
		int k = (ss + se) / 2;
		if(pos <= k){
			update(2*si , ss , k , pos , val);
		}
		else{
			update(2 * si + 1 , k + 1 , se , pos , val);
		}
		st[si] = max(st[2*si] , st[2 *si + 1]);
	}
}
public:
	SegmentTree(const vi &_A) {A = _A; n = (int)A.size();
		st.assign(4 * n, 0);
		build(1, 0, n - 1);
	}
	int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
	void update(int i , int val){
		update(0 , 0 , n - 1 , i , val);
	}
};