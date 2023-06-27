#include <string>
using namespace std;

class Solution {
public:
    int get_grid_width(string s, int numRows);
    char** create_grid(string s, int numRows, int numCols, char defaultValue);
    void populate_grid(string s, char** grid, int numRows, int numCols);
    void print_grid(char** grid, int numRows, int numCols);
    string convert(string s, int numRows);
};
