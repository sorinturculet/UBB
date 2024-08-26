#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;
#define inf 10000
int mat[1001][1001], sol[1001][1001];
int main() {
    ifstream fin("C:/eu/ubb/2nd_Semester/grafuri/02_laborator/cerinte/labirint_1.txt");
    ofstream fout("C:/eu/ubb/2nd_Semester/grafuri/02_laborator/cerinte/labirint_1_solve.txt");
    int n = -1, m = -1;
    int i = 0, j = 0;
    pair<int, int> start(0, 0);
    pair<int, int> finish(0, 0);
    char s[1000];
    while (fin.getline(s, 1000)) {

        i++;
        for (j = 0; s[j] != NULL; j++) {
            if (s[j] == '1')
                mat[i][j] = -1, sol[i][j] = -1;
            if (s[j] == 'S')
                mat[i][j] = 1, sol[i][j] = 1, start.first = i, start.second = j;
            if (s[j] == 'F')
                mat[i][j] = inf, sol[i][j] = inf, finish.first = i, finish.second = j; // Set finish point
        }
        n = i, m = j;
    }
    queue<pair<int, int>> q;
    q.push(start);
    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();

        if (i == finish.first && j == finish.second) // Update finish point if reached
            break;

        if (i + 1 <= n && (mat[i + 1][j] == 0 || mat[i + 1][j] == inf)) {
            mat[i + 1][j] = mat[i][j] + 1;
            q.push({i + 1, j});
        }
        if (i - 1 >= 1 && (mat[i - 1][j] == 0 || mat[i - 1][j] == inf)) {
            mat[i - 1][j] = mat[i][j] + 1;
            q.push({i - 1, j});
        }
        if (j + 1 <= m && (mat[i][j + 1] == 0 || mat[i][j + 1] == inf)) {
            mat[i][j + 1] = mat[i][j] + 1;
            q.push({i, j + 1});
        }
        if (j - 1 >= 1 && (mat[i][j - 1] == 0 || mat[i][j - 1] == inf)) {
            mat[i][j - 1] = mat[i][j] + 1;
            q.push({i, j - 1});
        }
    }
    if (mat[finish.first][finish.second] == inf)
        cout << "Labirintul nu poate fi rezolvat";
    else {
        i = finish.first;
        j = finish.second;
        while (i != start.first || j != start.second) { // Use || instead of &&
            sol[i][j] = mat[i][j];
            if (i + 1 <= n && mat[i + 1][j] == mat[i][j] - 1)
                i = i + 1;
            else if (i - 1 >= 1 && mat[i - 1][j] == mat[i][j] - 1) // Use else if instead of if
                i = i - 1;
            else if (j + 1 <= m && mat[i][j + 1] == mat[i][j] - 1) // Use else if instead of if
                j = j + 1;
            else if (j - 1 >= 1 && mat[i][j - 1] == mat[i][j] - 1) // Use else if instead of if
                j = j - 1;
        }

    }

    sol[start.first][start.second] = 1;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            fout << setw(3) <<sol[i][j] << " "; // Add space between characters for better readability
        }
        fout << endl; // Add newline after each row
    }
    return 0;
}
