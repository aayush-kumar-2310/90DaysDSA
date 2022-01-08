#include<bits/stdc++.h>
using namespace std;

unsigned long long numsum(int n){

    if(n == 1)
        return 1;

    return n+numsum(n-1);
}
int main(){

    int n;
    cin>>n;

    cout<<numsum(n);
}