----Krushkals Algorithm----

bool comp(pair<int , pi > a, pair<int , pi > b){
    return a.F < b.F;
}
ll krushkals(int V , vector<pair<ll , pi> > EdgeList){
    sort(EdgeList.begin(), EdgeList.end() , comp);
    ll mst_cost = 0;
    UnionFind UF(V);
    int E = EdgeList.size();
    for (int i = 0; i < E; i++){
        pair<int, pi> front = EdgeList[i];
        if (!UF.isSameSet(front.second.first, front.second.second)) {
            mst_cost += front.first;
            UF.unionSet(front.second.first, front.second.second);
        }
    }
    return mst_cost;
}


------Prims Algorithm---------


void process(int vtx , priority_queue<pi> & pq , vi & taken , vector<pi> adj[]) {
    taken[vtx] = 1;
    for (int j = 0; j < (int)adj[vtx].size(); j++) {
        pi v = adj[vtx][j];
        if (!taken[v.first]) pq.push({v.second, v.first});
    }
}
ll prims(int V , vector<pi> adj[]){
    vi taken;
    priority_queue<pi> pq;
    taken.assign(V, 0);
    process(0 , pq , taken , adj);
    ll mst_cost = 0;
    while (!pq.empty()) {
        pi front = pq.top(); pq.pop();
        int u = front.second, w = front.first;
        if (!taken[u])
            {mst_cost += w, process(u , pq , taken , adj);}
    }
    return mst_cost;
}


------Articulation Points------

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


--------Dijkastra-------


int dijkstra(int V ,int s , vector<pi> AdjList[] , int d){
	vi dist(V, INT_MAX); dist[s] = 0;
	priority_queue< pi, vector<pi>, greater<pi> > pq;
	pq.push(pi(0, s));
	while (!pq.empty()) {
	pi front = pq.top(); pq.pop();
	int d = front.first, u = front.second;
	if (d > dist[u]) continue;
	for (int j = 0; j < (int)AdjList[u].size(); j++) {
		pi v = AdjList[u][j];
		if (dist[u] + v.second < dist[v.first]) {
			dist[v.first] = dist[u] + v.second;
			pq.push(pi(dist[v.first], v.first));
			}
		}
	}
	return dist[d];
}


---------Bellman fords algorithm---------


bool bellman(int V , vector<pi> AdjList[]){
    vi dist(V, INF); dist[0] = 0;
    for (int i = 0; i < V - 1; i++)
    for (int u = 0; u < V; u++)
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
        pi v = AdjList[u][j];
        dist[v.first] = min(dist[v.first], dist[u] + v.second);
    }
    bool hasNegativeCycle = false;
    for (int u = 0; u < V; u++)
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            pi v = AdjList[u][j];
            if (dist[v.first] > dist[u] + v.second)
            hasNegativeCycle = true;
    }
    return hasNegativeCycle;
}



----------Flod warshalls APSP --------

void APSP(vector<vector<int> > & AdjMat){
	for (int k = 0; k < V; k++)
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)
				AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
}

------printing sortest path --------

void printPath(int i, int j) {
	if (i != j) printPath(i, p[i][j]);
	printf(" %d", j);
}

for (int i = 0; i < V; i++)
	for (int j = 0; j < V; j++)
		p[i][j] = i;

if (AdjMat[i][k] + AdjMat[k][j] < AdjMat[i][j]) {
	AdjMat[i][j] = AdjMat[i][k] + AdjMat[k][j];
	p[i][j] = p[k][j];
}



----------Edmonds Karps------------

int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}


-------- dfs --------

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
}

---------graph colouring bfs ---------


int dx[] = {2,2,-2,-2,1,1,-1,-1};
int dy[] = {1,-1,1,-1,2,-2,2,-2};


------- BFS -------------

void bfs(){
	queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    vis[x][y] = 1;
    dis[x][y] = 0;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(l = 0;l < 8;l++){
            if(is_valid(dx[l] + i,dy[l] + j)){
                q.push(make_pair(dx[l] + i,dy[l] + j));
                dis[i+dx[l]][j + dy[l]] = dis[i][j] + 1;
                vis[i + dx[l]][j + dy[l]] = 1;
            }
        }
    }
    x = s2[0] - 'a';
    y = s2[1] - 1 - '0';
    cout<<dis[x][y]<<nl;
}


--------- DFS -----------



int dx[] = {0 , 1 , -1 , 0 };
int dy[] = {1 , 0 , 0 , -1 };
bool flag = false;

void dfs(int i,int j , vector<vc> & g , vector<vb> & vis){
    //cout<<i<<" "<<j<<nl;
    if(i < 0 || j < 0 || i >= g.size() || j >= g[0].size()){return;}
    if(vis[i][j] || g[i][j] == '#')return;
    if(i == p && j == q){
      //  cout<<"ye"<<nl;
        flag = true;
    }
    vis[i][j] = true;
    for(int k = 0;k < 4;k++){
        dfs(i + dx[k] , j + dy[k] , g , vis);
    }
}


------Modified dfs top sort ------

vi ans;
void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}
reverse(all(ans));

--------- toposort ------

vi toposort(vi & ind){
    priority_queue<int,vector<int> , greater<int>> q;
    for(int i = 1;i <= n;i++){
        if(ind[i] == 0){
            q.push(i);
        }
    }
    vi ans;
    while(!q.empty()){
        int curr = q.top();
        ans.push_back(curr);
        q.pop();
        for(int lokesh : adj[curr]){
            ind[lokesh]--;
            if(ind[lokesh] == 0){
                q.push(lokesh);
            }
        }
    }
    return ans;
}

-----------Bipirtite Check -----------------

bool dfs(int i,int col){
    cols[i] = col;
    for(int j : adj[i]){
        if(col[j] != -1){
            if(!dfs(j,col^1))
                return false;
        }
        else if(cols[j] == cols[i]){
            return false;
        }
    }
    return true;
}

------ Tarjans Algorithm---------

void tarjanSCC(int u , vb & visited , vi & dfs_low , vi & dfs_num , vi & S , vi AdjList[] , int & dfsNumberCounter , vb & in_stack) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    S.push_back(u);
    visited[u] = true;
    in_stack[u] = true;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        if (visited[v] == false)
            tarjanSCC(v , visited , dfs_low , dfs_num , S , AdjList , dfsNumberCounter , in_stack);
        if (in_stack[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if (dfs_low[u] == dfs_num[u]) {
        printf("SCC %d:", ++numSCC);
        while (1) {
            int v = S.back(); S.pop_back(); in_stack[v] = 0;
            printf(" %d", v);
            if (u == v) break;
        }
        printf("\n");
    }
}

--------Create vector-----

vi create_val(string s){
    int i = 0;
    vi p;
    int u = 0;
    bool sign = true;
    while(i < s.size()){
        if(s[i] == ' '){
            if(sign)p.pb(u);else p.pb(-u);
            sign = false;
        }
        else if(s[i] == '-'){
            sign = false;
        }
        else{
            u *= 10;
            u += s[i] - '0';
        }
        i++;
    }
    if(sign)p.pb(u);else p.pb(-u);
    return p;
}


----------Ford-Fulkerson method-----------


vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}