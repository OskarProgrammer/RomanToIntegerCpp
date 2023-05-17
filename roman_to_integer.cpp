#include <iostream>
#include <string.h>
#include <math.h>
#include <map>
#include <string>

using namespace std;

typedef map<char, int> dict;//defining the dict with key char and value int

int integerToRoman(string number){
    int result=0;
    int x=0;
    dict m = {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
    };
    // m['I']=1;
    // m['V']=5;
    // m['X']=10;
    // m['L']=50;
    // m['C']=100;
    // m['D']=500;
    // m['M']=1000;

    while (x < number.length()){
        char current = number[x];
        try{
            char next = number[x+1];

            if (m[current] < m[next]){
                result+=(m[next] - m[current]);
                x+=2;
            }else{
                result+=(m[current]);
                x+=1;
            }
        }catch (exception){
            result+=(m[current]);
            x+=1;
        }
    }
    return result;
}

int main(){
    string number;
    cin >> number;
    cout << integerToRoman(number)<<endl;

    return 0;
}