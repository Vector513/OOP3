#include "Application.h"
#include <iostream>
#include <string>
#include <limits>

Application::Application() {}

Application::~Application() {}

void Application::exec(Polynom& polynom)
{
    const char separator[] = "------------------------------------------------------------------------------------------------------------------------";
    const char commands[] =
        "1) Ввести значения полинома с консоли\n"
        "2) Изменить коэффициент An или корень по индексу\n"
        "3) Вычислить значение полинома в точке\n"
        "4) Изменить размерность массива корней\n"
        "s) Вывести полином в форме 1 или 2\n"
        "c) Вывести список команд\n"
        "e) Выход из программы\n";

    std::string command = "c";

    do {
        if (command == "e") {
            std::cout << "Программа завершена.\n";
            break;
        }
        else if (command == "c") {
            std::cout << commands;
        }
        else if (command == "s") {
            std::string form;
            std::cout << "Вывести полином в форме 1 или 2 (введите 1 или 2): ";
            std::getline(std::cin, form);
            if (form == "1") {
                polynom.show(std::cout);
            }
            else if (form == "2") {
                polynom.show(std::cout, false);
            }
            else {
                std::cerr << "Ошибка: неверная форма вывода.\n";
            }
        }
        else if (command == "1") {
            std::cout << "Введите коэффициент An и N значений его корней: ";
            number An;
            std::cin >> An;
            polynom.setAn(An);
            std::string input;
            std::getline(std::cin, input);
            polynom.fillRoots(input);
            std::cout << "Массив корней успешно заполнен введёнными значениями.\n";
        }
        else if (command == "2") {
            std::cout << "Введите, что изменить (An/индекс корня): ";
            std::string changeOption;
            std::getline(std::cin, changeOption);

            if (changeOption == "An") {
                std::cout << "Введите новое значение An: ";
                number newAn;
                std::cin >> newAn;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                polynom.setAn(newAn);
            }
            else {
                try {
                    size_t index = std::stoul(changeOption);
                    if (index < polynom.getDegree()) {
                        number newRoot;
                        std::cout << "Введите новое значение для корня с индексом " << index << ": ";
                        std::cin >> newRoot;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        polynom.setRoot(index, newRoot);
                    }
                    else {
                        std::cerr << "Ошибка: неверный индекс корня.\n";
                    }
                }
                catch (const std::invalid_argument&) {
                    std::cerr << "Ошибка: неверный формат индекса.\n";
                }
            }
        }
        else if (command == "3") {
            number x;
            std::cout << "Введите значение точки x для вычисления полинома: ";
            std::cin >> x;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            number result = polynom.evaluate(x);
            std::cout << "Значение полинома в точке " << x << ": " << result << '\n';
        }
        else if (command == "4") {
            size_t newSize;
            std::cout << "Введите новую размерность массива корней: ";
            std::cin >> newSize;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            polynom.resize(newSize);
            std::cout << "Размер массива корней изменён на " << newSize << ".\n";
        }
        else {
            std::cout << "Неправильная команда! Попробуйте снова.\n";
        }

        std::cout << separator << '\n';
        std::cout << "Введите команду: ";
        std::getline(std::cin, command);

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод! Попробуйте снова.\n";
            command = "c";
        }

    } while (true);
}
