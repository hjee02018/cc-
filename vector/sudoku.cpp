#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

int sudoku[9][9] = { 0 };
// 9 x 9 sudoku

void print()
// sudoku ���
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

void sudoku_ans(int row, int col)
{

    int used_num[9] = { 0 };
    // ����� ���ڰ��� ����

    vector<int> hj;


    for (int i = 0; i < 9; i++)
    {
        if (sudoku[row][i])
            used_num[sudoku[row][i] - 1] = 1;
        if (sudoku[i][col])
            used_num[sudoku[i][col] - 1] = 1;
    }
    // ��� �� �˻�


    int sub_row = row / 3;
    int sub_col = col / 3;
    sub_row *= 3;
    sub_col *= 3;


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sudoku[sub_row][sub_col + j])
                used_num[sudoku[sub_row][sub_col + j] - 1] = 1;
        }
        sub_row++;
    }
    // 3 x 3 box �˻�



    for (int i = 0; i < 9; i++)
    {
        if (!used_num[i]) hj.push_back(i + 1);
    }
    // ��밡���� ���� -> hj vector



    int next_row = row;
    int next_col = col;

    while (true)
    {
        if ((++next_col) == 9)
        {
            next_row++;
            next_col = 0;
            if (next_row == 9) {
                sudoku[row][col] = hj[0];
                print();
                exit(0);
            }
        }
        if (next_row == 9) break;
        if (sudoku[next_row][next_col] == 0) break;
    }


    for (int i = 0; i < hj.size(); i++)
    {
        sudoku[row][col] = hj[i];
        sudoku_ans(next_row, next_col);
        sudoku[row][col] = 0;
    }

}

int main()
{
    freopen("input.txt", "r", stdin);
    int N; // sudoku ������ȣ��
    cin >> N;
    for (int a = 0; a < N; a++)
    {
        // N���� ��������(testcase)


        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cin >> sudoku[i][j];
            }
        }
        // 9 x 9  sudoku �о����

        cout << "sudoku " << a + 1 << endl;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (sudoku[i][j] == 0)
                    // ä������ ������ ��� ��(i,j)
                {
                    sudoku_ans(i, j);
                }
            }
        }


    }

    return 0;
}