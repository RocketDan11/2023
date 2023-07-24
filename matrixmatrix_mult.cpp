#include <iostream>
#include <vector>
#include <chrono>
#define TESTCASE 16



std::vector<std::vector<int>> generateTestMatrix(int n, int m) {
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));

    // Fill the matrix with a specific pattern or values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Generate matrix elements based on your test case requirements
            matrix[i][j] = (i + 1) * (j + 1);  // Example: Element = (row + 1) * (column + 1)
        }
    }

    return matrix;
}
// Function to multiply two matrices
std::vector<std::vector<int>> matrixMultiply(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int rows_A = A.size();
    int cols_A = A[0].size();
    int cols_B = B[0].size();

    std::vector<std::vector<int>> C(rows_A, std::vector<int>(cols_B, 0));

    for (int i = 0; i < rows_A; i++) {
        for (int j = 0; j < cols_B; j++) {
            for (int k = 0; k < cols_A; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

int main() {
    // Example matrices A and B
    std::vector<std::vector<int>> A = generateTestMatrix(TESTCASE,TESTCASE) ;
    std::vector<std::vector<int>> B = generateTestMatrix(TESTCASE,TESTCASE) ;
    //start timer
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<int>> result = matrixMultiply(A,B) ;
    //stop timer
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the elapsed time
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    // Output the elapsed time
    std::cout << "Elapsed time: " << duration << " milliseconds" << std::endl;


    /*
    // Output the result
    for (const auto& row : result) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
    */
    return 0;
}