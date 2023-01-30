#if !defined(BANK_ACCOUNT_H)
#define BANK_ACCOUNT_H
#include "iostream"

namespace Bankaccount {
class Bankaccount {
    public:
        void open();
        int balance();
        void deposit(int amount);
        void withdraw(int amount);
        void close();
    private:
        bool opened = false;
		int user_balance = 0;
};  // class Bankaccount

}  // namespace Bankaccount

#endif  // BANK_ACCOUNT_H