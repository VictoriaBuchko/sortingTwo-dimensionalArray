#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

//Сортировка выбором 
void selectionSort(char arr[][50], int n) {

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {

            int result = strcmp(arr[j], arr[minIndex]);//сравнение 2 фамилий( сравниваются текущая фамилии и фамилии с минимальным индексом)

            if (result > 0) {//если 1 фамилия меньше 2   Если измени тут знак на противоположный то сортировка будет по убыванию

                minIndex = j;
            }
        }
        if (minIndex != i) {//присвоение минимальному индексу новое значение(обмен фамилиями)

            char temp[50];
            strcpy_s(temp, arr[i]);
            strcpy_s(arr[i], arr[minIndex]);
            strcpy_s(arr[minIndex], temp);
        }
    }
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int nameOfStudents = 5;//количество фамилий 
    const int maxLength = 50;// максимальное количество символов в каждой фамилии 

    char students[nameOfStudents][maxLength];


    cout << "Введите фамилии 5 студентов:\n";
    for (int i = 0; i < nameOfStudents; i++) {

        cout << "Студент " << i + 1 << ": ";
        cin >> students[i];
    }

    selectionSort(students, nameOfStudents);


    cout << "\nОтсортированные фамилии студентов:\n";
    for (int i = 0; i < nameOfStudents; i++) {

        cout << "Студент " << i + 1 << ": " << students[i] << "\n";
    }

    return 0;
}

