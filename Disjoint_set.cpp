//https://codeforces.com/problemset/problem/1557/D
//Tree Rerooting
//https://codeforces.com/contest/1187/submission/135924468

// persistance segment tree
//https://www.spoj.com/problems/MKTHNUM/

//
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
    st[p] = (A[p1] <= A[p2]) ? p1 : p2;}
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
        st[si] = pos;
        A[pos] = val;
    }
    else{
        int k = (ss + se) / 2;
        if(pos <= k){
            update(2*si , ss , k , pos , val);
        }
        else{
            update(2 * si + 1 , k + 1 , se , pos , val);
        }
        int p1 = st[2*si];
        int p2 = st[2*si + 1];
        st[si] = (A[p1] <= A[p2]) ? p1 : p2;
    }
}
public:
    SegmentTree(const vi &_A) {A = _A; n = (int)A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }
    int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
    void update(int i , int val){
        update(1 , 0 , n - 1 , i , val);
    }
};



------------Sparse Table -------------



#define MAX_N 1000
#define LOG_TWO_N 10
class RMQ {
private:
    int _A[MAX_N], SpT[MAX_N][LOG_TWO_N];
public:
    RMQ(int n, int A[]) {
        for (int i = 0; i < n; i++) {
            _A[i] = A[i];
            SpT[i][0] = i;
        }
        for (int j = 1; (1<<j) <= n; j++) 
            for (int i = 0; i + (1<<j) - 1 < n; i++)
                if (_A[SpT[i][j-1]] < _A[SpT[i+(1<<(j-1))][j-1]])
                    SpT[i][j] = SpT[i][j-1];
                else
                    SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
    }
    int query(int i, int j) {
        int k = (int)floor(log((double)j-i+1) / log(2.0));
        if (_A[SpT[i][k]] <= _A[SpT[j-(1<<k)+1][k]]) return SpT[i][k];
        else return SpT[j-(1<<k)+1][k];
    }
};


-------------lazy ---------------



class SegmentTree {
private: vi st, A , lazy;
int n;
int left (int p) { return p << 1; }
int right(int p) { return (p << 1) + 1; }
void build(int p, int L, int R) {if (L == R) st[p] = A[L];else {
    build(left(p) , L , (L + R) / 2);
    build(right(p), (L + R) / 2 + 1, R );
    ll p1 = st[left(p)], p2 = st[right(p)];
    st[p] = p1 + p2;}
    }
ll rmq(int p, int L, int R, int i, int j) {if (i > R || j < L) return -1;
    if (L >= i && R <= j) return st[p];
    if(lazy[p] && 2*p < lazy.size()){
        int si = p;
        lazy[2*si] += lazy[si];
        lazy[2*si + 1] += lazy[si];
        st[2*si] += lazy[si];
        st[2*si + 1] += lazy[si];
        lazy[si] = 0;
    }
    ll p1 = rmq(left(p) , L , (L+R) / 2, i, j);
    ll p2 = rmq(right(p), (L+R) / 2 + 1, R , i, j);
    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return p1 + p2;
}
void update(int si , int ss , int se , int pos , ll val){
    if(ss == se){
        st[si] = val;
        A[pos] = val;
    }
    else{
        if(lazy[si] && 2*si < lazy.size()){
            lazy[2*si] += lazy[si];
            lazy[2*si + 1] += lazy[si];
            st[2*si] += lazy[si];
            st[2*si + 1] += lazy[si];
            lazy[si] = 0;
        }
        int k = (ss + se) / 2;
        if(pos <= k){
            update(2*si , ss , k , pos , val);
        }
        else{
            update(2 * si + 1 , k + 1 , se , pos , val);
        }
        ll p1 = st[2*si];
        ll p2 = st[2*si + 1];
        st[si] = p1 + p2;
    }
}

ll modify(int p , int L , int R, int i , int j , int val){
    if (i > R || j < L) return -1;
    if (L >= i && R <= j){ 
        st[p] += (R - L + 1) * val;
        lazy[p] += val;
        return st[p];
    }
    if(lazy[p] && 2*p < lazy.size()){
        int si = p;
        lazy[2*si] += lazy[si];
        lazy[2*si + 1] += lazy[si];
        st[2*si] += lazy[si];
        st[2*si + 1] += lazy[si];
        lazy[si] = 0;
    }
    ll p1 = modify(left(p) , L , (L+R) / 2, i, j , val);
    ll p2 = modify(right(p), (L+R) / 2 + 1, R , i, j , val);
    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return p1 + p2;
}

public:
    SegmentTree(const vi &_A) {A = _A; n = (int)A.size();
        st.assign(4 * n, 0);
        lazy.assign(4 * n , 0);
        build(1, 0, n - 1);
    }
    ll rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
    void update(int i , ll val){
        update(1 , 0 , n - 1 , i , val);
    }
    ll modify(int i , int j , ll val){
        return modify(1 , 0 , n - 1 , i , j , val);
    }
};





class SegmentTree {
private: vi st, A , lazy;
int n;
int left (int p) { return p << 1; }
int right(int p) { return (p << 1) + 1; }
void build(int p, int L, int R) {if (L == R) st[p] = A[L];else {
    build(left(p) , L , (L + R) / 2);
    build(right(p), (L + R) / 2 + 1, R );
    ll p1 = st[left(p)], p2 = st[right(p)];
    st[p] = max(p1 , p2);}
    }
ll rmq(int p, int L, int R, int i, int j) {if (i > R || j < L) return -1;
    if (L >= i && R <= j) return st[p];
    if(lazy[p] != -1 && 2*p < lazy.size()){
        int si = p;
        lazy[2*si] = lazy[si];
        lazy[2*si + 1] = lazy[si];
        st[2*si] = lazy[si];
        st[2*si + 1] = lazy[si];
        lazy[si] = -1;
    }
    ll p1 = rmq(left(p) , L , (L+R) / 2, i, j);
    ll p2 = rmq(right(p), (L+R) / 2 + 1, R , i, j);
    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return max(p1 , p2);
}
void update(int si , int ss , int se , int pos , ll val){
    if(ss == se){
        st[si] = val;
        A[pos] = val;
    }
    else{
        if(lazy[si] != -1 && 2*si < lazy.size()){
            lazy[2*si] = lazy[si];
            lazy[2*si + 1] = lazy[si];
            st[2*si] = lazy[si];
            st[2*si + 1] = lazy[si];
            lazy[si] = -1;
        }
        int k = (ss + se) / 2;
        if(pos <= k){
            update(2*si , ss , k , pos , val);
        }
        else{
            update(2 * si + 1 , k + 1 , se , pos , val);
        }
        ll p1 = st[2*si];
        ll p2 = st[2*si + 1];
        st[si] = max(p1 , p2);
    }
}

ll modify(int p , int L , int R, int i , int j , int val){
    if (i > R || j < L) return -1;
    if (L >= i && R <= j){ 
        st[p] = val;
        lazy[p] = val;
        return st[p];
    }
    if(lazy[p] != -1 && 2*p < lazy.size()){
        int si = p;
        lazy[2*si] = lazy[si];
        lazy[2*si + 1] = lazy[si];
        st[2*si] = lazy[si];
        st[2*si + 1] = lazy[si];
        lazy[si] = -1;
    }
    ll p1 = modify(left(p) , L , (L+R) / 2, i, j , val);
    ll p2 = modify(right(p), (L+R) / 2 + 1, R , i, j , val);
    if (p1 == -1) return st[p] = p2;
    if (p2 == -1) return st[p] = p1;
    return st[p] = max(p1 , p2);
}

public:
    SegmentTree(const vi &_A) {A = _A; n = (int)A.size();
        st.assign(4 * n, 0);
        lazy.assign(4 * n , -1);
        build(1, 0, n - 1);
    }
    ll rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
    void update(int i , ll val){
        update(1 , 0 , n - 1 , i , val);
    }
    ll modify(int i , int j , ll val){
        return modify(1 , 0 , n - 1 , i , j , val);
    }
};




------------------- Trie ----------------

class Trie {
public:
    struct TreeNode
    {
        bool we;
        TreeNode * child[26];
    };
    TreeNode *root;
    Trie() {
        root = getNode();
    }
    TreeNode * getNode(){
        TreeNode *newNode = new TreeNode;
        newNode->we = false;
        for(int i = 0;i < 26;i++){
            newNode->child[i] = NULL;
        }
        return newNode;
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TreeNode *curr;
        curr = root;
        for(int i = 0;i < word.size();i++){.
            int k = word[i] - 'a';
            if(!curr->child[k]){
                curr->child[k] = getNode();
            }
            curr = curr->child[k];
        }
        curr->we = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TreeNode *curr;
        curr = root;
        for(int i = 0;i < word.size();i++){
            int k = word[i] - 'a';
            if(!curr->child[k]){
                return false;
            }
            curr = curr->child[k];
        }
        return (curr != NULL && curr->we);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string s) {
        TreeNode *curr;
        curr = root;
        for(int i = 0;i < s.size();i++){
            int k = s[i] - 'a';
            if(!curr->child[k]){
                return false;
            }
            curr = curr->child[k];
        }
        return true;
    }
};


//// Monotonic Queue //////
class Solution{
public:
    deque<pair<ll,ll>>dq;
    void add(ll idx,ll val){
        while(!dq.empty() && dq.back().second >= val)dq.pop_back();
        dq.push_back({idx,val});
        return;
    }
    void del(ll i){
        while(!dq.empty()&&dq.front().first== i){
            dq.pop_front();
        }
        return;
    }
    ll mn(){
        return dq.front().second;
    }
};

// Venice Technique ///

struct VeniceSet {
    multiset<int> S;
    int water_level = 0;
    void add(int v) {
        S.insert(v + water_level);
    }
    void remove(int v) {
        S.erase(S.find(v + water_level));
    }
    void updateAll(int v) {
        water_level += v;
    }
    int getMin() {
        return *S.begin() - water_level;
    }
    int size() {
        return S.size();
    }
};

