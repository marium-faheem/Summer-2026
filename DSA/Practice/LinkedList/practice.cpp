#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int streak=1;
    int best = 1;
    for(int i=1 ; i<s.size() ; i++){
        if(s[i] == s[i-1]) streak++;
        else streak = 1;
        if(streak>best) best = streak;
    }
    cout<< best;
    return 0;
}