#include <iostream>
#include <cmath>
#include <tuple>      

using namespace std;

auto oktaeder = [](const int a) {
    const float V = pow(a, 3) * sqrt(2) / 3;
    const float A = 2 * pow(a, 2) * sqrt(3);
    const float ru = a * sqrt(2) / 2;
    const float ri = a * sqrt(6) / 6;
    return make_tuple(V, A, ri, ru);
};

int main() {
    const int a = 2;
    auto [V, A, ri, ru] = oktaeder(a);
    cout << "Volumen: " << V << " Oberfläche: " << A << " Inkreisradius: " << ri << " Umkreisradius: " << ru << endl;
    return 0;
}