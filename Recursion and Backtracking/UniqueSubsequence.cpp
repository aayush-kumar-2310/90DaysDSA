#include<bits/stdc++.h>
using namespace std;

void generate (string s1, string s2, unordered_set<string> &st, int i){

    if(i == s1.length()){
        st.insert(s2);
        return;
    }

    generate(s1, s2, st, i+1);
    s2.push_back(s1[i]);
    generate(s1, s2, st, i+1);
}

int main(){
    unordered_set<string> st;
    string s;
    generate("aab", s, st, 0);

    for( auto it: st){
        cout<<it<<" ";
    }
}