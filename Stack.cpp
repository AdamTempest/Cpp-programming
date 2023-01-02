#include <iostream>

using namespace std;

#define MAXOFSTACK 10

int toCount=0;

struct stack
{
	int data[MAXOFSTACK];
	int top;
};

typedef struct stack st;

void create_emptyStack(st *myStack);
int isStackFull(st *myStack);
int isStackEmpty(st *myStack);
void pushToStack(st *myStack, int value);
void printStackData(st* myStack);

int main()
{
	st *myStack=(st*)malloc(sizeof(st));
	create_emptyStack(myStack);

	for (int i=30;i<40;i++)
	{
		pushToStack(myStack, i);
	}

	cout << "[..] There are " << myStack->top+1 << " elements inside the stack."<<endl;
	printStackData(myStack);
	return 0;
}

void create_emptyStack(st *myStack)
{
	myStack->top = -1;
}

int isStackFull(st *myStack)
{
	if (myStack->top == MAXOFSTACK-1)
	{
		return 1;
	} else
	{
		return 0;
	}
}

int isStackEmpty(st *myStack)
{
	if (myStack->top == -1)
	{
		return 1;
	} else
	{
		return -1;
	}
}

void pushToStack(st *myStack, int value)
{
	if (isStackFull(myStack))
	{
		printf("Stack is Full!\n");
	} else
	{
		myStack->top++;
		myStack->data[myStack->top] = value;
	}

	toCount++;
}

void printStackData(st* myStack)
{
	int count = myStack->top;
	cout << "     x=== Data inside stack ===x" << endl;
	for (int i=count;i>=0;i--)
	{
		cout <<"     |      Level " << count-i;
		cout << ":   "<< myStack->data[i] << "      |"<<endl;
	}
	cout << "     x=========================x" <<endl;

}