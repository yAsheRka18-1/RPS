#include "class.h"
#include "interface.h"
#include <fstream>
#include "getinfo.h"

/// <summary>
/// Главная функция, в которой реализовано все пользовательское меню с выбором заполнения массива.
/// </summary>
int main() {
    // Переменные для управления меню ввода, сохранения и выбора сохраненного массива
    int actionMenuForInput = 1;
    int actionSavingMenu = 1;
    int actionWitchOneSave = 1;

    // Вектор для хранения массива и размер массива
    vector<int> arr;
    vector<int> res;
    int sizeOfArr = 0;
    QuickSort sort;

    // Вывод границ и задачи программы
    Borders();
    Task();
    Borders();


    // Основной цикл программы
    while (actionMenuForInput) {
        // Вывод меню выбора способа ввода
        MenuForInput();
        actionMenuForInput = static_cast<int>(GetInt("Choose an option:  "));
        // Переменная для хранения имени файла
        string name = "";

        // Поток для записи в файл
        fstream fout;
        switch (actionMenuForInput) {

        case MenuForInput::console:
            // Ввод массива с консоли
            sizeOfArr = static_cast<int>(GetInt("Enter array size :  "));
            cout << "\n";
            ConcoleInput(arr, sizeOfArr);  //ввод массива с клавиатуры'
            res = arr;
            cout << "\nOriginal array\n";
            PrintArr(arr);                 //вывод элементов массива в консоль
            cout << sort.NameOfSort();     // Вывод названия метода сортировки.
            sort.Sort(res);   // Вызов метода сортировки.
            PrintArr(res);   // Вывод отсортированного массива.

            // Вложенный цикл для выбора опции сохранения
            while (actionSavingMenu) {
                SavingMenu();
                actionSavingMenu = static_cast<int>(GetInt("Choose an option:  "));

                switch (actionSavingMenu) {
                case SavingMenu::savetofile:
                    // Вложенный цикл для выбора опции сохранения массива
                    while (actionWitchOneSave) {
                        WitchOneSave();
                        actionWitchOneSave = static_cast<int>(GetInt("Choose an option:  "));

                        switch (actionWitchOneSave) {
                        case WitchOneSave::original:
                            SaveOriginalArr(arr);
                            actionWitchOneSave = 0;
                            break;
                        case WitchOneSave::sorted:
                            SaveSortedArr(res);
                            actionWitchOneSave = 0;
                            break;
                        case WitchOneSave::backToSaving:  
                            actionWitchOneSave = 0;
                            break;
                        default:
                            cout << "Incorect option! Try enter again!" << endl;
                            cin >> actionSavingMenu;
                            break;
                        }
                    }

                    actionWitchOneSave = 1;
                    actionSavingMenu = 0;
                    break;

                case SavingMenu::backToInput:
                    actionSavingMenu = 0;
                    break;

                default:
                    cout << "Incorect option! Try enter again!" << endl;
                    cin >> actionSavingMenu;
                    break;
                }
            }

            actionSavingMenu = 1;
            break;

        case MenuForInput::file:
            // Ввод массива из файла

            cout << "Enter the name of the file: ";
            cin >> name;

            if (FileInput(arr, name)) {
                cout << "\nOriginal array\n";
                res = arr;
                PrintArr(arr);
                cout << sort.NameOfSort();   // Вывод названия метода сортировки.
                sort.Sort(res);   // Вызов метода сортировки.
                PrintArr(res);   // Вывод отсортированного массива.
            }
            else {
                actionSavingMenu = 0;
            }

            // Вложенный цикл для выбора опции сохранения
            while (actionSavingMenu) {
                SavingMenu();
                actionSavingMenu = static_cast<int>(GetInt("Choose an option: "));

                switch (actionSavingMenu) {
                case SavingMenu::savetofile:
                    // Вложенный цикл для выбора опции сохранения массива
                    while (actionWitchOneSave) {
                        WitchOneSave();
                        actionWitchOneSave = static_cast<int>(GetInt("Choose an option: "));

                        switch (actionWitchOneSave) {
                        case WitchOneSave::original:
                            SaveOriginalArr(arr);
                            actionWitchOneSave = 0;
                            break;
                        case WitchOneSave::sorted:
                            SaveSortedArr(res);
                            actionWitchOneSave = 0;
                            break;
                        case WitchOneSave::backToSaving:
                            actionWitchOneSave = 0;
                            break;
                        default:
                            cout << "Incorect option! Try enter again!" << endl;
                            cin >> actionSavingMenu;
                            break;
                        }
                    }

                    actionWitchOneSave = 1;
                    actionSavingMenu = 0;
                    break;
                case SavingMenu::backToInput:
                    actionSavingMenu = 0;
                    break;
                default:
                    cout << "Incorect option! Try enter again!" << endl;
                    cin >> actionSavingMenu;
                    break;
                }
            }

            actionSavingMenu = 1;
            break;
        case MenuForInput::random:
            // Генерация случайного массива
            sizeOfArr = static_cast<int>(GetInt("Enter array size :  "));
            cout << "\n";
            RandomInput(arr, sizeOfArr);
            res = arr;
            cout << "\nOriginal array\n";
            PrintArr(arr);
            cout << sort.NameOfSort();   // Вывод названия метода сортировки.
            sort.Sort(res);   // Вызов метода сортировки.
            PrintArr(res);   // Вывод отсортированного массива.

            // Вложенный цикл для выбора опции сохранения
            while (actionSavingMenu) {
                SavingMenu();
                actionSavingMenu = static_cast<int>(GetInt("Choose an option: "));

                switch (actionSavingMenu) {
                case SavingMenu::savetofile:
                    // Вложенный цикл для выбора опции сохранения массива
                    while (actionWitchOneSave) {
                        WitchOneSave();
                        actionWitchOneSave = static_cast<int>(GetInt("Choose an option: "));

                        switch (actionWitchOneSave) {
                        case WitchOneSave::original:
                            SaveOriginalArr(arr);
                            actionWitchOneSave = 0;
                            break;
                        case WitchOneSave::sorted:
                            SaveSortedArr(res);
                            actionWitchOneSave = 0;
                            break;
                        case WitchOneSave::backToSaving:
                            actionWitchOneSave = 0;
                            break;
                        default:
                            cout << "Incorect option! Try enter again!" << endl;
                            cin >> actionSavingMenu;
                            break;
                        }
                    }

                    actionWitchOneSave = 1;
                    actionSavingMenu = 0;
                    break;

                case SavingMenu::backToInput:
                    actionSavingMenu = 0;
                    break;
                default:
                    cout << "Incorect option! Try enter again!" << endl;
                    cin >> actionSavingMenu;
                    break;
                }
            }

            actionSavingMenu = 1;
            break;

        case MenuForInput::quit:
            cout << "Programm finished its work!" << endl;
            return EXIT_SUCCESS;
        default:
            cout << "\nIncorect option! Try enter again!\n\n";
            break;
        }
    }
}

