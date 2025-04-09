#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "matrix.hpp"

//Templated function called "load_matrices_from_file" that reads in matrices from a file.
//Parameters: String variable called "filename" and two Matrix objects called "m1" and "m2".
template<typename T>
void load_matrices_from_file(const std::string &filename, Matrix<T> &m1, Matrix<T> &m2) {
    //First open the file with ifstream function with the filename passed in.
    std::ifstream file(filename);
    //If there is an error with opening the file, then throw an error.
    if (!file) {
        //Display "Error opening file: " with the filename.
        std::cerr << "Error opening file: " << filename << '\n';
        //Exits the program
        exit(1);
    }

    //Variable called "N" to read in the first value from the file.
    std::size_t N;
    //Integer variable called "type_flag" to read in the type of variables for the matrices.
    int type_flag;
    //Reads the first value as well as the type_flag.
    file >> N >> type_flag;
    //Initialize the first two matrices with NxN matrices filled with zeros.
    std::vector<std::vector<T>> mat1(N, std::vector<T>(N));
    std::vector<std::vector<T>> mat2(N, std::vector<T>(N));

    //For loop that passes in the data from the file and stores it in the first matrix (mat1).
    for (std::size_t i = 0; i < N; ++i)
        for (std::size_t j = 0; j < N; ++j)
            file >> mat1[i][j];

    //For loop that passes in the data from the file and stores it in the second matrix (mat2).
    for (std::size_t i = 0; i < N; ++i)
        for (std::size_t j = 0; j < N; ++j)
            file >> mat2[i][j];

    //Sets matrix 1 (mat1) to the object Matrix(data1) (Which is the matrix now filled with data)
    m1 = Matrix<T>(mat1);
    //Sets matrix 2 (mat2) to the object Matrix(data2) (Which is the matrix now filled with data).
    m2 = Matrix<T>(mat2);
}

int main(int argc, char *argv[]) {
    //Error checks with the input file.
    //Will exit the program for both checks if the file fails to open.
    if (argc != 2) {
        //Displays "Usage: ./matrix <input_file>" and the file it tries.
        std::cerr << "Usage: ./matrix <input_file>\n";
        return 1;
    }

    std::ifstream test(argv[1]);
    if (!test.is_open()) {
        //Displays "Cannot open file.".
        std::cerr << "Cannot open file.\n";
        return 1;
    }

    //Variable called "N" for the first value from the file.
    std::size_t N;
    //Integer variable called "type_flag" for the type of variables in the matrices.
    int type_flag;
    //Reads in the test, N, and type_flag to start reading in the file.
    test >> N >> type_flag;
    test.close();  //Close after reading header; reopen in loader.

    //A check to see the tye of variables in the matrices.
    //If the type_flag is 0, then the variables are integers.
    if (type_flag == 0) {
        //Creates two matrix object called "A" and "B" with N passed in to initialize both matrices with zeros.
        Matrix<int> A(N), B(N);
        //Loads the matrices from the file with a call to the load_matrices_from_file function. 
        load_matrices_from_file(argv[1], A, B);

        //Displays both matrices with the print_matrix property. 
        std::cout << "Matrix A:\n";
        A.print_matrix();
        std::cout << "\nMatrix B:\n";
        B.print_matrix();

        //Matrix addition problem.
        //Displays "A + B:" with the addition of A and B.
        //After the operation has been completed, a call to the print_matrix property is done.
        std::cout << "\nA + B:\n";
        (A + B).print_matrix();

        //Matrix multiplication problem.
        //Displays "A * B:" with the addition of A and B.
        //After the operation has been completed, a call to the print_matrix property is done.
        std::cout << "\nA * B:\n";
        (A * B).print_matrix();

        //Diagonal sums problem to display the sum of the main and secondary diagonal elements of the matrices.
        //Displays "Main diagonal sum of A: " with a call to A's sum_diagonal_major property. (Main diagonal).
        std::cout << "\nMajor diagonal of A: " << A.sum_diagonal_major() << '\n';
        //Displays "Secondary diagonal sum of A: " with a call to A's sum_diagonal_minor property. (Secondary diagonal).
        std::cout << "Minor diagonal of A: " << A.sum_diagonal_minor() << '\n';

        //Swap rows problem.
        //Swap rows 0 and 1 for matrix A with the swap_rows property.
        //Print the result using the print_matrix property.
        std::cout << "\nSwapping rows 0 and 1 in A:\n";
        A.swap_rows(0, 1);
        A.print_matrix();

        //Swap columns problem.
        //Swap columns 0 and 1 for matrix B with the swap_cols property.
        //Print the result using the print_matrix property.
        std::cout << "\nSwapping columns 0 and 1 in B:\n";
        B.swap_cols(0, 1);
        B.print_matrix();

        //Updating matrix A with the element 99 in place of row 2 and column 3 using set_value property.
        //Print the resulting matrix with print_matrix.
        std::cout << "\nUpdating A[2][3] to 99:\n";
        A.set_value(2, 3, 99);
        A.print_matrix();

    } else if (type_flag == 1) { //Else if the type_flag was 1, then the variables are double.
        //Creates two matrix object called "A" and "B" with N passed in to initialize both matrices with zeros.
        Matrix<double> A(N), B(N);
        //Loads the matrices from the file with a call to the load_matrices_from_file function. 
        load_matrices_from_file(argv[1], A, B);

        //Displays both matrices with the print_matrix property. 
        std::cout << "Matrix A:\n";
        A.print_matrix();
        std::cout << "\nMatrix B:\n";
        B.print_matrix();

        //Matrix addition problem.
        //Displays "A + B:" with the addition of A and B.
        //After the operation has been completed, a call to the print_matrix property is done.
        std::cout << "\nA + B:\n";
        (A + B).print_matrix();

        //Matrix multiplication problem.
        //Displays "A * B:" with the addition of A and B.
        //After the operation has been completed, a call to the print_matrix property is done.
        std::cout << "\nA * B:\n";
        (A * B).print_matrix();

        //Diagonal sums problem to display the sum of the main and secondary diagonal elements of the matrices.
        //Displays "Main diagonal sum of A: " with a call to A's sum_diagonal_major property. (Main diagonal).
        std::cout << "\nMajor diagonal of A: " << A.sum_diagonal_major() << '\n';
        //Displays "Secondary diagonal sum of A: " with a call to A's sum_diagonal_minor property. (Secondary diagonal).
        std::cout << "Minor diagonal of A: " << A.sum_diagonal_minor() << '\n';

        //Swap rows problem.
        //Swap rows 0 and 1 for matrix A with the swap_rows property.
        //Print the result using the print_matrix property.
        std::cout << "\nSwapping rows 0 and 1 in A:\n";
        A.swap_rows(0, 1);
        A.print_matrix();

        //Swap columns problem.
        //Swap columns 0 and 1 for matrix B with the swap_cols property.
        //Print the result using the print_matrix property.
        std::cout << "\nSwapping columns 0 and 1 in B:\n";
        B.swap_cols(0, 1);
        B.print_matrix();

        //Updating matrix A with the element 9.99 in place of row 2 and column 3 using set_value property.
        //Print the resulting matrix with print_matrix.
        std::cout << "\nUpdating A[2][3] to 9.99:\n";
        A.set_value(2, 3, 9.99);
        A.print_matrix();
    } else { //Else, the type_flag was not a part of the values given.
        //Display "Invalid type flag. Use 0 for int, 1 for double.".
        std::cerr << "Invalid type flag. Use 0 for int, 1 for double.\n";
        return 1;
    }

    return 0;
}
