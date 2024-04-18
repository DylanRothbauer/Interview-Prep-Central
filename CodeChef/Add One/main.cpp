#include <iostream>
using namespace std;

string AddOne(string N) {
    // Start from the last digit and move backward
    for (int i = N.length() - 1; i >= 0; i--) {
        if (N[i] == '9') {
            N[i] = '0';  // If '9', set to '0' and continue to next digit
        }
        else {
            N[i] += 1;  // If not '9', increment and return the modified number
            return N;
        }
    }
    // If all digits were '9', we need to add a '1' at the beginning
    return "1" + N;
}

int main() {
    int T;
    cin >> T;  // Read the number of test cases

    while (T > 0) {
        string N;
        cin >> N;  // Read the large number as a string
        string result = AddOne(N);
        cout << result << endl;
        T--;
    }
    return 0;
}