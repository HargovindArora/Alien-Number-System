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

string succ_alien(string n, string b){

    int length = n.size()-1, base = b.size();

    vector<int> num = getNumFromString(n, b, length, base);

    incrementBy1(num, length, base);

    string result = convertNumToString(num, b);

    return result;
}

void testCodeForMultipleInputs(){

    string s1 = "!@^&*", s2 = "!@#^*&";
    string b1 = "!@^&*", b2 = "!@#^&*";

    string ans1 = "!@^*!", ans2 = "!@#^**";

    bool test1, test2;
    
    test1 = ans1 == succ_alien(s1, b1);
    test2 = ans2 == succ_alien(s2, b2);

    cout << test1 << " " << test2 << endl;

    return;
}

int main(){

    string mode;
    cout << "Please enter `test` to test the code, otherwise any character to use the code" << endl;
    cin >> mode;

    if(mode=="test"){
        testCodeForMultipleInputs();
    }
    else{
        string s, b;
        cin >> s >> b;

        cout << succ_alien(s, b) << endl;
    }

    return 0;
}