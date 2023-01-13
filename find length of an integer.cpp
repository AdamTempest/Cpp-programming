#include <iostream>

using namespace std;

int findLengthOfInt(int num){
    int count=0; int tens=1;
    while(tens<num){
        tens = tens*10;
        count+=1;
    }
    if (!count) {return 1;}
    return count;
}

int main(){

    cout << "length of 1: " << findLengthOfInt(1) << endl;
    cout << "length of 12: " << findLengthOfInt(12) << endl;
    cout << "length of 123: " << findLengthOfInt(123) << endl;
    cout << "length of 1234: " << findLengthOfInt(1234) << endl;
    cout << "length of 12345: " << findLengthOfInt(12345) << endl;

    return 0;
}