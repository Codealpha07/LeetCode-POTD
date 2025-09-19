class Spreadsheet {
    vector<vector<int>> grid;
    int rows;
public:
    Spreadsheet(int rows) : rows(rows), grid(rows, vector<int>(26, 0)) {}

    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        grid[row][col] = value;
    }

    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        grid[row][col] = 0;
    }

    int getValue(string formula) {
        auto parse = [&](string s) -> int {
            if (isalpha(s[0])) {
                int col = s[0] - 'A';
                int row = stoi(s.substr(1)) - 1;
                return grid[row][col];
            }
            return stoi(s);
        };
        formula = formula.substr(1); // remove '='
        size_t plus = formula.find('+');
        string left = formula.substr(0, plus);
        string right = formula.substr(plus + 1);
        return parse(left) + parse(right);
    }
};