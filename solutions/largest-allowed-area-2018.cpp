#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <cstring>
#include <cmath>
#define DETERMINATION main
#define lldin(a) scanf("%lld",&a)
#define din(a) scanf("%d",&a)
#define printlnlld(a) printf("%lld\n",a)
#define printlnd(a) printf("%d\n",a)
#define printlld(a) printf("%lld",a)
#define printd(a) printf("%d",a)
#define reset(a,b) memset(a,b,sizeof(a))
const int INF=0x3f3f3f3f;
using namespace std;
const double PI=acos(-1);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int mod=1000000007;
const int tool_const=1999112620000907;
const int tool_const2=33;
inline ll lldcin()
{
    ll tmp=0,si=1;char c=getchar();
    while(c>'9'||c<'0')
    {
        if(c=='-')
            si=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        tmp=tmp*10+c-'0';
        c=getchar();
    }
    return si*tmp;
}
///Schlacht von Stalingrad
/**Although there will be many obstructs ahead,
the desire for victory still fills you with determination..**/
ll sum[1050][1050];
int DETERMINATION()
{
    ll t;
    t=lldcin();
    while(t--)
    {
        reset(sum,0);
        ll r,c;
        r=lldcin(),c=lldcin();
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
            {
                ll tmp;
                tmp=lldcin();
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+tmp;
            }
//        cout<<endl;
//        for(int i=1;i<=r;i++)
//        {
//            for(int j=1;j<=c;j++)
//                cout<<sum[i][j]<<" ";
//          cout<<endl;
//        }
        ll ans=-1;
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
            {
                ll left=1,right=min(i,j);
                while(left<=right)
                {
                    ll mid=(left+right)>>1;
                    if(sum[i][j]+sum[i-mid][j-mid]-sum[i-mid][j]-sum[i][j-mid]<=1)
                    {
                        ans=max(ans,mid);
                        left=mid+1;
                    }
                    else
                        right=mid-1;
                }
            }
        printlnlld(ans);
    }
    return 0;
}
