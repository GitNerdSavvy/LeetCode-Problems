class Solution {
public:
    struct matrix {
        int mat[2][2];
    };

    matrix mul(matrix A, matrix B) {
        matrix C;
        for (int row = 0; row < 2; row++) {
            for (int col = 0; col < 2; col++) {
                C.mat[row][col] = 0;
                for (int i = 0; i < 2; i++) {
                    C.mat[row][col] += A.mat[row][i] * B.mat[i][col];
                }
            }
        }
        return C;
    }

    matrix identity() {
        matrix A;
        A.mat[0][0] = 1;
        A.mat[0][1] = 0;
        A.mat[1][0] = 0;
        A.mat[1][1] = 1;
        return A;
    }

    matrix power(matrix A, int N) {
        if (N == 0) {
            return identity();
        }

        matrix X = power(A, N / 2);
        if (N % 2 == 0) {
            return mul(X, X);
        } else {
            return mul(mul(X, X), A);
        }
    }

    int fib(int N) {
        if (N == 0)
            return 0;

        matrix fib;
        fib.mat[0][0] = 1;
        fib.mat[0][1] = 1;
        fib.mat[1][0] = 1;
        fib.mat[1][1] = 0;

        return power(fib, N - 1).mat[0][0];
    }
};