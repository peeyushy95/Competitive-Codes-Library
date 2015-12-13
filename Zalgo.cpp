/*
   (•_•)
   <) )>
    / \
   AUTHOR  : Peeyush Yadav {*_-}
   Problem : Z-Algorithm
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
}
/*........................................................END OF TEMPLATES.......................................................................*/

bool ZAlgo(string pattern , string text){

	string s = pattern + '$' + text;
	int goal = pattern.length(),n = s.length();
	vector <int> z(n,0);
	int l=0,r=0;
	
	f(k,1,n){
		
		if(k > r){
			int i = k;
			while (i < n && s[i] == s[i - k]) i++;

			if(i > k){
				z[k] = i - k;
				l = k;
				r = i - 1;
			}
		}
		else{
			int offset = k - l , diff = r - k + 1;

			if(z[offset] > diff){

				int i = r + 1;
				while(i < n && s[i] == s[i - k]) i++;
				
				z[k] = i - k;
				l = k;
				r = i - 1;
			}

		}

		if(goal == z[k]) return true;
	} 

	return false;
}


int main(){
	fast(); 
	string pattern,text;
	cin>>pattern>>text;

	if(ZAlgo(pattern , text)) puts("Patten Found");
	else 					  puts("Pattern Not Found");

	#ifdef Megamind
		cerr << "\nTime elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
	#endif
}  
