#include <iostream>
#include <iomanip>
#include <cmath>
#include <numbers>
using namespace std;
//calculates the value of x for variant 159 and returns the result as a double
double f(double x) {
        return sin(20.0/59.0)+(18.0* numbers::e)/(62.0* numbers::pi)
        *4/((x+10.0)*(x-7.0))+12.0*asin(x-11.0)-(3.0+sqrt(x-8.0))/(x+15.0);
}
// checks if x is between 10 and 12 (10 and 12 are included)
bool isDefined(double x) {
        return x >= 10.0 && x <= 12.0;
}

int main() {
        double x;
        cout << "Author: Yevhenii Andronenkov" << endl;
        cout << "Variant: 159" << endl;
        cout << "Calculate the value for x." << endl;
        cout << "Enter x (10 <= x <= 12):";
        cin >> x;
        if (cin.fail()) {
                cout << "\nwrong input" << endl;
        } else {
                cout << "\n***** do calculations ... ";
                bool defined = isDefined(x);
                double result = 0.0;
                if (defined) {
                        result = f(x);
                }
                cout << "done" << endl;

                cout << fixed << setprecision(5) << "for x = " << x << endl;
                if (defined) {
                        cout << fixed << setprecision(9) << "result = " << result << endl;
                } else
                        cout << "result = undefined" << endl;

        }
        return 0;
}