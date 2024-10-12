#include "Application.h"
#include <iostream>

Application::Application() {}

Application::~Application() {}

void Application::exec(Polynom& polynom) {
    const char separator[] = "------------------------------------------------------------------------------------------------------------------------";
    const char commands[] = "1) Ввести значения массива с консоли\n"
        "2) Рассчитать среднее и СКО элементов массива\n"
        "3) Отсортировать элементы массива по возрастанию или убыванию\n"
        "4) Изменить размерность массива\n"
        "5) Изменить значение элемента массива\n"
        "s) Вывести текущие элементы массива\n"
        "c) Вывести список команд\n"
        "e) Выход из программы\n";

    char command = 'c';

    do {
        if (command == 'e') {
            std::cout << "Программа была завершена по воле пользователя\n";
            break;
        }
        else if (command == 'c') {
            std::cout << commands;
        }
        else if (command == 's') {
            array.show(std::cout);
        }
        else if (command == '1') {
            array.clear();
            fill();
            std::cout << "Массив был успешно заполнен введёнными значениями\n";
        }
        else if (command == '2') {
            try {
                std::cout << "Среднее значение: " << array.average() << '\n';
                std::cout << "СКО: " << array.MSD() << '\n';
            }
            catch (std::exception& ex) {
                std::cout << "Ошибка при вычислении: " << ex.what() << '\n';
            }
        }
        else if (command == '3') {
            std::cout << "Отсортировать по возрастанию? (y/n): ";
            char isIncreased;
            std::cin >> isIncreased;
            if (isIncreased == 'y') {
                array.sort();
                std::cout << "Элементы массива были успешно отсортированы по возрастанию\n";
                array.show(std::cout);
            }
            else if (isIncreased == 'n') {
                array.sort(true);
                std::cout << "Элементы массива были успешно отсортированы по убыванию\n";
                array.show(std::cout);
            }
            else {
                std::cout << "Вы ввели неправильный символ, массив не был отсортирован\n";
            }
        }
        else if (command == '4') {
            std::cout << "Введите новую размерность текущего массива: ";
            int newCapacity;
            std::cin >> newCapacity;
            resize(newCapacity);
            std::cout << "Размер массива был успешно изменён на " << newCapacity << '\n';
        }
        else if (command == '5') {
            std::cout << "Введите индекс и новое значение элемента массива: ";
            int index;
            number value;
            std::cin >> index >> value;
            try {
                array[index] = value;
                std::cout << "Значение элемента массива с индексом " << index << " было успешно изменено\n";
                array.show(std::cout);
            }
            catch (std::out_of_range& ex) {
                std::cout << "Ошибка: " << ex.what() << '\n';
            }
        }

        std::cout << separator << '\n';
        std::cout << "Введите команду: ";
        std::cin >> command;
        std::cout << '\n';

    } while (true);
}

void Application::fill()
{
    std::string input;
    std::cout << "Введите элементы списка: ";
    std::cin.ignore();  // Пропускаем символ новой строки, оставленный после предыдущего cin
    std::getline(std::cin, input);
    array.fill(input);
}