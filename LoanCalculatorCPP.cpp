#include <iostream>
#include <cmath>

using namespace std;

double calculateMonthlyPayment(double loanAmount, double annualInterestRate, int loanTermYears) {
    double monthlyInterestRate = annualInterestRate / 12 / 100;
    int totalPayments = loanTermYears * 12;
    return loanAmount * monthlyInterestRate / (1 - pow(1 + monthlyInterestRate, -totalPayments));
}

double calculateAnnualInterestRate(double loanAmount, double monthlyPayment, int loanTermYears) {
    int totalPayments = loanTermYears * 12;
    double low = 0.0;
    double high = 100.0;
    double mid;

    while (high - low > 0.0001) {
        mid = (low + high) / 2;
        double monthlyInterestRate = mid / 12 / 100;
        double estimatedPayment = loanAmount * monthlyInterestRate / (1 - pow(1 + monthlyInterestRate, -totalPayments));

        if (estimatedPayment < monthlyPayment) {
            low = mid;
        }
        else {
            high = mid;
        }
    }

    return mid;
}

int main() {
    double loanAmount;
    double monthlyPayment;
    int loanTermYears;

    cout << "Enter loan amount: ";
    cin >> loanAmount;
    cout << "Enter monthly payment: ";
    cin >> monthlyPayment;
    cout << "Enter loan term (in years): ";
    cin >> loanTermYears;

    double annualInterestRate = calculateAnnualInterestRate(loanAmount, monthlyPayment, loanTermYears);
    cout << "Estimated annual interest rate: " << annualInterestRate << "%" << endl;

    return 0;
}
