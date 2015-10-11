        /*
           AUTHOR  : Peeyush Yadav
           Problem : https://www.codechef.com/SEPT15/problems/REBXOR
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
        	
        	#define fi 						first
        	#define se 						second
        	#define mp 						make_pair
        	#define pb(x) 					push_back(x)
        	#define s(x)                    scanf("%d",&x);
        	#define sl(x)                   scanf("%lld",&x);
        	#define p(x)                    printf("%d\n",x);
        	#define f(a,b,c)                for(int a=b;a<c;a++)
        	#define r(a,b,c)				for(int a=b;a>c;a--)
        	#define p2(x,y)                 printf("%d %d\n",x,y);
        	#define pl(x)                   printf("%lld\n",x);
        	#define pl2(x,y)                printf("%lld %lld\n",x,y);
        	#define p1d(a,n)                for(int ix=0;ix<n;ix++) printf("%d ",a[ix]); printf("\n");
        	#define p2d(a,n,m)              for(int ix=0;ix<n;ix++){ for(int jx=0;jx<m;jx++) printf("%d ",a[ix][jx]); printf("\n");}
        }
        /*........................................................END OF TEMPLATES.......................................................................*/
        #define sz1 100000001
        #define sz  412345
        #define eps 1e-9
        int a[sz],f[sz],b[sz],po[34];
         
         
         
        struct node{
            node * zero,* one;
        }*trie ;
         
        inline void  insert (node * x, int bits, int pos){
           
        	if (pos==-1) return;
            if ((1<<pos)&bits){
                if (x->one==NULL){
        			x->one=(struct node *) malloc(sizeof(struct node));
        			x->one->one = NULL;
        			x->one->zero = NULL;
        		}
                insert(x->one, bits, pos-1);
            }
            else{
                if (x->zero==NULL) {
        			x->zero=(struct node *) malloc(sizeof(struct node));
        			x->zero->one = NULL;
        			x->zero->zero = NULL;
        		}
                insert(x->zero, bits, pos-1);
            }
        	
        }
         
        inline int query (node * t, int a, int pos){
          
          if (pos==-1) return 0;
          if ((1<<pos)&a){
              if (t->zero==NULL)	 return query (t->one, a, pos-1);
              else					 return po[pos] + query(t->zero, a, pos-1);
          }
          else {
              if (t->one==NULL)		 return query(t->zero, a, pos-1);  
              else					 return po[pos] + query(t->one, a, pos-1);
          } 
         
        }
         
        int main(){
        	fast();
        	int t,n,xr=0,maxxor=0;
        	s(n)
        	
        	po[0] = 1;
        	f(i,1,32) po[i] = po[i-1]*2;
        	
        	trie = (struct node *) malloc(sizeof(struct node));
        	trie->one = NULL;
        	trie->zero = NULL;
        	f(i,0,n) s(a[i]);
        	
        	insert(trie,0,29);
        	insert(trie,a[0],29);
        	
        	
        	f[0] = a[0];	
        	b[n-1] = a[n-1];
        	xr = a[0];
        	f(i,1,n){
        		xr = xr ^ a[i];
        		insert(trie,xr,29);
        		f[i] = max(f[i-1], query(trie,xr,29));
        	}
        	
        	trie->one = NULL;
        	trie->zero = NULL;
        	
        	insert(trie,0,29);
        	insert(trie,a[n-1],29);
        	xr = a[n-1];
        	r(i,n-2,-1){
        		xr = xr ^ a[i];
        		insert(trie,xr,29);
        		b[i] = max(b[i+1], query(trie,xr,29));
        	}
        	int ans = 0;
        	
        	//p1d(f,n)
        	//p1d(b,n)
        	
        	f(i,1,n)	if(f[i-1] + b[i] > ans) ans = f[i-1] + b[i];
        	
        	
        	p(ans)
        	#ifdef Megamind
        		cerr << "\nTime elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
        	#endif
        }   
