/*
   AUTHOR  : Peeyush Yadav
   Problem : https://www.hackerrank.com/challenges/insertion-sort
*/
 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f(a,b,c)                for(int a=b;a<c;a++)
#define s(x)                    scanf("%d",&x);
#define sl(x)                   scanf("%lld",&x);
#define p(x)                    printf("%d\n",x);
#define p2(x,y)                 printf("%d %d\n",x,y);
#define pl(x)                   printf("%lld\n",x);
#define pl2(x,y)                printf("%lld %lld\n",x,y);
#define p1d(a,n)                for(int ix=0;ix<n;ix++) printf("%d ",a[ix]); printf("\n");
#define p2d(a,n,m)              for(int ix=0;ix<n;ix++){ for(int jx=0;jx<m;jx++) printf("%d ",a[ix][jx]); printf("\n");}
void input(){
	#ifdef Megamind
			#define DEBUG
			#define TRACE
			freopen("inp.txt","r",stdin);
			//freopen("out1.txt","w",stdout);
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
#define SIZE 123456

ll a[123456],b[SIZE];
int n;
int tree[SIZE];

int read(int ind){
	int counter=0;
	while(ind > 0){
		counter+=tree[ind];
		ind-= ind&-ind;
	}
	return counter;
}

void upd(int ind){
	for(int i = ind; i < n+10 ; i+= i&-i) tree[i]++;
}

int main(){
	input();
	
	int t,ind;
	
	s(t);
	
	while(t--){
		s(n);
		ll ans = 0;
		f(i,0,n) {
			sl(a[i]);
			b[i]= a[i];
		}
		sort(b,b+n);
		f(i,0,n){
			ind = lower_bound(b,b+n,a[i]) - b;
			ans += i - read(ind+1);
			upd(ind+1);
		}
		pl(ans);
		memset(tree,0,sizeof(tree));
	}
	
	#ifdef Megamind
		cerr << "\nTime elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
        #endif
}
