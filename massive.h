#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

template <typename T>
void InputElements(vector<T> &mass) {   // ������ ����� ��������� ������� � ����������
    mass.clear();   // ������� ��������� ������
    string kol;
    cout << "Enter quantity of elements: ";
    cin >> kol;      // ������ ������ ������� � ���� ������
    cin.ignore(32767, '\n');    // ������� ������
    
    for (unsigned __int8 j = 0; j < kol.length() ; j++) {   // ��������� ������������ �����
        if (  !((kol[j] >= '0') && ( kol[j] <= '9')) )      // ���� �� �����, �� ������� ����������
            throw invalid_argument("Incorrect value of array size.");
    }
    
    __int8 size = stoi(kol);    // �������������� ������ ������� �� string � int
    for (__int8 i = 0; i < size; i++) {     // ��������� ������
        cout << "Enter element: " << endl;
        cin >> kol;     // ���������������� ��� ������
        cin.ignore(32767, '\n');    // ������� ������
        for (unsigned __int8 s = 0; s < kol.length(); s++) { // ��������� ������������ �����
            if (!((kol[s] >= '0') && (kol[s] <= '9'))) {  // ���� � ������� ������ �� �����

             if (kol[s] == '-' && s != 0) // ���� ����� �� ������ �������, �� ������� ����������
                throw invalid_argument("Incorrect value of element.");
            else if (kol[s] == '.' && !((kol[s + 1] >= '0') && (kol[s + 1] <= '9')) && kol[s - 1] != '-') {
                s++;
                // ������� ����������, ���� ����� � ������ �� ����� �� �����
                throw invalid_argument("Incorrect value of element.");
            }
            }
        }
        T a = (T)stof(kol); //������������� �������� �������� �� string � ������������ ����
        mass.push_back(a);  // �������� ������� � ������
    }
    return;
}

template <typename T>
void GenerateArray(vector<T> &mass) {   // ������ �������� ���������� �������
    mass.clear();   // ������� ������
    srand(time(NULL));  
    int arr_size = rand()%10 + 1; // ������ ������� �� 1 �� 10
    T elem;

    for (unsigned __int8 i = 0; i < arr_size; i++) {    
        elem = (T)( ( rand() % 100 - 50) / 1.23);   // ��������� �������� �������� �� -50/1.23 �� 50/1.23 ����������� � ������������ ����
        mass.push_back(elem);   // �������� ������� � ������
    }
    return;

}

template <typename T>
T FindBiggest(vector<T> mass) { // ������ ������ ����������� �� ������ �������� �������
  
    if (mass.size() == 0) throw invalid_argument("Empty array.");

    T big = NULL;
   
    for (unsigned __int8 i = 0; i < mass.size(); i++) {
        if (abs(mass[i]) > big) { 
            big = abs(mass[i]);
        }
    }

    return big;

}

template <typename T>
void OutputVector(vector<T> mass) { // ������ ������ �������
    cout << "Current array: ";
    for (T n : mass)
        cout << n << " ";
    cout << endl;

}

template <typename T>
T SummBetween(vector<T> mass) { // ������ ������ ����� ����� ����� �������������� ����������
   
    T summ = NULL;
    unsigned __int8 i = 0;

    if (mass.size() == 0) throw invalid_argument("Empty array.");

    while ((mass[i] < 0) && (i < mass.size()-1)) 
        i++;    // ������� ������ ������������� �������
    if (i == mass.size()-1) return 0;
    ++i;    // ��������� � ���������� �������� ����� ��������������
    while (( i < mass.size() ) && (mass[i] < 0) ){ 
    // ��������� �������� ���� �� �������� ������������� ������� ��� �� ������ �� ����� �������
        summ += mass[i];
        ++i;
    }

    return summ;
}

template <typename T>
void SortArray(vector<T> &mass) { // ������ ����������� ����� � ����� �������
    unsigned __int8 j = 0;         // ������� ���������� �����
    
    if (mass.size() == 0) throw invalid_argument("Empty array.");
    
    for (unsigned __int8 i = 0; i  < mass.size() - j; i++) // �������� �� ������� (����� ��������� ����������, ���� ��� �������)
    {
        if (mass[i] == 0)   // ���� ������� ��������� ����
        {
            j++;            // ��������� ������� �����
            mass[i] = mass[mass.size() - j];    // ������� ������� ������ ��������� ������ �� ��������
            mass[mass.size() - j] = 0;          // � �������� ��������� ����
        }
    }
    if (j == 0)     // ���� � ������� ��� �����, �� ������� ���������
        cout << "There is no zero elements." << endl;
    return;
}

template <typename T>
void menu(vector<T>& mass) { // ������ ���� ��� ������� ������ � ���������
   char k;
    
    do {
        cout    << "1 - Enter array." << endl       // ������ ������
                << "2 - Generate random array." << endl // ������� ������ �� ��������������� �����
                << "3 - Find absolutely biggest element." << endl   // ����� ���������� �� ������ �������
                << "4 - Summ between two positive number." << endl // ����� ����� ����� ����� �������������� ��-��
                << "5 - Put zero in the end of array." << endl  // ����������� ���� � ����� �������
                << "6 - Choose another type of array." << endl; // ������� ������, ��������� �� ��-�� ������ �����

        cin >> k;
        cin.ignore(32767, '\n');    // ������� �������
        if (!isdigit(k)) throw invalid_argument("Incorrect command."); // �������� �����
        switch ((int)k - (int)'0') {    // ������������ char � int

        case 1: // ������ ������
            InputElements(mass);
            OutputVector(mass); // ������� ������
            break;

        case 2: // ������� ������ �� ��������������� �����
            GenerateArray(mass);
            OutputVector(mass);
            break;

        case 3: // ����� ���������� �� ������ �������
            OutputVector(mass);
            cout << "Biggest element: " << FindBiggest(mass) << std::endl;
            break;

        case 4: // ����� ����� ����� ����� �������������� ��-��
            OutputVector(mass);
            cout << "Summ between two positive elemnts: " << SummBetween(mass) << endl;
            break;

        case 5: // ����������� ���� � ����� �������
            OutputVector(mass);
            SortArray(mass);
            OutputVector(mass);
            break;

        case 6: // ������� ������, ��������� �� ��-�� ������ �����
            mass.clear();   // ������� ������, ��������� �� ��-�� ������ ����� ������� ������
            break;

        default:
            cout << "Wrong command." << endl;
        }

    } while ((int)k - (int)'0' != 6);

}


