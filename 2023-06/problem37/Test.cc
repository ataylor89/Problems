#include "Zigzag.h"
#include <iostream>

void test_get_grid_width(string str, int numRows) {
    cout << "Testing get_grid_width function..." << endl;
    Solution s; 
    int gridWidth = s.get_grid_width(str, numRows);
    printf("Grid dimensions: %d rows x %d columns\n", numRows, gridWidth);
    cout << "Finished test" << endl << endl;
}

void test_create_grid(string str, int numRows) {
    cout << "Testing create_grid function..." << endl;
    Solution s;
    int numCols = s.get_grid_width(str, numRows);
    char defaultValue = '_';
    char** grid = s.create_grid(str, numRows, numCols, defaultValue);
    s.print_grid(grid, numRows, numCols);
    cout << "Finished test" << endl << endl;
}

void test_populate_grid(string str, int numRows) {
    cout << "Testing populate_grid function..." << endl;
    Solution s;
    int numCols = s.get_grid_width(str, numRows);
    char defaultValue = '_';
    char** grid = s.create_grid(str, numRows, numCols, defaultValue);
    s.populate_grid(str, grid, numRows, numCols);
    s.print_grid(grid, numRows, numCols);
    cout << "Finished test" << endl << endl;
}

void test_convert(string str, int numRows) {
    cout << "Testing convert function..." << endl;
    Solution s;
    string result = s.convert(str, numRows);
    cout << "Result: " << result << endl;
    cout << "Finished test " << endl;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <string> <numRows>\n", argv[0]);
        return 0;
    }
    string str = argv[1];
    int numRows = atoi(argv[2]);
    cout << "String: " << str << endl;
    cout << "Num rows: " << numRows << endl << endl;
    test_get_grid_width(str, numRows);
    test_create_grid(str, numRows);
    test_populate_grid(str, numRows);
    test_convert(str, numRows);
    return 0;
}
