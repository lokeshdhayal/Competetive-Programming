#include <bits/stdc++.h>
using namespace std;
#define vector<int> v;
int t,n,i,j,l,k;
int main(){cin>>t;
    while(t--){
        cin>>n;
        vector<v> a(n,v(n));
        while(i<n){
            j=0;
            while(j<=i){
                cin>>v[i][j],j++;
            }
            i++;
        }
        v b(a.back());
        i=n-2;
        while(i>=0){
            for(j=0;j<=i;j++){
                b[j]=max(b[j],b[j+1])+a[i][j];
            }
            i++;
        }
        cout<<b[0]<<"\n";
    }
}