#include <iostream>

using namespace std;

class Solution {
public:
	bool isInArray(int tofind, int arr[],int length)
	{
		for (int i=0;i<length;i++)
		{
			if (tofind == arr[i])
			{
				return true;
			}
		}
		return false;
	}

    bool isHappy(int n) 
    {
    	if (n == 1){
    		return true;
    	}

    	int sum = 0;
    	int history[100] = {0};
    	int length = 0;

    	while (sum!=1)
    	{
    		while (n>0)
    		{
	    		int c = n%10;
	    		sum +=  c*c; // squared
	     		n = n/10;
	    	}
	    	
	    	if (sum==1)
	    	{
	    		return true;
	    	} 
	    	else if (isInArray(sum,history,length))
	    	{
	    		return false;
	    	}
	    	history[length] = sum;
	    	length+=1;
	    	n=sum;
	    	sum=0;
    	}
    	return true;
    }
};

int main()
{
	Solution obj;
	int num = 7;
	int res = obj.isHappy(num);

	if (res)
	{
		cout << num << " is happy !" << endl;
	} 
	else
	{
		cout << num << " isn't happy !" << endl;
	}


	return 0;
}