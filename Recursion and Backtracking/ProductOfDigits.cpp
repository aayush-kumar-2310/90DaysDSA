#include<bits/stdc++.h>
using namespace std;

unsigned long long DigitProd(int n){

    if(n/10 == 0)
        return n;

    return (n%10) * DigitProd(n/10);
}

int main(){

    int n;
    cin>>n;

    cout<<DigitProd(n);
    return 0;
}