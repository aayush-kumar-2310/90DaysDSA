#include<bits/stdc++.h>
using namespace std;

void print(int n) {
    
    if( n >= 0){
        print(n-1);
        cout<<n<<endl;
    }
    return;
}

int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    print(n);

    return 0;
}