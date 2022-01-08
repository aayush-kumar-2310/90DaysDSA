#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

void CountNum(long n){

    if(n == 0)
        return;

    if((n%10) == 0)
        cnt++;
    
    CountNum(n/10);
}

int main(){

    int n;
    cin>>n;

    CountNum(n);
    cout<<cnt;

}