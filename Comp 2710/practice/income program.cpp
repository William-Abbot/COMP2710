#include <iostream>
#include <iomanip>

using namespace std;
const double income = 25000;


double friday(double t, double y);
bool incomecheck();

int main()
{
double minutes,income,hRate,total;

cout << "Total minutes of consulting time: ";
cin >> minutes;
cout << "Enter the standard hourly rate charged: ";
cin >> hRate;
cout << "Enter the income of customer: ";
cin >> income;


cout << "The total bill for this customer is $" << friday(minutes, hRate)  << ".";

return 0;
}

double friday(double minutes, double hrate)
{
    double total = 0;
    if (income <= 25000)
    {
        if (minutes <= 30)
		total = 0;
        else
        total = hrate * 0.40 * (minutes/60);
    }
    else if (income > 25000)
    {
        if (minutes <= 20)
		total = 0;
        else
		total = hrate * 0.7 * (minutes/60);
}

return total;
}