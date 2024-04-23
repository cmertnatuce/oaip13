#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <locale>
#include <windows.h>
#include <queue> // Для использования очереди

using namespace std;

const int MAX = 100; // Максимальное количество деталей

// Структура для хранения информации о детали
struct Detail {
    string name;
    float cost = 0;
    float size = 0;
    float weight = 0;
};

// Функция для ввода данных о детали
void enter(Detail& detail) {
    cout << "Введите название детали: ";
    cin >> detail.name;
    cout << "Введите стоимость детали: ";
    cin >> detail.cost;
    cout << "Введите размер детали: ";
    cin >> detail.size;
    cout << "Введите вес детали: ";
    cin >> detail.weight;
}

void print(queue<Detail> detailsQueue) {
    if (!detailsQueue.empty()) {
        cout << "----------------------------------------------------------------------------------------------------------\n";
        cout << setw(20) << "Название детали" << setw(20) << "Стоимость" << setw(20) << "Размер" << setw(20) << "Вес" << endl;
        cout << "----------------------------------------------------------------------------------------------------------\n";
        while (!detailsQueue.empty()) {
            Detail detail = detailsQueue.front();
            cout << setw(20) << detail.name << setw(20) << detail.cost << setw(20) << detail.size << setw(20) << detail.weight << endl;
            detailsQueue.pop();
        }
        cout << "----------------------------------------------------------------------------------------------------------\n";
    }
    else {
        cout << "\nОчередь деталей пуста.\n";
    }
}
    

// Функция для сохранения информации о деталях в файл
void save(Detail results[], int numResults) {
    if (numResults > 0) {
        ofstream outFile("details.txt");
        if (outFile.is_open()) {
            outFile << "Название детали" << setw(20) << "Стоимость" << setw(20) << "Размер" << setw(20) << "Вес" << endl;
            for (int i = 0; i < numResults; ++i) {
                outFile << results[i].name << setw(20) << results[i].cost << setw(20) << results[i].size << setw(20) << results[i].weight << endl;
            }
            outFile.close();
            cout << "Информация о деталях сохранена в файле 'details.txt'.\n";
        }
        else {
            cout << "Невозможно открыть файл для записи.\n";
        }
    }
    else {
        cout << "Нет информации о деталях для сохранения.\n";
    }
}


int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Rus");

    queue<Detail> detailsQueue; // Очередь для хранения данных о деталях

    int choice;

    do {
        cout << "\nМеню выбора:\n";
        cout << "1. Ввести данные о детали\n";
        cout << "2. Вывести информацию о деталях\n";
        cout << "3. Сохранить информацию о деталях в файл\n";
        cout << "4. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (detailsQueue.size() < MAX) {
                cout << "\nВведите данные о детали:\n";
                Detail newDetail;
                enter(newDetail);
                detailsQueue.push(newDetail);
            }
            else {
                cout << "Очередь деталей заполнена.\n";
            }
            break;
        case 2:
            if (!detailsQueue.empty()) {
                print(detailsQueue);
            }
            else {
                cout << "Очередь деталей пуста.\n";
            }
            break;
        case 3:
            if (!detailsQueue.empty()) {
                ofstream outFile("details.txt");
                if (outFile.is_open()) {
                    outFile << "Название детали" << setw(20) << "Стоимость" << setw(20) << "Размер" << setw(20) << "Вес" << endl;
                    while (!detailsQueue.empty()) {
                        Detail currentDetail = detailsQueue.front();
                        outFile << currentDetail.name << setw(20) << currentDetail.cost << setw(20) << currentDetail.size << setw(20) << currentDetail.weight << endl;
                        detailsQueue.pop();
                    }
                    outFile.close();
                    cout << "Информация о деталях сохранена в файле 'details.txt' в виде таблицы.\n";
                }
                else {
                    cout << "Невозможно открыть файл для записи.\n";
                }
            }
            else {
                cout << "Очередь деталей пуста. Нет информации для сохранения.\n";
            }
            break;
            break;
        case 4:
            cout << "Выход.\n";
            break;
        default:
            cout << "Неверный выбор.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}
