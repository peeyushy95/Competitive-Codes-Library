/*
   AUTHOR  : Peeyush Yadav
   Problem : Running Median(Insertion/Deletion)
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
#define sz 112345
int a[sz];

multiset<int> mini,maxi;  
multiset<int> :: iterator it1,it2;
 
inline void insert1(int val){
	
	if(mini.empty()) mini.insert(val);
	else if(mini.size() == maxi.size()){
		maxi.insert(val);
		mini.insert(*maxi.begin());
		maxi.erase(maxi.begin());
	}
	else{
		mini.insert(val);
		maxi.insert(*mini.rbegin());
		mini.erase(mini.find(*mini.rbegin()));
	}	
}
 
inline void delete1(int val){
	
	it1 = mini.find(val);
	it2 = maxi.find(val);
	
	if(mini.size() == maxi.size()){
		
		if(it1 != mini.end()){
			mini.erase(it1);
			mini.insert(*maxi.begin());
			maxi.erase(maxi.begin());
		}
		else  maxi.erase(it2);
	}
	else if(it2 != maxi.end()) {
		maxi.erase(it2);
		maxi.insert(*mini.rbegin());
		mini.erase(mini.find(*mini.rbegin()));
	}
	else mini.erase(it1);
}

 
int main(){
	input();
	int v,n;
	s(n)
	
	f(i,0,n) {							//Supports Insertion/Deletion Both
		s(v);
		insert1(v);
		if(mini.size() == maxi.size())  p((*mini.rbegin() + *maxi.begin())/2)
		else							p(*mini.rbegin());
	}
	
	
	#ifdef Megamind
		cout << "\nTime elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
    #endif
}
