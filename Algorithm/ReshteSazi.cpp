#include <iostream>
#include <string>
using namespace std;
int main(){
    string s = "1";
    int l, r;
    cin >> l >> r;
    while (s.size() < r){
        string t = "";
        for (int i = 0;i<s.size();i++){
            if (s[i] == '0'){
                t+='1';
            }
            else{
                t+='0';
            }
        }
        s+=t;
    }
    for (int i = l-1;i <= r-1;i++){
        cout << s[i];
    }
    cout << endl;
    return 0;
}