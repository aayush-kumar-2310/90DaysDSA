#include<bits/stdc++.h>
using namespace std;

void FindSubset(string &s, string &ans, int i, vector<string> &v){

    if(i == s.length()){
        v.push_back(ans);
        return;
    }

    ans.push_back(s[i]);
    FindSubset(s, ans, i+1, v);
    ans.pop_back();
    FindSubset(s, ans, i+1, v);
}

int main(){

    vector<string> s;
    string a = "abc";
    string ans;
    FindSubset(a, ans, 0, s);
    
    sort(s.begin(), s.end());
    
    for( auto x:s)
        cout<<x<<endl;

}