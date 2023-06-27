#include "Zigzag.h"
#include <iostream>
#include <cmath>

int Solution::get_grid_width(string s, int numRows) {
    // In the special case that numRows == 1, return the length of the string
    if (numRows == 1) {
        return s.length();
    }

    // The patternLength variable stores the number of characters in a zigzag pattern
    double patternLength = 2*numRows - 2;
    
    // The numRepetitions variable stores the number of pattern repetitions
    int numRepetitions = ceil(s.length() / patternLength);
    
    // The patternWidth variable stores the width of a pattern (in terms of number of characters)
    int patternWidth = numRows - 1;
    
    // The gridWidth variable stores the number of columns in the grid
    int gridWidth = numRepetitions * patternWidth;
    
    // We have computed the gridWidth, and now we can return the result
    return gridWidth;
}

char** Solution::create_grid(string s, int numRows, int numCols, char defaultValue) {
    char** grid = new char*[numRows];
    for (int row = 0; row < numRows; row++) {
        grid[row] = new char[numCols];
        for (int col = 0; col < numCols; col++) {
            grid[row][col] = defaultValue;
        }
    }
    return grid;
}

void Solution::populate_grid(string s, char** grid, int numRows, int numCols) {
    int i = 0, row = 0, col = 0;
    int len = s.length();
    while (i < len) {
        for (row = 0; row < numRows && i < len; row++) {
            grid[row][col] = s[i];
            i++;   
        }
        col++;
        for (row = row-2; row > 0 && i < len; row--) {
            grid[row][col] = s[i];
            col++;
            i++;
        }
    }
}

void Solution::print_grid(char** grid, int numRows, int numCols) {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            cout << grid[row][col];
            if (col < numCols - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

string Solution::convert(string s, int numRows) {
    string result;
    int numCols = get_grid_width(s, numRows);
    char** grid = create_grid(s, numRows, numCols, '_');
    populate_grid(s, grid, numRows, numCols);
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            if (grid[row][col] != '_') {
                result += grid[row][col];
            }
        }
    }
    return result;
}
