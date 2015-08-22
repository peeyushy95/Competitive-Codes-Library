    /*
    AUTHOR: Peeyush yadav
    Problem: http://www.codechef.com/NOV14/problems/POWERMUL
    */
     
    #include<bits/stdc++.h>
    using namespace std;
    #define f(a,b,c) for(int a=b;a<c;a++)
    #define s(x) scanf("%d",&x);
    #define s2(x,y) scanf("%d%d",&x,&y);
    #define sl(x) scanf("%lld",&x);
    #define sl2(x,y) scanf("%lld%lld",&x,&y);
    #define p(x) printf("%d\n",x);
    #define pl(x) printf("%lld\n",x);
    #define p1d(a,n) for(int _i=0;_i<n;_i++) printf("%d ",a[_i]); printf("\n");
    #define p2d(a,n,m) for(int _i=0;_i<n;_i++){ for(int _j=0;_j<m;_j++) printf("%d ",a[_i][_j]); printf("\n");}
     
    typedef long long ll;
     
    void input(){
    #ifndef ONLINE_JUDGE
    #define DEBUG
    #define TRACE
    #define gc getchar
    freopen("inp.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    #else
    #define gc getchar_unlocked
    #endif
    }
     
    #ifdef TRACE
    #define trace1(x) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
    #define trace2(x,y) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
    #define trace3(x,y,z) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
    #else
    #define trace1(x)
    #define trace2(x,y)
    #define trace3(x,y,z)
    #endif
     
    template <class T>
    inline void read(T &n){
     
    n=0;
    char c=gc();
    while( c<=32 ) c =gc();
    while( c>32 ){
    n=(n<<3) + (n<<1) + c - 48;
    c=gc();
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
    #define MAX 100000 + 5
    bool a[32000];
    int pcount=0, phi, m_prime[11], m_ppower[11],m_counter=0,m,n;
    ll prefix[MAX];
    ll countpower[MAX][11];
    vector <int> prime;
     
    inline void call_karo_seive(){ // generate Primes upto 32000
		f(i,2,32000)
		if(!a[i]){
			prime.push_back(i);
			for(int j = i+i; j <= 32000; j += i) a[j] = true;
		}
    }
     
    inline void calc_phi(){ // calculate Euler Totient => phi , prime factors in current m => m_prime , count of prime factor =>m_ppower
		phi = m;
		int temp = m,counter=0;
		m_counter=0;
		for(int i=2; i*i <= temp; i = prime[++counter]){
			if(temp % i == 0){
				phi/=i;
				phi*=(i-1);
				while(temp%i == 0){
					temp/=i;
				}
				 
				m_prime[m_counter++]=i;
			}
		}
		if(temp>1){
			phi/=temp;
			phi*=temp-1;
			m_prime[m_counter++]=temp;
		}
     
    }
     
    inline ll check(int num){ // removing factors of prime present in m from num
		ll x = num;
		 
		for(int i=0;i<11;i++) countpower[x][i]=0;
		for(int i=0; i<m_counter; i++){
			int val = m_prime[i];
			while( num%val == 0){
				num/=val;
				countpower[x][i]++;
				}
		}
		for(int i =0 ; i < m_counter; i++) //prefix computation of power of prime (present in m ) in X;
		countpower[x][i] =countpower[x][i]*x + countpower[x-1][i];
		 
		return power(num,x,m);
    }
     
    inline void pre(){ // prefix multiplication without any multiples of prime factors in "m"
		prefix[1]=1;
		f(i,2,n+1){
			prefix[i]=(prefix[i-1]*check(i))%m;
		}
	}
		 
	ll ans_plz(int r){
		ll ans = ((prefix[n]*power(prefix[n-r], phi - 1, m)%m )* power(prefix[r], phi - 1, m))%m; //modular inverse
		for(int i = 0; i< m_counter; i++){
			ll finalpow = countpower[n][i] - countpower[n-r][i] - countpower[r][i]; //computing p^(x-y-z) for each p in m
			ans = (ans * power(m_prime[i],finalpow,m))%m;
		}
		return ans;
    }
     
    int main(){
     
		input();
		int t;
		read(t);
		call_karo_seive();
		pcount = prime.size();
		while(t--){
			int q;
			read(n);
			read(m);
			 
			calc_phi();
			//trace2(phi,m_counter);
			//p1d(m_prime,m_counter);
			pre();
			read(q);
			while(q--){
				int r;
				read(r);
				//trace1(r);
				pl(ans_plz(r));
			}
		}
     
    }
