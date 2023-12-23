#include <iostream>
#include <iomanip>

#define PI 3.14159

using namespace std;

double area(double raio) {
	return PI * raio * raio;
}

int main() {
	
	double raio;
	cin >> raio;

	cout << fixed << setprecision(4) << "A=" << area(raio) << "\n";

	return 0;
}
