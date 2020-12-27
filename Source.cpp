/*
    Выполнить задание на тему «Одномерные массивы», оформив каждый пункт задания в виде шаблона функции.
    Все необходимые данные для функций должны передаваться им в качестве параметров.
    Использование глобальных переменных в функциях не допускается.
    Привести примеры программ, использующих эти шаблоны для типов int, float и double.
    Дополнительные массивы не заводить!

    Вариант 9
В одномерном массиве, состоящем из п элементов, вычислить:
    1) максимальный по модулю элемент массива;
    2) сумму элементов массива, расположенных между первым и вторым положительными элементами.
    3) преобразовать массив таким образом, чтобы элементы, равные нулю, располагались после всех
остальных.

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
            cin.ignore(32767, '\n');        // очищаем входной буффер
            if (!isdigit(k)) throw invalid_argument("Incorrect command.");
            switch ((int)k - (int)'0') {

            case 1:
                menu(mass1);    // массив int 
                break;
            case 2:
                menu(mass2);    // массив double
                break;
            case 3:
                menu(mass3);    // массив float
                break;
            case 4:
                break;          // выход из программы
            
            default:
                cout << "Wrong command." << endl;
            }
        } while ((int)k-(int)'0' != 4);
    }
    catch(invalid_argument& error) {    // ловим ошибки
        cout << "Error: " << error.what() << endl;
    }


    return 0;
}