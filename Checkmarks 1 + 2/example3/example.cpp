#include <iostream>
#include <cmath>
#include <tuple>     

using namespace std;

auto tetraeder = [](const int a) {
    const float V = pow(a, 3) * sqrt(2) / 12;     
    const float A = pow(a, 2) * sqrt(3);          
    const float ru = a * sqrt(6) / 4;             
    const float ri = a * sqrt(6) / 12;            
    return make_tuple(V, A, ri, ru);
};

int main() {
    const int a = 2;  
    auto [V, A, ri, ru] = tetraeder(a);
    cout << "Volumen: " << V << " Oberfläche: " << A << " Inkreisradius: " << ri << " Umkreisradius: " << ru << endl;
    return 0;
}