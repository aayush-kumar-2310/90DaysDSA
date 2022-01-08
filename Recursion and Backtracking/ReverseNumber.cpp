#include<bits/stdc++.h>
using namespace std;

long sum = 0;
void RevNum(long n){
    if(n == 0){
        return;
    }
    sum = (sum*10) + (n%10);
    RevNum(n/10);
}

int main(){

    long n;
    cin>>n;

    RevNum(n);
    cout<<sum;
}