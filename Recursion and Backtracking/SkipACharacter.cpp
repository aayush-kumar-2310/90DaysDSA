#include<bits/stdc++.h>
using namespace std;

string SkipChar(string Org){

    if(Org.length() <= 0)
        return "";

    // string tmp;
    // tmp.push_back(Org[i]);

    if(Org[Org.length()-1] == 'a'){
        Org.pop_back();
        return SkipChar(Org);
                
    }

    else{
        char tmp = Org[Org.length()-1];
        Org.pop_back();
        return (SkipChar(Org) + tmp);

    }
}

int main(){

    cout<<SkipChar("baccdah");
}