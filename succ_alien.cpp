#include<iostream>
#include<vector>

using namespace std;

void succ_alien(string n, string b){

    int length = n.size()-1;
    vector<int> num;
    for(int i=0; i<=length; i++){
        char c = n[i];
        for(int j=0; j<b.size(); j++){
            if (c==b[j]){
                num.emplace_back(j);
            }
        }
    }
    int carry = 1;

    for(int i=length; i>=0; i--){
        if((carry+num[i])%b.size()==0){
            num[i]=0;
        }
        else{
            num[i] = num[i]+1;
            carry = 0;
            break;
        }
    }

    string result = "";

    for(int i=0; i<=length; i++){
        result += b[num[i]];
    }

    cout << result << endl;
}

int main(){

    string s;
    cin >> s;

    string b = "!@^&*";

    succ_alien(s, b);

    return 0;
}