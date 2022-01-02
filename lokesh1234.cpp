bool Check(TreeNode * t,int left,int right){
	if(t == NULL)return 1;
	if(!(t->val >= left && t->val <= right))return 0;
	return Check(t->left,left,t->val-1)&&Check(t->right,t->val+1,right);
}

Check(root,-inf,+inf)


sum = 0;sum%2 != 0 

int dp[100][100];

int solve(int i,int sum){
	if(sum < 0)return 0;
	if(i == n)return sum == 0;
	if(dp[i][sum]!=-1)return dp[i][sum];
	return dp[i][sum]=solve(i+1,sum-a[i])||solve(i+1,sum);
}
memset(dp,-1,sizeof(dp));
C(n,2) * C(n-2,2)
n
n 105
Odd -> n



int solve(int n){
	if(n == 0 || n == 1)return 1;
	return n*(n-1)/2 * solve(n-2) + solve(n-1);
}
<< >> & 

int count(int n){
	int cnt = 0;
	while(n){
		if(n%2)cnt++;
		n/=2;
	}
	return cnt;
}


BFS

vector<TreeNode *> solve(TreeNode *root){
	queue<TreeNode *>  q;
	vector<TreeNode *> ans;
	q.push(root);
	bool flag = 0;
	while(!q.empty()){
		int r = (int)q.size();
		vector<TreeNode *>p;
		for(int i = 0;i < r;i++){
			p.push_back(q.front());
			auto front = q.front();q.pop();
			if(front->left!=NULL)q.push(front->left);
			if(front->right!=NULL)q.push(front->right);
		}
		if(flag){
			reverse(p.begin(),p.end());
		}
		for(int i = 0;i < (int)p.size();i++){
			ans.push_back(p[i]);
		}
		flag = !flag;
	}
	return ans;
}

s1 s2

s1 = n
s2 = m

1000 


int solve(int i,int j){
	if(i == (int)s1.size())return (int)s2.size()-j;
	if(j == (int)s2.size())return (int)s1.size()-i;
	if(s1[i] == s2[j]){
		return solve(i+1,j+1);
	}
	return min(solve(i+1,j),solve(i,j+1));
}

