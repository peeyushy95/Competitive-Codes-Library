/*
   (o_o)
   <) )>
    / \
   AUTHOR  : Peeyush Yadav
   Problem : https://www.codechef.com/JUNE16/problems/CHSQARR 
*/
#include<bits/stdc++.h>
using namespace std; typedef long long ll; typedef pair<int,int> grp;
inline ll power(ll a,ll b)     { ll r=1; while(b){ if(b&1) r=r*a    ; a=a*a    ; b>>=1;} return r;}
inline ll power(ll a,ll b,ll m){ ll r=1; while(b){ if(b&1) r=(r*a)%m; a=(a*a)%m; b>>=1;} return r;}
void fast(){	
	#ifdef Megamind
		freopen("inp.txt","r",stdin);
		//freopen("out.txt","w",stdout);
		#define trace(x)            cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
		#define trace2(x,y)         cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
		#define trace3(x,y,z)       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
		#define trace4(w,x,y,z)     cerr<<__FUNCTION__<<":"<<__LINE__<<": "#w" = "<<w<<" | "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
	#else
		#define trace(x)
		#define trace2(x,y)
		#define trace3(x,y,z)
		#define trace4(w,x,y,z)
	#endif
	
	#define fi						first
	#define se						second
	#define mp						make_pair
	#define pb(x)					push_back(x)
	#define s(x)					scanf("%d",&x);
	#define sl(x)					scanf("%lld",&x);
	#define p(x)					printf("%d\n",x);
	#define f(a,b,c)				for(int a=b;a<c;a++)
	#define r(a,b,c)				for(int a=b;a>c;a--)
	#define p2(x,y)					printf("%d %d\n",x,y);
	#define pl(x)					printf("%lld\n",x);
	#define pl2(x,y)				printf("%lld %lld\n",x,y);
	#define p1d(a,n)				for(int ix=0;ix<n;ix++) printf("%d ",a[ix]); printf("\n");
	#define p2d(a,n,m)				for(int ix=0;ix<n;ix++){ for(int jx=0;jx<m;jx++) printf("%d ",a[ix][jx]); printf("\n");}
	#define TimeElapsed				(double)clock()/CLOCKS_PER_SEC
}
/*........................................................END OF TEMPLATES..................................................................*/
 
 
#define maxSize 1000
#define Log 10
 
int a[maxSize][maxSize],n,m,sum[maxSize][maxSize],po[15],logo[maxSize],q,M[Log][Log][maxSize][maxSize];
 
void SumMatrix(){
	
	f(i,0,n){
		sum[i][0] = a[i][0];
		
		f(j,1,m){
			sum[i][j] = sum[i][j-1] + a[i][j];
		}
	}
 
	f(i,1,n){		
		f(j,0,m){
			sum[i][j] += sum[i-1][j];
		}
	}
}
 
 
 
inline int Max1(int x, int y, int x1, int y1){
	x = max(x,y);
	x1 = max(x1,y1);
	return max(x,x1);
}
 
void SparseTable(){
	po[0]=1;
	f(i,1,15) po[i] = po[i-1]*2LL;
 
	for(int k = 0; po[k] <= n; k++)
		for(int l = 0; po[l] <= m; l++)
			for(int i = 0; i + po[k] - 1 < n; i++)
				for(int j = 0; j + po[l] - 1 < m; j++){
					
					if(k == 0 && l == 0)	M[k][l][i][j] = a[i][j];
					else if(k == 0)			M[k][l][i][j] = max(M[k][l-1][i][j],M[k][l-1][i][j + po[l-1]]);
					else if(l == 0)			M[k][l][i][j] = max(M[k-1][l][i][j],M[k-1][l][i + po[k-1]][j]);	
					else					M[k][l][i][j] = Max1(M[k-1][l-1][i][j],M[k-1][l-1][i + po[k-1]][j],M[k-1][l-1][i + po[k-1]][j + po[l-1]],M[k-1][l-1][i][j + po[l-1]]);	
 
				}
}
 
 
int main(){
	fast(); 
	int x,y,p,q,q1;
	ll temp,ans,temp1,farzi;
 
	logo[1]=0;
	logo[2]=1;
	f(i,3,maxSize) logo[i] = logo[i>>1]+1;
 
	s(n) s(m)
 
	f(i,0,n)
		f(j,0,m)
			s(a[i][j]);
 
	SumMatrix();
	SparseTable();
	
	s(q1)
 
	
	while(q1--){
 
		ans = power(10,9) + 7;
		s(x) s(y)
		farzi = x*y;
		p = logo[x];
    	q = logo[y];
		x--;
		y--;
 
		for(int i = 0; i + x < n ;i++){
			for(int j = 0; j + y < m ; j++){
				temp1 = farzi;
				temp = sum[i+x][j+y]-(i?sum[i-1][j+y]:0)-(j?sum[i+x][j-1]:0) + ((i&&j)?sum[i-1][j-1]:0);				
    			temp1 = temp1*Max1(M[p][q][i][j],M[p][q][i+x-po[p]+1][j],M[p][q][i][j+y-po[q]+1],M[p][q][x+i-po[p]+1][y+j-po[q]+1]);
    
				//trace4(i,j,temp,temp1/farzi)
				ans = min(ans,temp1 - temp);
			}
		}
 
		pl(ans)
	}
 
	trace(TimeElapsed)
	
	
}   
