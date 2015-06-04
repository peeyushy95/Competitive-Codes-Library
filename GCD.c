/*

   AUTHOR: Peeyush yadav
   Problem: http://www.codechef.com/DEC14/problems/SEAGCD
   
*/
 
#include<stdio.h>

 
long long power(long long a,long long b,long long mod){
    if(b==0) return 1%mod;
    if(b==1) return a%mod;
    if(b%2 == 0){
        long long temp = power(a,b/2,mod);
        return (temp*temp)%mod;
    }
    else{
        long long temp = power(a,b/2,mod);
        temp = (temp*temp)%mod;
        return (temp*a)%mod;
    }
}
/*........................................................END OF TEMPLATES.......................................................................*/
 
long long a[3164],b[3164],modu=1e9+7;
 
 
void solve(int n,int m,int l,int r){                                        // computing combination 4 each in range[l,r]
        int sq=1,i,j,l1;
        long long ans=0;
 
        while(sq*sq<m) sq++;                        // square root of m
        sq--;
 
        int s,e=m;
                                                    // while i<sq   (m/i)-(m/(i+1)) > 1
        for(i=1;i<sq;i++){                         // for any gcd in (m/i,m/(i+1)] no. of combination are same.. eg. : (n/2,n] combination =1;
            s=m/i;
            e=m/(i+1);
 
                                                                                        // computing result for any number in range (m/i,m/(i+1)]
            a[m/s]=power((long long)m/s,(long long)n,modu);
            for(j=2*s;j<=m;j+=s){
                a[m/s]-=a[m/j];
                if(a[m/s]<0) a[m/s]+=modu;
            }
        }
                                            // Now result should be stored for each index(gcd) in (m/i,m/(i+1)] .. bt 4 this array of 1e7 size required
                                            // memory required can be reduced ....result is stored in a[m/s] only... representing each no. (m/i,m/(i+1)]
 
        for(i=e;i>=l;i--){                  // gcd combinations in [l,e]
            b[i]=power((long long)m/i,(long long)n,modu);
            for(j=2*i;j<=m;j+=i) {
                    if(j>e)  b[i]-=a[m/j];
                    else     b[i]-=b[j];
 
                    if(b[i]<0) b[i]+=modu;
            }
            ans=(ans+b[i])%modu;            // ans =  gcd combination in [l,e]
        }
        l1=(e+1>l)?(e+1):l;                 // ans+= gcd combin. [max(e+1,l),r]
        for(i=l1;i<r+1;i++)
            ans=(ans+a[m/i])%modu;
 
 
        printf("%lld\n",ans);
}
 
 
int main(){

    int t,n,m,l,r;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&m,&l,&r);
        solve(n,m,l,r);
    }
 
 
return 0;
}
 
