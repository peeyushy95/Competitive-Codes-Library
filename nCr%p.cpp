/*
   AUTHOR: Peeyush yadav
   Problem: http://www.spoj.com/problems/AJOB/
*/

#include<bits/stdc++.h>
using namespace std;
#define f(a,b,c) for(int a=b;a<c;a++)
#define s(x) scanf("%d",&x);
#define sl(x) scanf("%lld",&x);
#define p(x) printf("%d\n",x);
#define pl(x) printf("%lld\n",x);
#define p1d(a,n) for(int ee=0;ee<n;ee++) printf("%d ",a[ee]); printf("\n");
#define ld long double
#define maxn 1000000 + 5
map <int ,int > mymap;
set <int> myset;
map <int,int> :: iterator it;
set <int> :: iterator it1,it3;
vector <int> v;
vector <int> :: iterator itv;
typedef long long ll;

void input(){
     #ifndef ONLINE_JUDGE
        #   define DEBUG
        #   define TRACE
        freopen("inp.txt","r",stdin);
     #endif
}

#ifdef TRACE
    #define trace(x)            cerr<<x<<endl;
    #define trace1(x)           cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
    #define trace2(x,y)         cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
    #define trace3(x,y,z)       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
    #define trace4(a,b,c,d)     cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<endl;
    #define trace5(a,b,c,d,e)   cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<endl;
    #define trace6(a,b,c,d,e,f) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<" | "#f" = "<<f<<endl;
#else
    #define trace(x)
    #define trace1(x)
    #define trace2(x,y)
    #define trace3(x,y,z)
    #define trace4(a,b,c,d)
    #define trace5(a,b,c,d,e)
    #define trace6(a,b,c,d,e,f)
#endif

ll power(ll a, ll b, ll c)
{
    if(b==0) return 1%c;
    if(b==1) return a%c;
    if(b%2 == 0){
        ll temp = power(a,b/2,c);
        return (temp*temp)%c;
    }
    else{
        ll temp = power(a,b/2,c);
        temp = (temp*temp)%c;
        return (temp*a)%c;
    }
}
ll power1(ll a, ll b)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2 == 0){
        ll temp = power1(a,b/2);
        return (temp*temp);
    }
    else{
        ll temp = power1(a,b/2);
        temp = (temp*temp);
        return (temp*a);
    }
}
/*........................................................END OF TEMPLATES.......................................................................*/
ll mod;


ll facmod(ll n){                                                          // refer : http://e-maxx.ru/algo/modular_factorial
        ll val =1;                                                       // computing (n!)%mod by manipulating multiples of mod i.e
                                                                        // mod -> 1, 2*mod ->2, (mod-1)*mod->mod-1, mod*mod -> 1(repeat).... so on
                                                                       //  reason is they will b eliminated by multiples of mod in denominator
        while(n > 1){                                                 // used  William's Theorem ((p-1)!)%p= p-1  (EQ-1) ... ((p-1)^2)%p = 1
                                                                     // n/mod denotes number of blocks of length mod... if n/mod is multiple of 2
            val = ( val * ((n/mod)%2 ? mod - 1 : 1))%mod;           // then (mod-1) will b present even no. of times.. so result =1 (((p-1)^2)%p = 1)
                                                                   // else there will be one (mod - 1) present
            for(ll i = 2;i<=(n%mod);i++) val= (val * i)%mod;     // if(n%mod) i.e some blocks of length < mod.. so there result will b computed independently
            n /= mod;
        }
        return val%mod;
}

ll solve(ll n, ll r){
    ll countp = 0,temp = n, p = mod;                                                // countp contains number of mod in numerator - denominator
    while(temp/p){                                                                  // no. of mod in numerator
        countp += temp/p;
        p*=mod;
    }

    temp = r, p = mod;
    while(temp/p){                                                                  // no. of mod in denominator(r part)
        countp -= temp/p;
        p*=mod;
    }

    temp = n-r, p = mod;
    while(temp/p){                                                                  // no. of mod in denominator ((n-r) part)
        countp -= temp/p;
        p*=mod;
    }

    if(countp > 0) return 0;                                                        // if countp > 0 then "mod(multiples also)" will b in final result
                                                                                    // thus finalresult % mod = 0
    ll num = facmod(n), den = facmod(r);                                            // facmod(x) computes (x!)%mod removes d cases of "mod((multiples also))"
    den *= facmod(n - r);
    den %= mod;

    ll invden = power(den, mod - 2, mod);                                           // inverse of denominator (gcd(den, mod) = 1) bcz
                                                                                    // we have removed mod(multiples also) in den
    return (num * invden)%mod;                                                      // final result -> num * inverse of den.
}

int main(){
    input();
    int t;
    s(t);
    while(t--){
       ll n,k;
       sl(n);
       sl(k);
       sl(mod);
       pl(solve(n+1,n-k));                                                  //	(N+1)C(N-K) = (K)C(0) + (K+1)C(1) + ...... (N)C(N-K)

    }
return 0;
}

