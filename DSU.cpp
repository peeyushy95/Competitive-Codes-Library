/*
    (•_•)
    <) )>
     / \
   AUTHOR  : Peeyush Yadav {~_~}
   Problem: http://www.codechef.com/MARCH15/problems/MTRWY
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f(a,b,c)                for(int a=b;a<c;a++)
#define s(x)                    scanf("%d",&x);
#define sl(x)                   scanf("%lld",&x);
#define p(x)                    printf("%d\n",x);
#define pl(x)                   printf("%lld\n",x);
#define p1d(a,n)                for(int ix=0;ix<n;ix++) printf("%d ",a[ix]); printf("\n");
#define p2d(a,n,m)              for(int ix=0;ix<n;ix++){ for(int jx=0;jx<m;jx++) printf("%d ",a[ix][jx]); printf("\n");}
void input(){
    #ifdef Megamind
            #define TRACE
            #define gc getchar()
            freopen("inp.txt","r",stdin);
            //freopen("out.txt","w",stdout);
    #else
            #define gc getchar_unlocked()
    #endif
}
#ifdef TRACE
    #define trace(x)                       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
    #define trace2(x,y)                    cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
    #define trace3(x,y,z)                  cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
#else
    #define trace(x)
    #define trace2(x,y)
    #define trace3(x,y,z)
 
#endif
template <class T>
inline void read(T &n1){
	n1=0;
    char c=gc;
    while(c<'0' || c>'9') c=gc;
    while(c>='0' && c<='9'){
       n1=(n1<<3)+(n1<<1)+c-'0';
       c=gc;
    }
}
inline ll power(ll a, ll b, ll m) {
    ll r = 1;
    while(b) {
        if(b & 1) r = r * a % m;
        a = (a * a)% m;
        b >>= 1;
    }
    return r;
}
inline ll power(ll a, ll b) {
     ll r = 1;
    while(b) {
        if(b & 1) r = r * a ;
        a = a * a;
        b >>= 1;
    }
    return r;
}
 
/*........................................................END OF TEMPLATES.......................................................................*/

#define MAXI 1000000 + 10000
bool visited[MAXI],temp1[MAXI],temp2[MAXI];
int parent[MAXI],counter=0,par;
int compo[MAXI];
queue <int> qu;
int n,m,q,maxc=0;

 
 void bfs(int s1){
	qu.push(s1);
	visited[s1]=1;
	while(!qu.empty()){
		int s = qu.front();
		//trace(s);
		qu.pop();
		counter++;		
	    parent[s]=par;
		if(!temp1[s-1] && !visited[s-1])   					qu.push(s-1),visited[s-1]=1;
		if(!temp1[s]   && !visited[s+1])   					qu.push(s+1),visited[s+1]=1;
		if(s>m && !temp2[s-m] && !visited[s-m])             qu.push(s-m),visited[s-m]=1;
		if(!temp2[s]   && !visited[s+m]) 					qu.push(s+m),visited[s+m]=1;		
	}	
}
 
inline int find(int x){
	int y = x;
	while (x != parent[x]) {
		x = parent[x];
	}
	for (;y != x;) {
		int t = parent[y];
		parent[y] = x;
		y = t;
	}
	return x;
}
int a[MAXI][3];
 
int main(){
	input();
	int t;
	read(t);
	
 
	while(t--){
		ll ans=0;
		
		maxc=0;
		read(n);read(m);read(q);
		
		f(i,0,(m*n)+10) {
			compo[i]=0;
		}
		for(int i=0 ;i < n*m+1; i += m  )    temp1[i]=1;
		for(int i=(n-1)*m + 1;i< n*m+1; i++) temp2[i]=1;
	
	    int d=0;
		int type,x,y;;
		f(i2,0,q){
			
			read(type);
			if(type==1){				
				read(x);read(y);
				int del = (x-1)*m + y;
				if(!temp1[del]){	
						a[d][0]=1;
						a[d++][1]=del;
						temp1[del]=1;
				}
			}
			else if(type==2){
				read(x);read(y);
				int del = (x-1)*m + y;
				if(!temp2[del]){
						a[d][0]=2;
						a[d++][1]=del;
						temp2[del]=1;
				}
			}
			else if(type==3){
				a[d][0]=3;
				int x1,y1,x2,y2;
				read(x1);read(y1);read(x2);read(y2);
				x1--;
				x2--;
				a[d][1]   = x1*m + y1;
				a[d++][2] = x2*m + y2;
			}
			else 				
				a[d++][0]=4;
		}
		f(i,1,(m*n)+10) visited[i]=0;
		//p1d(parent,n*m+1);
		f(i,1,n*m+1) {
			counter=0;
			if(!visited[i]){
				par = i;
				bfs(i);
				compo[i]=counter;
				//trace2(i,counter);
				maxc=max(maxc,counter);		
			}			
		}
		for(int i=d-1;i>=0;i--){
			if(a[i][0]==4) {
				ll tenp = maxc;
				ans+= tenp;
			}
			else if(a[i][0]==1){
				
					int del = a[i][1];
					int fx = find(del), fy = find(del+1);
					if (fx != fy) {
							if(compo[fx]>compo[fy]){
								parent[fy] = fx;
								compo[fx] += compo[fy];
								maxc=max(maxc,compo[fx]);
							}
							else{
								parent[fx] = fy;
								compo[fy] += compo[fx];
								maxc=max(maxc,compo[fy]);
							}
					}
					temp1[del]=0;
					
			}
			else if(a[i][0]==2){
					int del = a[i][1];
					int fx = find(del), fy = find(del+m);
					if (fx != fy) {
							if(compo[fx]>compo[fy]){
								parent[fy] = fx;
								compo[fx] += compo[fy];
								maxc=max(maxc,compo[fx]);
							}
							else{
								parent[fx] = fy;
								compo[fy] += compo[fx];
								maxc=max(maxc,compo[fy]);
							}
					}
					temp2[del]=0;
			}
			else {
				int p1 = find(a[i][1]);
				int p2 = find(a[i][2]);
				if(p1==p2) ans++;
				
				
			}
		}
		pl(ans);
		for(int i=0 ;i < n*m+1; i += m  )    temp1[i]=0;
		for(int i=(n-1)*m + 1;i< n*m+1; i++) temp2[i]=0;
		
		
	}
	
}
