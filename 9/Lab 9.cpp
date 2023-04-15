#include <iostream>
#include <fstream>
#include <string>
using  namespace std;

int main()
{
    system("chcp 1251");
    system("cls");
    string row;
    int num = 1, cnt = 1, len_s = 0;
    ifstream in;
    ofstream out;
    in.open("F1.txt");
    cout << "Содержимое F1" << endl;
    while (!in.eof()) {
        getline(in, row);
        cout << row << endl;
    }
    cout << endl;
    in.close();
    in.open("F1.txt");
    out.open("F2.txt");
    while (!in.eof()) {
        getline(in, row);
        if (num >= 4) {
            out << row << endl;
        }
        num++;
    }
    in.close();
    out.close();
    ifstream in2;
    in2.open("F2.txt");
    cout << "Содержимое F2" << endl;
    while (!in2.eof()) {
        getline(in2, row);
        cout << row << endl;
    }
    in2.close();
    in2.open("F2.txt");
    string row_last;
    while (cnt < num - 4) {
        getline(in2, row);
        if (row != " ") row_last = row;
        cnt++;
    }
    string word_last;
    for (int i = 0; i < row_last.length(); i++) {
        if (row_last[i] != ' ') {
            word_last += row_last[i];
        }
        else word_last = "";
    }
    len_s = word_last.length();
    cout << "Количество символов последнего слова = " << len_s << endl;
    return 0;
}
