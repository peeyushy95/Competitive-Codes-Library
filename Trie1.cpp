/*
   AUTHOR  : Peeyush Yadav
   Problem : https://www.codechef.com/SEPT15/problems/REBXOR
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
	#else
		#define trace(x)
		#define trace2(x,y)
		#define trace3(x,y,z)
	#endif
	
	#define fi 						          first
	#define se 						          second
	#define mp 						          make_pair
	#define pb(x) 					        push_back(x)
	#define s(x)                    scanf("%d",&x);
	#define sl(x)                   scanf("%lld",&x);
	#define p(x)                    printf("%d\n",x);
	#define f(a,b,c)                for(int a=b;a<c;a++)
	#define r(a,b,c)				        for(int a=b;a>c;a--)
	#define p2(x,y)                 printf("%d %d\n",x,y);
	#define pl(x)                   printf("%lld\n",x);
	#define pl2(x,y)                printf("%lld %lld\n",x,y);
	#define p1d(a,n)                for(int ix=0;ix<n;ix++) printf("%d ",a[ix]); printf("\n");
	#define p2d(a,n,m)              for(int ix=0;ix<n;ix++){ for(int jx=0;jx<m;jx++) printf("%d ",a[ix][jx]); printf("\n");}
}
/*........................................................END OF TEMPLATES.......................................................................*/
 
#define sz  400010
int a[sz],f[sz],b[sz],po[34],trie[sz*30][2];//,trie1[sz*30][2];
int last;
 
 
 
inline void  insert ( int bits){
		int x  = 0;
		r(pos,30,-1){
			if (po[pos] & bits){
				if (!trie[x][1]) trie[x][1]=++last;
				x = trie[x][1];
			}	
			else{
				if(!trie[x][0])	 trie[x][0]=++last;
				x = trie[x][0];
			}
		}	
}
 
inline int query (int a){
		int x  = 0;
		int ans  = 0;
		r(pos,30,-1){
			if (po[pos] & a){
				if (!trie[x][0]) x = trie[x][1];
				else{
					ans += po[pos];
					x =  trie[x][0];
				}
			}	
			else{
				if(!trie[x][1])	 x = trie[x][0];
				else{
					ans += po[pos];
					x =  trie[x][1];
				}
			}
		}
		return ans;
}
  
 
int main(){
    	fast();
    	int t,n,xr=0,maxxor=0;
    	s(n)
    	
    	po[0] = 1;
    	f(i,1,32) po[i] = po[i-1]*2;
    	
    	f(i,0,n) s(a[i]);
    	
    	last = 0;
    	
    	insert(0);
    	insert(a[0]);
    	
    	
    	f[0] = a[0];	
    	b[n-1] = a[n-1];
    	xr = a[0];
    	
    	f(i,1,n){
    		xr = xr ^ a[i];
    		insert(xr);
    		f[i] = max(f[i-1], query(xr));
    	}
    	
    	last = 0;
    	f(i,0,30*sz) trie[i][0]=trie[i][1]=0;
    	insert(0);
    	insert(a[n-1]);
    	xr = a[n-1];
    	r(i,n-2,-1){
    		xr = xr ^ a[i];
    		insert(xr);
    		b[i] = max(b[i+1], query(xr));
    	}
    	int ans = 0;
    	
    	f(i,1,n)	if(f[i-1] + b[i] > ans) ans = f[i-1] + b[i];
    	
    	
    	p(ans)
    	#ifdef Megamind
    		cerr << "\nTime elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
    	#endif
}   
