#include<iostream>
#include<vector>
#include<map>

using namespace std;

// A function to map the characters in the base string to
// their corresponding int values and store it in a hashmap
// to make operations efficient
void getMappingOfBaseChars(string b, int base, map<char, int> &strToInt){

    for(int i=0; i<base; i++){
        strToInt[b[i]] = i;
    }

    return;
}

// A function to store the given number containing various chars
// in an integer form in a vector, while maintaing the mapping of those chars
// as mentioned in the base string
vector<int> getNumFromString(string n, string b, map<char, int> &strToInt){

    vector<int> num;

    for(char c: n){
        num.emplace_back(strToInt[c]);
    }

    return num;
}

// Function where we increase the given input number by 1
// The number is stored in a vector/array
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

// Function to convert the resulting next number back to a 
// string containing same characters and base as there were in the base string 
string convertNumToString(vector<int> &num, string b){

    string result = "";

    for(int n: num){
        result += b[n];
    }

    return result;
}

// succ_alien function, that take a number and base system as its input
// in string format and return the next number for n
string succ_alien(string n, string b){

    int length = n.size()-1, base = b.size();

    map<char, int> strToInt;

    getMappingOfBaseChars(b, base, strToInt);

    vector<int> num = getNumFromString(n, b, strToInt);

    incrementBy1(num, length, base);

    string result = convertNumToString(num, b);

    return result;
}

// Function to test the code for multiple inputs
void testCodeForMultipleInputs(){

    string s1 = "!@^&*", s2 = "!@#^*&", s3 = "******";
    string b1 = "!@^&*", b2 = "!@#^&*";
    string ans1 = "!@^*!", ans2 = "!@#^**", ans3 = "!!!!!!";

    bool test1, test2, test3;
    
    test1 = ans1 == succ_alien(s1, b1);
    test2 = ans2 == succ_alien(s2, b2);
    test3 = ans3 == succ_alien(s3, b2);

    cout << test1 << " " << test2 << " " << test3 << endl;

    return;
}

// Main Function, entry point of the program
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