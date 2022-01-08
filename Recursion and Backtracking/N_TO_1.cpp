#include<bits/stdc++.h>
using namespace std;

void count(int n){

    if(n == 1){
        cout<<1;
        return;
    }

    cout<<n<<" ";
    count(n-1);
}

int main() {
    
    int n;
    cin>>n;
    count(n);
}