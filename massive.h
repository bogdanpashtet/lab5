#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

template <typename T>
void InputElements(vector<T> &mass) {   // шаблон ввода элементов массива с клавиатуры
    mass.clear();   // очищаем имеющийся массив
    string kol;
    cout << "Enter quantity of elements: ";
    cin >> kol;      // вводим размер массива в виде строки
    cin.ignore(32767, '\n');    // очищаем буффер
    
    for (unsigned __int8 j = 0; j < kol.length() ; j++) {   // проверяем корректность ввода
        if (  !((kol[j] >= '0') && ( kol[j] <= '9')) )      // если не цифра, то вызвать исключение
            throw invalid_argument("Incorrect value of array size.");
    }
    
    __int8 size = stoi(kol);    // конвертировать размер массива из string в int
    for (__int8 i = 0; i < size; i++) {     // заполняем массив
        cout << "Enter element: " << endl;
        cin >> kol;     // считываемэлемент как строку
        cin.ignore(32767, '\n');    // очищаем буффер
        for (unsigned __int8 s = 0; s < kol.length(); s++) { // проверяем корректность ввода
            if (!((kol[s] >= '0') && (kol[s] <= '9'))) {  // если в элемент строки не цифра

             if (kol[s] == '-' && s != 0) // если минус не первый элемент, то вызвать исключение
                throw invalid_argument("Incorrect value of element.");
            else if (kol[s] == '.' && !((kol[s + 1] >= '0') && (kol[s + 1] <= '9')) && kol[s - 1] != '-') {
                s++;
                // вызвать исключение, если слева и справа от точки не цифры
                throw invalid_argument("Incorrect value of element.");
            }
            }
        }
        T a = (T)stof(kol); //преобразовать значение элемента из string к необходимому типу
        mass.push_back(a);  // добавить элемент в массив
    }
    return;
}

template <typename T>
void GenerateArray(vector<T> &mass) {   // шаблон создания случайного массива
    mass.clear();   // очищаем массив
    srand(time(NULL));  
    int arr_size = rand()%10 + 1; // размер массива от 1 до 10
    T elem;

    for (unsigned __int8 i = 0; i < arr_size; i++) {    
        elem = (T)( ( rand() % 100 - 50) / 1.23);   // случайное значение элемента от -50/1.23 до 50/1.23 приведенное к необходимому типу
        mass.push_back(elem);   // добавить элемент в массив
    }
    return;

}

template <typename T>
T FindBiggest(vector<T> mass) { // шаблон поиска наибольшего по модулю элемента массива
  
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
void OutputVector(vector<T> mass) { // шаблон вывода вектора
    cout << "Current array: ";
    for (T n : mass)
        cout << n << " ";
    cout << endl;

}

template <typename T>
T SummBetween(vector<T> mass) { // шаблон поиска суммы между двумя положительными элементами
   
    T summ = NULL;
    unsigned __int8 i = 0;

    if (mass.size() == 0) throw invalid_argument("Empty array.");

    while ((mass[i] < 0) && (i < mass.size()-1)) 
        i++;    // находим первый положительный элемент
    if (i == mass.size()-1) return 0;
    ++i;    // переходим к следующему элементу после положительного
    while (( i < mass.size() ) && (mass[i] < 0) ){ 
    // суммируем элементы пока не встретим положительный элемент или не дойдем до конца массива
        summ += mass[i];
        ++i;
    }

    return summ;
}

template <typename T>
void SortArray(vector<T> &mass) { // шаблон перемещения нулей в конец массива
    unsigned __int8 j = 0;         // счетчик количества нулей
    
    if (mass.size() == 0) throw invalid_argument("Empty array.");
    
    for (unsigned __int8 i = 0; i  < mass.size() - j; i++) // проходим по массиву (кроме последних элемментов, еслм они нулевые)
    {
        if (mass[i] == 0)   // если элемент равняется нулю
        {
            j++;            // итнрируем счетчик нулей
            mass[i] = mass[mass.size() - j];    // текущий элемент теперь равняется одному из конечных
            mass[mass.size() - j] = 0;          // а конечный равняется нулю
        }
    }
    if (j == 0)     // если в массиве нет нулей, то вывести сообщение
        cout << "There is no zero elements." << endl;
    return;
}

template <typename T>
void menu(vector<T>& mass) { // шаблон меню для удобной работы с массивами
   char k;
    
    do {
        cout    << "1 - Enter array." << endl       // ввести массив
                << "2 - Generate random array." << endl // создать массив из псевдослучайных чисел
                << "3 - Find absolutely biggest element." << endl   // найти наибольший по модулю элемент
                << "4 - Summ between two positive number." << endl // найти сумму между двумя положительными эл-ми
                << "5 - Put zero in the end of array." << endl  // переместить нули в конец массива
                << "6 - Choose another type of array." << endl; // выбрать массив, состоящий из эл-ов других типов

        cin >> k;
        cin.ignore(32767, '\n');    // очищаем буфферр
        if (!isdigit(k)) throw invalid_argument("Incorrect command."); // проверка ввода
        switch ((int)k - (int)'0') {    // конвертируем char в int

        case 1: // ввести массив
            InputElements(mass);
            OutputVector(mass); // выводим массив
            break;

        case 2: // создать массив из псевдослучайных чисел
            GenerateArray(mass);
            OutputVector(mass);
            break;

        case 3: // найти наибольший по модулю элемент
            OutputVector(mass);
            cout << "Biggest element: " << FindBiggest(mass) << std::endl;
            break;

        case 4: // найти сумму между двумя положительными эл-ми
            OutputVector(mass);
            cout << "Summ between two positive elemnts: " << SummBetween(mass) << endl;
            break;

        case 5: // переместить нули в конец массива
            OutputVector(mass);
            SortArray(mass);
            OutputVector(mass);
            break;

        case 6: // выбрать массив, состоящий из эл-ов других типов
            mass.clear();   // выбрать массив, состоящий из эл-ов других типов очищаем массив
            break;

        default:
            cout << "Wrong command." << endl;
        }

    } while ((int)k - (int)'0' != 6);

}


