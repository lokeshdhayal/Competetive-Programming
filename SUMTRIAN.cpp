#include <bits/stdc++.h>
using namespace std;
int t,n,i,j,l,k;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		vector<vector<int> > a;
		for(i=0;i<n;i++){
			std::vector<int> q;
			for(j=0;j<=i;j++){
				cin>>l;
				q.push_back(l);
			}
			a.push_back(q);
		}
		std::vector<int> b(a.back());
		for(i=n-2;i>=0;i--){
			for(j=0;j<=i;j++){
				b[j]=max(b[j],b[j+1])+a[i][j];
			}
		}
		cout<<b[0]<<"\n";
	}
}