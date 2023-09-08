#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define endl "\n"
void fast() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin.exceptions(cin.failbit);
}
void calculation() {
    double product_price;
    double total_price = 0.0;
    string input;

    while(true) {
        cin >> input;

        if (input == "done") {
            break;
            cout << "Thank You." << endl;
        }
        product_price = stod(input);
        total_price+=product_price;
    }
    cout << "--------------------" << endl;
    cout << fixed << setprecision(2) <<"Total Price: $ "<<total_price << endl;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    calculation();
    return (EXIT_SUCCESS); 
}
