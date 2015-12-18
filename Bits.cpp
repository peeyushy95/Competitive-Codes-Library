/* 
   AUTHOR: Peeyush yadav (~_~)
   Problem: Bits
*/

#include<bits/stdc++.h>
#define f(a,b,c) for(int a=b;a<c;a++)
#define s(x) scanf("%d",&x);
#define sl(x) scanf("%lld",&x);
#define p(x) printf("%d\n",x);
#define pl(x) printf("%lld\n",x);
#define maxn 1000000 + 5
using namespace std;
typedef long long ll;
ll m;
void input(){
     #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
     #endif
}
ll power(ll a, ll b, ll c)
{
    if(b==0)
        return 1;
    if(b==1)
        return a%c;
    if(b%2 == 0)
    {
        ll temp = power(a,b/2,c);
        return (temp*temp)%c;
    }
    else
    {
        ll temp = power(a,b/2,c);
        temp = (temp*temp)%c;
        return (temp*a)%c;
    }
}
/*........................................................END OF TEMPLATES.......................................................................*/



int main(){
    input();
    ll n,a,b,m,t,x,y;
    cin>>t;
    while(t--){
       cin>>a>>b;
       ll ans=0;
       while(a || b){                                             // remove sets bits bits one by one
            x=a;y=b;m=0;n=0;
            while(x) x>>=1,m++;                                          // counting number of bits in number
            while(y) y>>=1,n++;                                          // m,n will give most significant bit
            //m=log2(a)+1; n=log2(b)+1;                                  // log giving wrong answer for large number
            if(m==n){                                             // if number of bits is same then any number[l,r] will have that bits so add
                ll y=1LL<<(m-1);                                  // it to the answer and remove that bit
                ans+=y;
                a-=y;
                b-=y;
            }
            else if(n>m){                                        // if no. of bit in "b" is more then
                ll x=b+1;
                if(!(x&(x-1))) ans+=b;                              // 1:) all bits of b are set add it to answer.no need to see a,b further
                                                                    // eg :  [1011,11111]
                else ans+=(1LL<<(n-1))-1LL;                         // 2:) whatever be "a" .range b/w (a,b) contain the number with all "(n-1) bits" set
                break;                                              //  eg:   [10111,101111] ans= 111111
            }
        }
        cout<<ans<<endl;
    }
return 0;
}

