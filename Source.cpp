/*
    ��������� ������� �� ���� ����������� ��������, ������� ������ ����� ������� � ���� ������� �������.
    ��� ����������� ������ ��� ������� ������ ������������ �� � �������� ����������.
    ������������� ���������� ���������� � �������� �� �����������.
    �������� ������� ��������, ������������ ��� ������� ��� ����� int, float � double.
    �������������� ������� �� ��������!

    ������� 9
� ���������� �������, ��������� �� � ���������, ���������:
    1) ������������ �� ������ ������� �������;
    2) ����� ��������� �������, ������������� ����� ������ � ������ �������������� ����������.
    3) ������������� ������ ����� �������, ����� ��������, ������ ����, ������������� ����� ����
���������.

*/

#include <stdexcept>
#include "massive.h"



int main() {
    vector<int> mass1 = {0};
    vector<double> mass2 = { 0 };
    vector<float> mass3 = { 0 };
    char k;

    try {
        do {
            cout << "Choose type of mass(or press 4 to exit programm): \n1 - int \n2 - double \n3 - float" << endl;
            cin >> k;
            cin.ignore(32767, '\n');        // ������� ������� ������
            if (!isdigit(k)) throw invalid_argument("Incorrect command.");
            switch ((int)k - (int)'0') {

            case 1:
                menu(mass1);    // ������ int 
                break;
            case 2:
                menu(mass2);    // ������ double
                break;
            case 3:
                menu(mass3);    // ������ float
                break;
            case 4:
                break;          // ����� �� ���������
            
            default:
                cout << "Wrong command." << endl;
            }
        } while ((int)k-(int)'0' != 4);
    }
    catch(invalid_argument& error) {    // ����� ������
        cout << "Error: " << error.what() << endl;
    }


    return 0;
}