#include <iostream>
#include <cmath>
#include <tuple>

using namespace std;

auto dodekaeder = [](const int a) {
    const float V = pow(a, 3) * (15 + 7 * sqrt(5)) / 4.0;                 
    const float A = 3 * pow(a, 2) * sqrt(5 * (5 + 2 * sqrt(5)));          
    const float ru = a * sqrt(3) * (1 + sqrt(5)) / 4.0;                   
    const float ri = a * sqrt(10 * (25 + 11 * sqrt(5))) / 20.0;           
    return make_tuple(V, A, ri, ru);                                 
};

int main() {
    const int a = 2;  
    auto [V, A, ri, ru] = dodekaeder(a);
    cout << "Volumen: " << V << " Oberfläche: " << A << " Inkreisradius: " << ri << " Umkreisradius: " << ru << endl;
    return 0;
}