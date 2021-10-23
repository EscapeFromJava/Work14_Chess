#include <iostream>

using namespace std;
const int SIZE = 10;
void printBoard(char m[SIZE][SIZE]);
void checkForCheck(char x, char y, char sym1[], char sym2[]);

int main()
{
    setlocale(LC_ALL, "RUS");
    char board[SIZE][SIZE];//массив доски
    char sym1[] = { 'A','B','C','D','E','F','G','H' };//массив наименований столбцов доски
    char sym2[] = { '8','7','6','5','4','3','2','1' };//массив наименований строк доски
    for (int i = 0; i < SIZE; i++)//цикл заполнения массива доски символами ·
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = '·';
        }
    }
    for (int i = 1; i < SIZE - 1; i++)//маркировка столбцов и строк доски
    {
        board[0][i] = sym1[i - 1];
        board[i][0] = sym2[i - 1];
        board[SIZE - 1][i] = sym1[i - 1];
        board[i][SIZE - 1] = sym2[i - 1];
    }
    for (int i = 1; i < SIZE - 1; i++) { //отображение возможности хода слона и ферзя
        board[i][1] = board[3][i] = board[2][2] = board[4][2] = board[7][2] = board[1][3] = board[5][3] = board[6][3] = board[5][4] = board[6][4] = board[4][5] = board[7][5] = board[8][6] = board[2][7] = board[1][8] = '*';
    }
    board[0][0] = board[0][SIZE - 1] = board[SIZE - 1][0] = board[SIZE - 1][SIZE - 1] = ' ';//углы доски
    board[3][1] = 'Ф';//позиция ферзя
    board[8][1] = 'С';//позиция слона

    printBoard(board);

    cout << "Введите координаты черного короля: ";
    char x, y;
    cin >> x >> y;
    cout << endl;

    //проверка на свободное поле
    if ((x == sym1[0] && y == sym2[7]) || (x == sym1[0] && y == sym2[2])) {
        cout << "Поле занято другой фигурой";
        return 0;
    }

    //проверка на корректность координат
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (x == sym1[i]) {
            count++;
        }
        if (y == sym2[i]) {
            count++;
        }
    }
    if (count != 2) {
        cout << "Неверные координаты";
        return 0;
    }

    //рисуем короля
    for (int i = 1; i < 9; i++) {
        if (x == sym1[i - 1]) {
            for (int j = 1; j < 9; j++) {
                if (y == sym2[j - 1])
                    board[j][i] = 'K';
            }
        }
    }
    printBoard(board);
    checkForCheck(x, y, sym1, sym2);//проверка на шах 
    return 0;
}

void printBoard(char m[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout.width(4);
            cout << m[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void checkForCheck(char x, char y, char sym1[], char sym2[])
{
    int count = 0;
    if (x == sym1[0]) {
        cout << "Шах!";
        count++;
    }
    if (x == sym1[1]) {
        if (y == sym2[1] || y == sym2[2] || y == sym2[3] || y == sym2[6]) {
            cout << "Шах!";
            count++;
        }
    }
    if (x == sym1[2]) {
        if (y == sym2[0] || y == sym2[2] || y == sym2[4] || y == sym2[5]) {
            cout << "Шах!";
            count++;
        }
    }
    if (x == sym1[3]) {
        if (y == sym2[2] || y == sym2[4] || y == sym2[5]) {
            cout << "Шах!";
            count++;
        }
    }
    if (x == sym1[4]) {
        if (y == sym2[2] || y == sym2[3] || y == sym2[6]) {
            cout << "Шах!";
            count++;
        }
    }
    if (x == sym1[5]) {
        if (y == sym2[2] || y == sym2[7]) {
            cout << "Шах!";
            count++;
        }
    }
    if (x == sym1[6]) {
        if (y == sym2[1] || y == sym2[2]) {
            cout << "Шах!";
            count++;
        }
    }
    if (x == sym1[7]) {
        if (y == sym2[0] || y == sym2[2]) {
            cout << "Шах!";
            count++;
        }
    }
    if (count != 1) {
        cout << "Шаха нет!";
    }
}