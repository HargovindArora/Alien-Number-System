#include<iostream>
#include<vector>

using namespace std;

vector<int> getNumFromString(string n, string b, int length, int base){

    vector<int> num;

    for(char c: n){
        for(int j=0; j<base; j++){
            if (c==b[j]){
                num.emplace_back(j);
                break;
            }
        }
    }

    return num;
}

void incrementBy1(vector<int> &num, int length, int base){

    int carry = 1;

    for(int i=length; i>=0; i--){
        if((carry+num[i])%base==0){
            num[i]=0;
        }
        else{
            num[i] = num[i]+1;
            carry = 0;
            break;
        }
    }

    return;
}

string convertNumToString(vector<int> &num, string b){

    string result = "";

    for(int n: num){
        result += b[n];
    }

    return result;
}

void succ_alien(string n, string b){

    int length = n.size()-1, base = b.size();

    vector<int> num = getNumFromString(n, b, length, base);

    incrementBy1(num, length, base);

    string result = convertNumToString(num, b);

    cout << result << endl;

    return;
}

int main(){

    string s;
    cin >> s;

    string b = "!@^&*";

    succ_alien(s, b);

    return 0;
}