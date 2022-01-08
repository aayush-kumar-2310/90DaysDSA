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
int n, k; 
int arr[10001];
bool isPrime(int n){
    if(n==1) return false;
    if(n==2) return true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}

bool isGood(float x){

    int s = 0;
    for(int i=0; i<n; i++)
        s += floor(arr[i]/x);

    if(s>=k)
        return true;
    else
        return false;
}

int32_t main(){
    fast


    // I'll be there 1 day
    // 1 DAY :)


    int t=1;
    //cin>>t;
    while(t--){

        cin>>n>>k;

        for(int i=0; i<n; i++)
            cin>>arr[i];

        float l=0, r=1e8;
        for(int i=0; i<100; i++){
            float mid = l + (r-l)/2;

            if(isGood(mid))
                l=mid;
            else
                r=mid;
        }
        cout<<setprecision(20)<<l;
    }
    return 0;
}
