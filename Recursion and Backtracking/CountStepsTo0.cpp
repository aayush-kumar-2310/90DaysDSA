#include<bits/stdc++.h>
using namespace std;

int CountSteps(int n, int cnt){

    if(n == 0)
        return cnt;

    if(n%2 == 0)
        return CountSteps(n/2, cnt+1);

    else
        return CountSteps(n-1, cnt+1);

}

int fun(int num){

    return CountSteps(num, 0);
}

int main(){

    int n, cnt = 0;
    cin>>n;

    cout<<fun(n);
}