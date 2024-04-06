#include <iostream>
using namespace std;

void determineChampion(int prizePool, int carlsen, int chef) {
	int carlsenPrize = 0;
	int chefPrize = 0;

	if (carlsen > chef) {
		carlsenPrize += (60 * prizePool);
		chefPrize += (40 * prizePool);
		cout << carlsenPrize << endl;
		//cout << chefPrize << endl;
	}
	else if (chef > carlsen) {
		chefPrize += (60 * prizePool);
		carlsenPrize += (40 * prizePool);
		//cout << chefPrize << endl;
		cout << carlsenPrize << endl;
	}
	else if (carlsen == chef) {
		carlsenPrize += (55 * prizePool);
		chefPrize += (45 * prizePool);
		cout << carlsenPrize << endl;
		//cout << chefPrize << endl;
	}

}

int main() {
	// your code goes here
	int T;
	int X;
	string S;
	int carlsen = 0;
	int chef = 0;

	cin >> T;

	while (T > 0) {
		carlsen = 0;
		chef = 0;
		cin >> X;
		cin >> S;

		for (int i = 0; i < S.length(); i++) {
			if (S.at(i) == 'C') {
				carlsen += 2;
			}
			else if (S.at(i) == 'N') {
				chef += 2;
			}
			else {
				carlsen += 1;
				chef += 1;
			}
		}

		determineChampion(X, carlsen, chef);
		T--;
	}


}
