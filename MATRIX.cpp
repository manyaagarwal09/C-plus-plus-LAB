#include <iostream>
using namespace std;

// Function to display the input matrices and the resultant matrix
void display(int A[10][10], int r1, int c1, 
             int B[10][10], int r2, int c2, 
             int R[10][10], int r3, int c3, 
             int operation) {
    cout << "\nInput Matrix M1:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    // Display second matrix only for binary operations (Addition, Subtraction, Multiplication)
    if (operation != 4) {
        cout << "\nInput Matrix M2:\n";
        for (int i = 0; i < r2; i++) {
            for (int j = 0; j < c2; j++) {
                cout << B[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // Output title based on operation
    if (operation == 1) {
        cout << "\nResultant Matrix (Addition):\n";
    } else if (operation == 2) {
        cout << "\nResultant Matrix (Subtraction):\n";
    } else if (operation == 3) {
        cout << "\nResultant Matrix (Multiplication):\n";
    }

    // Display resultant matrix
    for (int i = 0; i < r3; i++) {
        for (int j = 0; j < c3; j++) {
            cout << R[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to perform matrix addition
void addition(int M1[10][10], int M2[10][10], int R[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            R[i][j] = M1[i][j] + M2[i][j];
        }
    }
}

// Function to perform matrix subtraction
void subtraction(int M1[10][10], int M2[10][10], int R[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            R[i][j] = M1[i][j] - M2[i][j];
        }
    }
}

// Function to perform matrix multiplication
void multiplication(int M1[10][10], int M2[10][10], int R[10][10], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            R[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                R[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
}

// Function to calculate matrix transpose
void transpose(int M[10][10], int R[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            R[j][i] = M[i][j];
        }
    }
}

int main() {
    int M1[10][10], M2[10][10], R[10][10];
    int r1, c1, r2, c2;
    int choice, matrixChoice;

    // Input Matrix 1
    cout << "Enter rows and columns of Matrix M1: ";
    cin >> r1 >> c1;
    cout << "\nEnter elements of Matrix M1:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> M1[i][j];
        }
    }

    // Input Matrix 2
    cout << "\nEnter rows and columns of Matrix M2: ";
    cin >> r2 >> c2;
    cout << "\nEnter elements of Matrix M2:\n";
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> M2[i][j];
        }
    }

    // Menu loop
    do {
        cout << "\nMatrix Menu\n";
        cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Transpose\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (r1 == r2 && c1 == c2) {
                    addition(M1, M2, R, r1, c1);
                    display(M1, r1, c1, M2, r2, c2, R, r1, c1, 1);
                } else {
                    cout << "\nAddition not possible... Both matrices must have same order.\n";
                }
                break;

            case 2:
                if (r1 == r2 && c1 == c2) {
                    subtraction(M1, M2, R, r1, c1);
                    display(M1, r1, c1, M2, r2, c2, R, r1, c1, 2);
                } else {
                    cout << "\nSubtraction not possible... Both matrices must have same order.\n";
                }
                break;

            case 3:
                if (c1 == r2) {
                    multiplication(M1, M2, R, r1, c1, c2);
                    display(M1, r1, c1, M2, r2, c2, R, r1, c2, 3);
                } else {
                    cout << "\nMultiplication not possible... Columns of M1 must be equal to rows of M2.\n";
                }
                break;

            case 4:
                cout << "\nWhich Matrix do you want to Transpose, 1 or 2?\nEnter your choice: ";
                cin >> matrixChoice;

                if (matrixChoice == 1) {
                    transpose(M1, R, r1, c1);

                    cout << "\nInput Matrix M1:\n";
                    for (int i = 0; i < r1; i++) {
                        for (int j = 0; j < c1; j++) {
                            cout << M1[i][j] << "\t";
                        }
                        cout << endl;
                    }

                    cout << "\nResultant Matrix (Transpose of M1):\n";
                    for (int i = 0; i < c1; i++) {
                        for (int j = 0; j < r1; j++) {
                            cout << R[i][j] << "\t";
                        }
                        cout << endl;
                    }
                } else if (matrixChoice == 2) {
                    transpose(M2, R, r2, c2);

                    cout << "\nInput Matrix M2:\n";
                    for (int i = 0; i < r2; i++) {
                        for (int j = 0; j < c2; j++) {
                            cout << M2[i][j] << "\t";
                        }
                        cout << endl;
                    }

                    cout << "\nResultant Matrix (Transpose of M2):\n";
                    for (int i = 0; i < c2; i++) {
                        for (int j = 0; j < r2; j++) {
                            cout << R[i][j] << "\t";
                        }
                        cout << endl;
                    }
                } else {
                    cout << "\nInvalid Matrix choice\n";
                }
                break;

            case 5:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice...\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
