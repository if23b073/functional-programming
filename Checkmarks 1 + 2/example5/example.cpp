#include <iostream>
#include <cmath>
#include <tuple>

using namespace std;

auto ikosaeder = [](const int a) {
    const float V = 5 * pow(a, 3) * (3 + sqrt(5)) / 12;        
    const float A = 5 * pow(a, 2) * sqrt(3);                  
    const float ru = a / 4.0 * sqrt(2 * (5 + sqrt(5)));       
    const float ri = a * sqrt(3) * (3 + sqrt(5)) / 12;        
    return make_tuple(V, A, ri, ru);
};

int main() {
    const int a = 2;  
    auto [V, A, ri, ru] = ikosaeder(a);
    cout << "Volumen: " << V << " Oberfläche: " << A << " Inkreisradius: " << ri << " Umkreisradius: " << ru << endl;
    return 0;
}