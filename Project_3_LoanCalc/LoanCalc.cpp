/***********************************************************
*
* LoanCalc.cpp
* 
* Ryan Hochmuth & Jason griffith
*
* 10/2/2014
*
* Description:
*	The LoanCalc program is used to take input
*	from the user for a loan amount, interest rate
*	and payment amount. It then takes this
*	information and calculates how many months
*	it will take to pay off the loan.
*
***********************************************************/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Function prototypes
void intro();
void getLoanAmount(double&, double&);
void getPaymentAmount(double&);
int calculateMonths();
void displayResults();

/*
* The main method that starts the program.
*/
int main()
{
	// Loan variables
	double loanAmount = 0;
	double interestRate = 0;
	double paymentAmount = 0;

	// Control variables
	bool keepGoing = true;

	intro(); // Display the intro greeting

	while (keepGoing)
	{
		// Reset loan variables
		loanAmount = 0;
		interestRate = 0;
		paymentAmount = 0;
		
		getLoanAmount(loanAmount, interestRate); // Get the loan amount and interest rate
		getPaymentAmount(paymentAmount); // Get the payment amount

		cout << loanAmount;
		cout << "\n";
		cout << interestRate;

		// Take input to see if the program should repeat
		cout << "\n\nWould you like to repeat the program? (yes/no): ";
		string input;
		getline(cin, input);


		if (input.compare("no") == 0)
		{
			keepGoing = false;
			cout << "\nGoodbye\n";
			system("PAUSE"); // Wait for user input
		}
		else if (input.compare("yes") == 0)
		{
			keepGoing = true;
			cout << "\n\n";
		}
		else
		{
			cout << "\nInvalid answer.  Assuming yes.\n\n";
		}
	}

	return 0;
}

/*
* Displays information on what this program does.
*/
void intro()
{
	cout << "The LoanCalc program is used to take input\n"
		"from the user for a loan amount, interest rate\n"
		"and payment amount. It then takes this\n"
		"information and calculates how many months\n"
		"it will take to pay off the loan.\n\n";
}

/*
* Takes input for the loan amount and interest rate.
*/
void getLoanAmount(double& loanAmount, double& interestRate)
{
	bool takeInput = true;
	int tempInput = 0;

	cout << "\n";

	// Loop until proper data entered
	while (takeInput)
	{
		cout << "Enter the full loan amount. (ex. 1000): ";
		cin >> tempInput;

		if (tempInput >= 0)
		{
			takeInput = false;
		}
		else
		{
			cout << "\nInvalid input.\n";
			takeInput = true;
		}
	}

	loanAmount = tempInput;
	tempInput = 0;
	takeInput = true;

	// Loop until proper data entered
	while (takeInput)
	{
		cout << "\nEnter the yearly interest rate. (ex. 18% would be 18): ";
		cin >> tempInput;

		if (tempInput >= 0)
		{
			takeInput = false;
		}
		else
		{
			cout << "\nInvalid input.";
			takeInput = true;
		}
	}

	interestRate = tempInput;
}

/*
* Takes input for the monthly payment amount.
*/
void getPaymentAmount(double& paymentAmount)
{

}

/*
* Calculates the number of months it takes to
* pay off the loan.
*/
int calculateMonths()
{
	return 0;
}

/*
* Display the results of the calculation.
*/
void displayResults()
{

}