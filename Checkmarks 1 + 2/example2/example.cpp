#include <iostream>
#include <cmath>
#include <tuple>      

using namespace std;

auto wuerfel = [](int a) {
    int V = pow(a, 3);
    int A = 6 * pow(a, 2);
    float d = a * sqrt(3);
    float ru = a / 2 * sqrt(3);
    float ri = a / 2;
    return make_tuple(V, A, d, ri, ru);
};

int main() {
    const int a = 2; 
    auto [V, A, d, ri, ru] = wuerfel(a);
    cout << "Volumen: " << V << " Oberfläche: " << A << " Diagonale: " << d << " Inkreisradius: " << ri << " Umkreisradius: " << ru << endl;
    return 0;
}