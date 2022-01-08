#include <bits/stdc++.h>
using namespace std;
#define pi (3.141592653589)
#define mod 1000000007
#define int long long
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int n, x, y;

bool isGood(int t){

    if(t < min(x,y)) return false;
    t -= min(x,y);
    if((t/x) + (t/y) +1>=n) 
        return true;
    else
        return false;
}

bool isPrime(int n){
    if(n==1) return false;
    if(n==2) return true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}

int32_t main(){
    fast


    // I'll be there 1 day
    // 1 DAY :)


    int t=1;
    //cin>>t;
    while(t--){

        cin>>n>>x>>y;

        int l=0, r=n*min(x,y);

        while(l+1<r){
            int mid = l+(r-l)/2;
            if(isGood(mid))
                r=mid;
            else
                l=mid;
        }
        cout<<r;
    }
    return 0;
}
