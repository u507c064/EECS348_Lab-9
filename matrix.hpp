#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <iostream>
#include <iomanip>
#include <cstdint> 
#include <vector>
#include <stdexcept>

template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;

public:
    Matrix(std::size_t N) : data(N, std::vector<T>(N, T())) {}

    //Constructor that initilizes the matrix with the values passed in from the parameter.
    //The parameter is the vector of integers called "nums".
    Matrix(std::vector<std::vector<T>> nums) : data(std::move(nums)) {}

    //The addition operator called "operator+" that takes in a Matrix object called "rhs".
    Matrix operator+(const Matrix &rhs) const {
        std::size_t N = get_size();
        if (N != rhs.get_size()) throw std::invalid_argument("Matrix sizes must match for addition.");
        Matrix result(N);
        for (std::size_t i = 0; i < N; ++i)
            for (std::size_t j = 0; j < N; ++j)
                result.data[i][j] = data[i][j] + rhs.data[i][j];
        return result;
    }

    //The multiplication operator called "operator*" that takes in a Matrix object called "rhs".
    Matrix operator*(const Matrix &rhs) const {
        std::size_t N = get_size();
        if (N != rhs.get_size()) throw std::invalid_argument("Matrix sizes must match for multiplication.");
        Matrix result(N);
        for (std::size_t i = 0; i < N; ++i)
            for (std::size_t j = 0; j < N; ++j)
                for (std::size_t k = 0; k < N; ++k)
                    result.data[i][j] += data[i][k] * rhs.data[k][j];
        return result;
    }

    //Function called "set_value" which takes in the parameters "i", "j", and an integer variable called "n".
    //Sets the value of an individual element in the matrix to the value n.
    void set_value(std::size_t i, std::size_t j, T n) {
        if (i >= get_size() || j >= get_size()) throw std::out_of_range("Invalid indices.");
        data[i][j] = n;
    }

    //Function called "get_value" which returns the value at given element in the matrix.
    T get_value(std::size_t i, std::size_t j) const {
        if (i >= get_size() || j >= get_size()) throw std::out_of_range("Invalid indices.");
        return data[i][j];
    }

    //Function called "get_size" which returns the size of the matrix.
    std::size_t get_size() const {
        return data.size();
    }

    //Function called "sum_diagonal_major" which sums up the diagonal elements in the matrix.
    T sum_diagonal_major() const {
        T sum = T();
        for (std::size_t i = 0; i < get_size(); ++i)
            sum += data[i][i];
        return sum;
    }

    //Function called "sum_diagonal_minor" which sums up the second diagonal of the matrix.
    T sum_diagonal_minor() const {
        T sum = T();
        std::size_t N = get_size();
        for (std::size_t i = 0; i < N; ++i)
            sum += data[i][N - i - 1];
        return sum;
    }

    //Function called "swap_rows" which swaps two rows in the matrix.
    void swap_rows(std::size_t r1, std::size_t r2) {
        if (r1 >= get_size() || r2 >= get_size()) throw std::out_of_range("Invalid row indices.");
        std::swap(data[r1], data[r2]);
    }

    //Function called "swap_cols" which swaps two columns in the matrix.
    void swap_cols(std::size_t c1, std::size_t c2) {
        if (c1 >= get_size() || c2 >= get_size()) throw std::out_of_range("Invalid column indices.");
        for (std::size_t i = 0; i < get_size(); ++i)
            std::swap(data[i][c1], data[i][c2]);
    }

    void print_matrix() const {
        for (const auto& row : data) {
            for (const auto& val : row)
                std::cout << std::setw(6) << val;
            std::cout << '\n';
        }
    }
};

#endif // __MATRIX_HPP__
