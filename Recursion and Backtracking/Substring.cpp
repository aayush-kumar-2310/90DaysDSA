#include<bits/stdc++.h>
using namespace std;

void generate(string s1, string s2, int i){

    if(i == s1.length()){
        cout<<"\""<<s2<<"\", ";
        return;
    }

    generate(s1, s2, i+1);
    s2.push_back(s1[i]);
    generate(s1, s2, i+1);
}

int main(){

    string s;
    generate("abc", s, 0);
}