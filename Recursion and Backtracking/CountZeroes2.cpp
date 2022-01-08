#include<bits/stdc++.h>
using namespace std;

int CountZeroes(long n, int cnt){

    if(n == 0)
        return cnt;

    if(n%10 == 0)
        return CountZeroes(n/10, cnt+1);

    else
        return CountZeroes(n/10, cnt);

}

int main(){

    long int n;
    cin>>n;

    cout<<CountZeroes(n, 0);
}