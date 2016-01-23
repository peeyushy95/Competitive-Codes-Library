/*
   (•_•)
   <) )>
    / \
   AUTHOR: Peeyush yadav
   Problem: http://www.codechef.com/APRIL15/problems/FRMQ
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
            #define DEBUG
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
#define MAX 100000+3
#define LOGN 17
int pre[LOGN][MAX],a[MAX],logo[MAX],p[20];
int Xpath[MAX],Ypath[MAX]; 
int main(){
    input();
	long long ans=0;
	int m,x,y,n,i,j;
	read(n);
	f(i1,0,n) {
		read(a[i1]);
		pre[0][i1] = i1;
	}
	read(m);
	read(x);
	read(y);
	Xpath[0]=x%(n-1);
	Ypath[0]=y;
	
	f(i1,0,n) {
		Xpath[i1+1] =  (Xpath[i1] + 7)%(n-1);
		Ypath[i1+1] =  (Ypath[i1] + 11)%n;
	}
 
	
	p[0]=1;
	f(i,1,20) p[i]=p[i-1]*2;
	logo[1]=0;
	logo[2]=1;
	f(i,3,n+1) logo[i] = logo[i>>1]+1;
	
    for(j=1;p[j]<=n;j++)
	  for(i=0;i+p[j]-1<n;i++){
		  if (a[pre[j-1][i]] > a[pre[j-1][i+p[j-1]]])     pre[j][i] = pre[j-1][i];
		  else											  pre[j][i] = pre[j-1][i+p[j-1]];
	  }
	
	i = min(x,y);
	j = max(x,y);
	int k = logo[j-i+1];
	if(a[pre[k][i]] >= a[pre[k][j-p[k]+1]])   ans = a[pre[k][i]];
	else                                      ans = a[pre[k][j-p[k]+1]];
 
	int l=1,r=1,temp;
	f(i1,1,m) {
      
       if(Xpath[l]>Ypath[r]) {
		   i = Ypath[r++];
		   j = Xpath[l++];
       }
       else{
       	   j = Ypath[r++];
		   i = Xpath[l++];
       }
	   k =logo[j-i+1];
	   if(a[pre[k][i]] >= a[pre[k][j-p[k]+1]])     ans = ans+a[pre[k][i]];
       else                                        ans = ans + a[pre[k][j-p[k]+1]];
	   if(l>n-1) l = 1;
	   if(r>n)   r = 1;
	}
 
	pl(ans);
 
 
} 
