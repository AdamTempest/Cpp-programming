#include <iostream>

using namespace std;

class Solution 
{
public:
    bool isPalindrome(int x) 
    {   
        long r=0;
        int n=x;
        while (n>0)
        {
            int t = n%10;
            r = r*10+t;
            n = n/10;
        }
        return r == x;
    }
};

int main()
{
    Solution obj;

    // int inpt=0;
    // cin >> inpt;
    int num = 121;
    int res = obj.isPalindrome(num);

    if(res){
        cout << num << " is a Palindrome."<<endl;
    } else{
        cout << num << " is not a Palindrome."<<endl;
    }


    return 0;
}