/*
   (•_•)
   <) )>
    / \
   AUTHOR  : Peeyush Yadav {~_~}
   Problem : https://www.hackerrank.com/contests/infinitum14/challenges/simple-one
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
/*........................................................END OF TEMPLATES.......................................................................*/

int K = 4;
ll mod = 1000000007,x,y;
typedef vector<vector<ll> > matrix;


matrix mul(matrix A, matrix B){

    matrix C(K, vector<ll>(K));

    f(i,0,K) f(j,0,K) f(k,0,K)   C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    
    return C;
}


matrix pow(matrix A, ll p){
   
    if (p == 1) return A;
    if (p % 2)	return mul(A, pow(A, p-1));

    matrix X = pow(A, p/2);
    return mul(X, X);
}

void fib(ll p, ll q, ll N){

    vector<ll> F1(K);
    matrix T(K, vector<ll>(K));

    F1[0] = p;
    F1[1] = 2LL*(p*q%mod)%mod;
    F1[2] = q;
    F1[3] = ((q*q%mod) - (p*p%mod))%mod;

    
    T[0][0] = 0, T[0][1] = 1, T[0][2] = 0, T[0][3] = 0;
    T[1][0] = 0, T[1][1] = q, T[1][2] = 0, T[1][3] = p;
    T[2][0] = 0, T[2][1] = 0, T[2][2] = 0, T[2][3] = 1;
    T[3][0] = 0, T[3][1] = -p,T[3][2] = 0, T[3][3] = q;

  
    if (N == 1){
        x = p;
        y = q;
        return;
    }
    T = pow(T, N-1);

    x=y=0;
    
    f(i,0,K){
        x = (x + T[0][i] * F1[i])% mod;
        y = (y + T[2][i] * F1[i])% mod;
    }
}

int main(){
	fast(); 
	ll n,p,q,t,ans;

	sl(t)
	

	while(t--){

		sl(p) sl(q) sl(n)

		fib(p,q,n);
		
		if(x<0) x += mod;
		if(y<0) y += mod;

		y  = power(y,mod - 2,mod);
		ans = (x*y)%mod;
		pl(ans);

	}
	trace(TimeElapsed)
	
}  
