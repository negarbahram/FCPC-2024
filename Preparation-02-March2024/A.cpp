#include <iostream>
using namespace std;

int main() {
    int PersepolisHome, EsteghlalHome, PersepolisAway, EsteghlalAway;

    cin >> PersepolisHome >> EsteghlalAway;
    cin >> EsteghlalHome >> PersepolisAway;

    if (PersepolisHome + PersepolisAway > EsteghlalHome + EsteghlalAway)
        cout << "Persepolis\n";
    else if (PersepolisHome + PersepolisAway < EsteghlalHome + EsteghlalAway)
        cout << "Esteghlal\n";
    else if (PersepolisAway > EsteghlalAway)
        cout << "Persepolis\n";
    else if (PersepolisAway < EsteghlalAway)
        cout << "Esteghlal\n";
    else
        cout << "Penalty\n";

    return 0;
}
