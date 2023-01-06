#include <iostream>

using namespace std;

class Solution {
public:
    int countDigits(int num) {
        int n = num;
        int c = 0;
        while (n>0){
            int d = n%10;
            if (!(num % d)){ // if res is zero
                c+=1;
            }
            n = n/10;
        }
        return c;
    }
};

int main()
{
    Solution a;
    int num = 1248;
    cout << "Input: " << num<< endl;
    cout << "Output: "<< a.countDigits(num)<< endl;
    return 0;
}