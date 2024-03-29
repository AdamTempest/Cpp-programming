#include "bank_account.h"

namespace Bankaccount {
	void Bankaccount::open(){
		if (!opened){
			opened = true;
		} else {
			throw std::invalid_argument("Sorry, you cannot open this account as it is already opened.");
		}
	}
	
	int Bankaccount::balance(){
		if (opened){
			return user_balance;
		} else {
			throw std::invalid_argument("Sorry, the balance cannot be checked. Your account is closed.");
		}
	}

	void Bankaccount::deposit(int amount){
		if (opened){
			if (amount>0){
				user_balance+=amount;
			} else{
				throw std::invalid_argument("Sorry, you cannot deposit negative amount.");
			}
		} else {
			throw std::invalid_argument("Sorry, you cannot deposit into this account. It is closed.");
		}
	}

	void Bankaccount::withdraw(int amount){
		if (opened){
			if (amount < 0){
				throw std::invalid_argument("Sorry, you cannot withdraw negative amount.");
			} else if (amount <= user_balance){
				user_balance -= amount;
			} else {
				throw std::invalid_argument("Sorry, that amount exceeds your balance.");
			}
		} else{
			throw std::invalid_argument("Sorry, you cannot withdraw from this account. It is closed.");
		}
	}

	void Bankaccount::close(){
		if (opened){
			user_balance = 0;
			opened = false;
		} else{
			throw std::invalid_argument("Sorry, you cannot close this account since it is not opened.");
		}
	}

}
