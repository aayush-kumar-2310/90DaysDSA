#include<bits/stdc++.h>
using namespace std;

long RevNum(long n, int digits){

    if(n == 0)
        return n;

    return (n%10) * pow(10, digits-1) + RevNum(n/10, digits - 1);
}

bool palindrome(long &n, int &digits){

    return (n == RevNum(n, digits));
}


int main(){

    long n;
    cin>>n;
    int digits = log10(n) + 1;
    cout<<palindrome(n, digits);

}