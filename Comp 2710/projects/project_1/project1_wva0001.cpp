//William Abbot
//project1_wva0001.cpp
//compile code using the g++ command
//learned how to format my numbers properly from the textbook
//learned how to make a template from stackoverflow.com
//learned how to make simple functions on youtube.com

#include <iostream>
#include <iomanip>

using namespace std;

//the code for this template is from a post by Cyril Leroux on stackoverflow.com 
template <typename MyType> void printElement(MyType n, int width)
{
	cout << left <<  setw(width) << setfill(' ') << n;
}//end of template

void Astericks()
{
	for (int i = 0; i < 54; i++)
	{
		cout << "*";
	}
}

int main()
{
	double LoanAmount;
	double InterestRate;
	double MonthlyPayments;
	double Principle;
	double InterestMonth;
	double InterestPayment;
	double MonthlyDiff;
	int LoopCounter1 = 0;
	double TotalInterest = 0;



	cout << "Loan Amount: ";
	cin >> LoanAmount;
	cout << "Interest Rate (% per year): ";
	cin >> InterestRate;
	cout << "Monthly Payments: ";
	cin >> MonthlyPayments;

	cout << "\n";
	Astericks();
	cout << "\n" << "        Amortization Table" << "\n";
	Astericks();
	cout << "\n";



	InterestMonth = InterestRate/12;
	double Balance = LoanAmount;
	double PreviousBalance = Balance;

	printElement("Month", 8);
        printElement("Balance", 11);
        printElement("Payment", 10);
        printElement("Rate", 7);
        printElement("Interest", 10);
        printElement("Principal", 10);
        cout << "\n";
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	if(LoopCounter1 == 0)
	{
		printElement(LoopCounter1, 8);
                printElement(Balance, 11);
                printElement("N/A", 10);
                printElement("N/A", 7);
                printElement("N/A", 10);
                printElement("N/A", 10);
                cout << "\n";
                LoopCounter1++;
	}


	while(Balance > 0)
	{
		PreviousBalance = Balance;
		InterestPayment = (InterestMonth/100)*Balance;
		if (MonthlyPayments < InterestPayment)
		{
			cout << "The interest rate is too high for your monthly payments, try again" << "\n" << "\n"; 
			return 0;
		}
		TotalInterest += InterestPayment;
		MonthlyDiff = Balance - MonthlyPayments;
		switch (MonthlyDiff < 0)
		{
			case true:
				MonthlyPayments += (MonthlyDiff + InterestPayment);
				Principle = PreviousBalance;
				break;
			case false:
				Principle = MonthlyPayments-InterestPayment;
				break;
			default:
				break;
		}
		Balance -= Principle;
		printElement(LoopCounter1, 8);
		printElement(Balance, 11);
		printElement(MonthlyPayments, 10);
		cout.precision(1);
		printElement(InterestMonth, 7);
		cout.precision(2);
		printElement(InterestPayment, 10);
		printElement(Principle, 10);
		cout << "\n";
		LoopCounter1++;	
	}

	Astericks();

	cout << "\n" << "\n"  << "It takes " << (LoopCounter1 - 1) << " months to pay off the loan." << "\n";
	cout << "Total interest paid is: $" << TotalInterest << "\n" << "\n";

	return 0;
}
