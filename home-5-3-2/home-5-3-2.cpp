#include <iostream>

template<typename T>
class Table {
private:
    T** data;
    int rows;
    int cols;
    Table(const Table&) = delete;
    Table& operator=(const Table&) = delete;
public:
    Table(int rows, int cols) : rows{ rows }, cols{ cols } {

        data = new T * [rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
        }
    }

    ~Table() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    const T& operator[](int row) const {
        return data[row][0];
    }

    T& operator[](int row) {
        return data[row][0];
    }

    T& at(int row, int col) {
        return data[row][col];
    }

    int size() {
        return  rows * cols;
    }

};

int main() {
    Table<int> table(2, 3);

    table.at(0, 0) = 4;
    std::cout << table.at(0, 0) << std::endl;
    std::cout << table.size();

    return 0;
}
