/**
 * 
 * Created on 6/2/2023
 * 
*/

// input - [id, name, nrc, password, email, accStatus, accLevel, PhNo, amount, addr, transrc]

#include <iostream>

struct transition{
	char note[200];
};

struct data{
	unsigned int id;
	char name[30];
	char nrc[50]; // id
	char mail[50];
	char password[50];
	char acc_status[1];
	char address[100];
	char pOrb[1]; // personal Or buisiness
	char loan_status[1];
	int acc_level;
	unsigned int monthly_income;
	unsigned int loan_amount;
	unsigned int loan_reate;
	unsigned int phNumber;
	unsigned int cur_amount; // balance
	struct transition trc[100];
};

struct data db[1000];

void welcome(){
	int option=0;
	printf("Welcome to the Bank\n");
	printf("Press 1 to login\nPress 2 to REgister\nPress 3 to Exit");

	switch (option){
	case
	}

}

// gmail validation
// strong password validation
// amount validation
