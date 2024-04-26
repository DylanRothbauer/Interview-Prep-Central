#define INF 999
#include <iostream>
using namespace std;

void printMatrix(int arr[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == INF) {
				cout << "INF" << " ";
			}
			else {
				cout << arr[i][j] << " ";
			}
		}
		cout << "\n";
	}
}


void allPairsShortestPath(int arr[4][4]) {
	int i, j, k;

	for (k = 0; k < 4; k++) {
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				//arr[i, j] = min(arr[i, j], arr[i, k] + arr[k, j]);
				if (arr[i][k] + arr[k][j] < arr[i][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
}

int main() {
	int arr[4][4] = { {0,1,5,INF}, // example from notes
					{INF,0,2,INF},
					{INF,2,0,3},
					{INF,INF,INF,0}
	};

	allPairsShortestPath(arr); // Floyd Warshall Algorithm
	printMatrix(arr);

	return 0;
}