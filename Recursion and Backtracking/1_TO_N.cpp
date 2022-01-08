#include<bits/stdc++.h>
using namespace std;

void count(int n){

    if(n < 1)
        return;

    count(n-1);
    cout<<n<<" ";
}
int main(){

    int n;
    cin>>n;

    count(n);
}