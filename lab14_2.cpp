#include<iostream>
using namespace std;

const int N = 5;


void inputMatrix(double A[][N]) {
    for (int i = 0; i < N; ++i) {
        cout << "Row " << (i + 1) << ": ";
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }
}

void findLocalMax(const double A[][N], bool B[][N]) {
    for (int i = 0; i < N; ++i) {
        B[i][0] = false;
        B[i][N - 1] = false;
    }
    for (int j = 0; j < N; ++j) {
        B[0][j] = false;
        B[N - 1][j] = false;
    }

    for (int i = 1; i < N - 1; ++i) {
        for (int j = 1; j < N - 1; ++j) {
            double center = A[i][j];
            bool isLocalMax =
                center >= A[i - 1][j] && // บน
                center >= A[i + 1][j] && // ล่าง
                center >= A[i][j - 1] && // ซ้าย
                center >= A[i][j + 1];   // ขวา
            B[i][j] = isLocalMax;
        }
    }
}

void showMatrix(const bool B[][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << (B[i][j] ? 1 : 0);
            if (j < N - 1) cout << ' ';
        }
        cout << '\n';
    }
}


int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

