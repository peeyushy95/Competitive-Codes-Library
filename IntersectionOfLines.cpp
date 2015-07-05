/*
   AUTHOR  : Peeyush Yadav
   Problem : 
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
          //freopen("out.txt","w",stdout);
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

//Taken From geeks4geeks.com, http://www.dcs.gla.ac.uk/~pat/52233/slides/Geometry1x1.pdf
struct Point{
    ll x,y;
};
 
// Given three colinear points p, q, r, the function checks if point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r){
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
		return true; 
    
	return false;
}
 
// To find orientation of ordered triplet (p, q, r). return  0 --> p, q and r are colinear, 1 --> Clockwise , 2 --> Counterclockwise
ll orientation(Point p, Point q, Point r){
    
    ll val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear

    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
bool doIntersect(Point p1, Point q1, Point p2, Point q2){
	
	
    // Find the four orientations needed for general and special cases
    ll o1 = orientation(p1, q1, p2);
    ll o2 = orientation(p1, q1, q2);
    ll o3 = orientation(p2, q2, p1);
    ll o4 = orientation(p2, q2, q1);
 
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
 
    // Special Cases
    // 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;				// p1, q1 and p2 are colinear and p2 lies on segment p1q1 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;				// p1, q1 and p2 are colinear and q2 lies on segment p1q1    
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;				// p2, q2 and p1 are colinear and p1 lies on segment p2q2     
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;				// p2, q2 and q1 are colinear and q1 lies on segment p2q2
 
    return false; 													// Doesn't fall in any of the above cases
}


int main(){
	input();
	
	int t;
	s(t);
	
	struct Point p1,q1,p2={0,0},q2;
	while(t--){
		sl(p1.x);
		sl(p1.y);
		sl(q1.x);
		sl(q1.y);
		sl(q2.x);
		sl(q2.y);
		doIntersect(p1, q1, p2, q2)? cout << "NO\n": cout << "YES\n";
	}
	
	
	#ifdef Megamind
		cout << "\nTime elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
    #endif
}
