#include<iostream>
using namespace std;

void printStar(int num) {
	for (int i = 0; i < num; i++) {
		cout << "*";
	}
	cout << endl;
}

int main() {

	/*  Read input as specified in the question.
 * Print output as specified in the question.
 */
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		printStar(i);
	}

}


