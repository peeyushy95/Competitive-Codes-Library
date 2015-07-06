/*
   AUTHOR  : Peeyush Yadav
   Problem : http://codeforces.com/contest/1/problem/B
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
          //  freopen("out.txt","w",stdout);
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

int main(){
	input();
	int t;
	
	s(t);
	char inp[30];
	string ans;
	while(t--){
		scanf("%s",inp);
		ans="";
		int len = 0;
		bool flag = 0;
		if(inp[0] ==  'R') {
			if(inp[1] >='0' && inp[1] <='9'){
				f(i,2,strlen(inp))
					if(inp[i]=='C') flag = 1;
			
			}
		}
		if(flag){
				
				int len = strlen(inp),numlen = 1,num=0,off=1;
				int i =0;
				
				while(inp[i] != 'C') i++;
				f(x,i+1,len) num = num*10 + inp[x] - '0';
				
				
				while(off*26 < num) {
					off*=26;
					num -= off;
					numlen++;
				}
				num--;
				//trace2(num,numlen)
				f(i,0,numlen){
					off = 1;
					f(j,1,numlen-i) off*=26;
					ans += 'A' + (num/off);
					num -= (num/off)*off;
				}
				i=1;
				while(inp[i] != 'C') {
					ans+=inp[i];
					i++;
				}
		}
		else{
			ans+='R';
			
			f(i,0,strlen(inp))
				if(inp[i]>='0' && inp[i] <= '9') ans+=inp[i];
				else 							 len = i;
			ans+='C';
			int outputval = (26*(power(26,len)-1))/25;
			
			//trace(outputval)
			
			f(i,0,len) {
				outputval += (inp[i]-'A')*power(26,len-i);
			//	trace(outputval)
			}
			
		//	trace(outputval)
			
			outputval += inp[len] - 'A' + 1;
			string temp = "";
			while(outputval){
				
				temp+= (outputval%10) + '0';
				outputval/=10;
			}
			
			reverse(temp.begin(),temp.end());
			ans+=temp;
			
		}
		
		cout<<ans<<endl;
	}
	
	#ifdef Megamind
		cout << "\nTime elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
    #endif
}
