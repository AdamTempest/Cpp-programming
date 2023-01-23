#include <iostream>

using namespace std;

// jumpsearch
void printArray(int *arr,int size);
void BubbleSort(int *arr,int size);
int jumpSearch(int *arr, int size, int target);


int main()
{
	int arr[]  = {5,26,7,8,2,1,45,6,312,124}; // unsorted
	int size   = sizeof(arr)/sizeof(arr[0]);
	int toFind = 2;
	int result = 0;

	cout << "[.] Find: " << toFind << endl;

	result = jumpSearch(arr,size, toFind);
	if (result>=0)
	{
		cout << "[+] Found it!" << endl;
		cout << "[+] " << toFind << " is at index " << result << "." <<endl;
		cout << "[+] Array: ";
		printArray(arr,size);
	} else 
	{
		printArray(arr,size);
		cout << "[x] "<< toFind << " is not in array!"<< endl;
	}
	cout << endl;

	return 0;
}

// start of jumpsearch related functions
void BubbleSort(int *arr,int size)
{
	int temp;
	for (int i=0;i<size-1;i++)
	{
		for (int j=0;j<size-i-1;j++)
		{
			if (arr[j]>arr[j+1])
			{
				temp     = arr[j+1];
				arr[j+1] = arr[j];
				arr[j]   = temp;
			}
		}
	}
}

int jumpSearch(int *arr, int size, int target)
{
	int previous = 0;
	int nextStep = size/2;
	int width    = nextStep;
	bool forward = true;

	// sort the array, if it isn't sorted
	for (int i=0;i<size-1;i++)
	{
		if (arr[i] > arr[i+1])
		{
			BubbleSort(arr,size);
		}
	}

	// checking if the target is first or last element and
	// if it's in the range of array
	if (arr[0] == target)
	{
		return 0;
	}
	else if (arr[size-1] == target)
	{
		return size-1;
	}
	else if (arr[size-1] < target || arr[0] > target)
	{
		return -1;
	}

	// jump
	while (width >= 2)
	{
		// checking current place and elements beside it
		if (arr[nextStep] == target)
		{
			return nextStep;
		} 
		else if (arr[nextStep-1] == target)
		{
			return nextStep-1;
		} 
		else if (arr[nextStep+1] == target)
		{
			return nextStep+1;
		}

		// jump
		if (arr[nextStep] < target)
		{
			width     = width/2;
			previous  = nextStep;
			nextStep += width;
			forward   = true;
		} else
		{
			width     = width/2;
			previous  = nextStep;
			nextStep -= width;
			forward   = false; 
		}
	}

	// linear search
	if (forward)
	{
		for(int j=previous;arr[j]<=target;j++)
		{
			cout << "arr[j]: " <<arr[j] << endl;
			if (arr[j] == target)
			{
				return j;
			}
		}
	} else 
	{
		for(int j=previous;j>0 && arr[j]>=target;j--)
		{
			if (arr[j] == target)
			{
				return j;
			}
		}
	}

	return -1;

}

void printArray(int *arr,int size)
{
	cout << "[";
	for (int i=0;i<size-1;i++) 
	{	
		cout <<arr[i] << ", ";	
	}
	cout << arr[size-1] << "]" << endl;
}