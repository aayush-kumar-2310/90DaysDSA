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

float c;

bool isGood(float x){
    if((x*x) + sqrt(x) >= c)
        return true;

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
        
        cin>>c;
        float l = 0, r=c;

        for(int i=0; i<100; i++){
            float m = l+(r-l)/2;

            if(isGood(m))
                r=m;
            else
                l=m;
        }
        cout<<setprecision(10)<<l;
    }
    return 0;
}
