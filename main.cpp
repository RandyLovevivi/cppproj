#include <iostream>
#include <string>
#include <sstream>
using namespace std;
bool cinisnotdigit(string str);
bool cinisnotfloat(string str);

struct matrix{
    int rows,columns;
    float data;
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int rows1, columns1, rows2, columns2;
    string str;
    cout << "Please enter the rows in matrix1: ";
    cin >> str;
    while (cinisnotdigit(str)) {
        cin.clear();
        cin.get();
        cout << "Input Error,Please Enter Again!" << "\n";
        cin >> str;
    }
    istringstream is(str);
    is >> rows1;

    cout << "Please enter the columns in matrix1: ";
    cin >> str;
    while (cinisnotdigit(str)) {
        cin.clear();
        cin.get();
        cout << "Input Error,Please Enter Again!" << "\n";
        cin >> str;
    }
    istringstream is2(str);
    is2 >> columns1;

    cout << "Please enter the rows in matrix2: ";
    cin >> str;
    while (cinisnotdigit(str)) {
        cin.clear();
        cin.get();
        cout << "Input Error,Please Enter Again!" << "\n";
        cin >> str;
    }
    istringstream is3(str);
    is3 >> rows2;

    cout << "Please enter the columns in matrix2: ";
    cin >> str;
    while (cinisnotdigit(str)) {
        cin.clear();
        cin.get();
        cout << "Input Error,Please Enter Again!" << "\n";
        cin >> str;
    }
    istringstream is4(str);
    is4 >> columns2;

    if (columns1 != rows2) {
        cout << "The size of two matrices do not match!" << "\n";
        return 0;
    }
    matrix m1[rows1][columns1], m2[rows2][columns2], m3[rows1][columns2];
    m1[0][0].rows = rows1;
    m1[0][0].columns = columns1;
    m2[0][0].rows = rows2;
    m2[0][0].columns = columns2;
    m3[0][0].rows = rows1;
    m3[0][0].columns = columns2;

    cout << "Please enter matrix 1: " << "\n";
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            string s;
            cin >> s;
            while (cinisnotfloat(s)) {
                cin.clear();
                cin.get();
                cout << "Input Error,Please Enter Again!" << "\n";
                i = 0;
                cin >> s;
            }
            istringstream is(s);
            is >> m1[i][j].data;
        }
    }

    cout << "Please enter matrix 2: " << "\n";
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < columns2; j++) {
            string s;
            cin >> s;
            while (cinisnotfloat(s)) {
                cin.clear();
                cin.get();
                cout << "Input Error,Please Enter Again!" << "\n";
                i = 0;
                cin >> s;
            }
            istringstream is(s);
            is >> m2[i][j].data;
        }
    }
    cout<<"matrix1 is: "<<"\n";
    for (int i = 0; i < rows1; i++){
        for (int j = 0; j < columns1; j++){
            cout<<m1[i][j].data<<" ";
        }
        cout<<"\n";
    }
    cout<<"matrix2 is: "<<"\n";
    for (int i = 0; i < rows2; i++){
        for (int j = 0; j < columns2; j++){
            cout<<m2[i][j].data<<" ";
        }
        cout<<"\n";
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            m3[i][j].data=0;
            for (int k = 0; k < columns1; k++) {
                m3[i][j].data += m1[i][k].data * m2[k][j].data;
            }
        }
    }
    cout<<"The answer is: "<<"\n";
    for (int i = 0; i < rows1; i++){
        for (int j = 0; j < columns2; j++){
            cout<<m3[i][j].data<<" ";
        }
        cout<<"\n";
    }
}

inline bool cinisnotdigit(string str) {
    for (int i = 0;i < str.length();i++) {
        if (!isdigit(str[i]))
            return true;
    }
    return false;
}

inline bool cinisnotfloat(string str) {
    for (int i = 0;i < str.length();i++) {
        if ((!isdigit(str[i]))&&(str[i]!='.') )
            return true;
    }
    return false;
}
