#include<bits/stdc++.h>
using namespace std;

int main()
{

    string str = "forxxorfxdofr", pat = "for";
    vector<int> stringHash(26,0), patHash(26,0);

    for(int i = 0; i<pat.size(); i++)
        patHash[ pat[i] - 97 ] += 1;

    int p1 = 0, p2 = 0, ans = 0;

    while( p2 < str.size() ){

        if(p2-p1 != pat.size()-1){
            stringHash[str[p2] - 97]++;
            p2++;
        }

        else{
            stringHash[str[p2] - 97]++;

            if(stringHash == patHash){
                ans++;
            }    

            stringHash[str[p1] - 97]--;
            p1++;
            p2++;    
        }
    }
    cout<<ans;
    
}