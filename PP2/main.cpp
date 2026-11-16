#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

const double a =-0.9;
const double b =0.9;
//Calculates the sum of the series S(x) with a specified precision
double s (double x, double eps) {
    double x4 = x * x * x * x;
    double terms = x *x4 / 5;
    double sum = terms;
    for (double k = 1; terms> eps || terms < -eps; k+=4) {
        terms *= x4 * k/(k+8) ;
        sum += terms;
    }
    return sum;
}
//Displays an error, followed by a diagnostic message
void report(const char* message) {
    cout << "***** error\n"<< message << endl;
}
//Reads a number and checks that nothing else follows it
bool isReal (double& real) {
    cin >> real;
    int next = cin.peek();
    return !cin.fail() && (next == EOF || isspace(next));
}
//Requests x and checks whether it is a number that falls within a specified range.
bool inputX (double& x) {
    cout << "Enter x from [" << a << "] to [" << b << "]: \n";
    if (!isReal(x)) {
        report("x must be a valid number");
        return false;
    }
    if (x<a || x>b) {
        report("x must be within the specified range");
        return false;
    }
    return true;
}
//Requests an epsilon and checks whether it is a positive number
bool inputEps (double& eps) {
    cout << "Enter epsilon (positive number):\n";
    if (!isReal(eps)) {
        report("epsilon must be a valid number");
        return false;
    }
    if (eps <= 0.0) {
        report("epsilon must be positive");
        return false;
    }
    return true;
}
//Calculates S(x) and outputs the input data and the result.
void calculations(double x, double eps) {
    cout << "***** do calculations ... ";
    const double result = s(x,eps);
    cout << "done\n";
    cout << scientific  << uppercase;
    cout << "for x = " << setprecision(7) <<x << endl;
    cout << "for eps = " << setprecision(9) << eps << endl;
    cout << "result = " <<fixed << setprecision(8) << result << endl;
}
int main() {
    cout << "Yevhenii Andronenkov\n";
    cout << "Variant:159\n";
    cout << "calculate the sum of a power series S(x) at a given point with a specified precision\n";
    double x = 0;
    double eps = 0;
    if (inputX(x) && inputEps(eps)) {
        calculations(x, eps);
    }
    return 0;
}