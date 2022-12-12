#include <stdio.h>

int findStr(char buf[100000], char tofind[100], int size,int i);

int main()
{
	int countWinhtut		   = 0;
	int countNationalCyberCity = 0;

	char winhtut[7] = {'w','i','n','h','t','u','t'};
	char NationalCyberCity[17] = {'N','a','t','i','o','n','a','l','C','y','b','e','r','C','i','t','y'};

	// reading from file
	if (FILE *fp = fopen("words.txt", "r"))
	{
		char buf[100000];
		while (size_t len = fread(buf, 1, sizeof(buf), fp)){

			// finding string
			for (int i=0;i<100000;i++){
				countWinhtut 		   += findStr(buf, winhtut, 7, i);
				countNationalCyberCity += findStr(buf, NationalCyberCity, 17, i);
			}
		}
		fclose(fp);
	}
	
	printf("====================================\n");
	printf("  ====== In words.txt file  ======  \n");
	printf("====================================\n");
	printf("[+] Winhtut appeared for: %d times. \n", countWinhtut);
	printf("[+] NationalCyberCity appeared for: %d times. \n", countNationalCyberCity);

	return 0;
}

int findStr(char buf[100000], char tofind[100], int size, int i){
	int count=0;
	char space[100];

	for(int j=0;j<size;j++){
		space[j] = buf[i+j];
		// 0+0=0; 0+1=1; 0+2=2; 0+3=3; ...; [0,1,2,3]
		// 1+0=1; 1+1=2; 1+2=3; 1+3=4; ...; [1,2,3,4]
		// 2+0=2; 2+1=3; 2+2=4; 2+3=5; ...; [2,3,4,5]
	}
	
	// checking if it's equal to tofind
	int equal = 1;
	for (int w=0;w<size;w++){
		if (space[w] != tofind[w]){
			equal=0;
			break;
		}
	}

	if (equal){
		count++;	
	} else{
		equal=1;
	}
	
	return count;
}