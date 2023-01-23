#include <iostream>

using namespace std;

int checkMail(string mail)
{
	string after = "";
	bool add = false;

	// The email address must start with a letter (no numbers or symbols).
	int a = ("%d",mail[0]);
	bool con1 = a < 65 || a > 90; // not capital letters
	bool con2 = a < 97 || a > 122;// not small letters
	if (con1 && con2){
		cout << "[x] Your Gmail \""<< mail << "\" is invalid !" << endl;
		cout << "[x] The email address must start with a letter (no numbers or symbols)."<<endl<<endl;
		return 0;
	}

	for(int i=0;i<mail.length();i++)
	{
		char e = mail[i];
		if (e == '@')
		{
			add = true;
		}
		if (add)
		{
			after += mail[i];
		}
	}

	if (after == "@gmail.com") 
	{
		cout << "[+] Your Gmail \""<< mail << "\" is valid !" << endl<<endl;
		return 1;
	}
	else 
	{
		cout << "[x] Your Gmail \""<< mail << "\" is invalid !" << endl;
		cout << "[x] There must be a 'gmail.com' after '@' NOT '"<< after << "'" << endl << endl;
		return 0;
	}
}

int main()
{ 
	/* test cases */
	//
	// string test_mail1 = "dingDong@gmail.com";
	// string test_mail2 = "dingDong@gmall.com";
	// string test_mail3 = "small_pp@gmail.com";
	// string test_mail4 = "dingDong@small.com";

	// checkMail(test_mail1);
	// checkMail(test_mail2);
	// checkMail(test_mail3);
	// checkMail(test_mail4);

	string mail;
	while(true)
	{
		cout << "Enter your gmail: ";
		cin >> mail;
		checkMail(mail);
	}


	return 0;
}