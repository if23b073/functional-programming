#include <iostream>
#include <cmath>
#include <tuple>

using namespace std;
//insgesamt 3 Lambdas wegen 3 Parametern
auto quader = [](int a) { //gibt ein weiteres Lambda zurück
    return [=](int b) { //captured a und gibt ein weiters Lambda zurück
        return [=](int c) { //captured a und b und macht die Berechnung, gibt Ergebnis zurück
            int V = a * b * c;
            int A = 2 * (a * b + a * c + b * c);
            float d = sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2));
            return make_tuple(V, A, d);
        };
    };
};

int main() {
    const int a = 2;
    const int b = 3;
    const int c = 4;

    auto [V, A, d] = quader(a)(b)(c);

    cout << "Volumen: " << V << " Oberfläche: " << A << " Diagonale: " << d << endl;

    return 0;
}