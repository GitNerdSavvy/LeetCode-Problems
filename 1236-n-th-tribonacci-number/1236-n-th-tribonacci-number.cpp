class Solution {
public:
    class matrix {
public:
    int mat[3][3];
};
matrix mul(matrix A, matrix B) {
    matrix c;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            int t = 0;

            for (int i = 0; i < 3; i++) {
                t += A.mat[row][i] * B.mat[i][col];
            }
            c.mat[row][col] = t;
        }
    }
    return c;
}

matrix identity() {
    matrix A;
    A.mat[0][0] = 1;
    A.mat[0][1] = 0;
    A.mat[0][2] = 0;
    A.mat[1][0] = 0;
    A.mat[1][1] = 1;
    A.mat[1][2] = 0;
    A.mat[2][0] = 0;
    A.mat[2][1] = 0;
    A.mat[2][2] = 1;
    return A;
}

matrix power(matrix trib, int n) {
    if (n == 0)
        return identity();
    matrix x = power(trib, n / 2);
    if (n & 1) {
        return mul(mul(x, x), trib);
    } else {
        return mul(x, x);
    }
}
    int tribonacci(int n) {
        if(n==0) return 0;
        matrix trib;
        trib.mat[0][0] = 1, trib.mat[0][1] = 1, trib.mat[0][2] = 1;
        trib.mat[1][0] = 1, trib.mat[1][1] = 0, trib.mat[1][2] = 0;
        trib.mat[2][0] = 0, trib.mat[2][1] = 1, trib.mat[2][2] = 0;
        return power(trib, n-1).mat[0][0];
    }
};