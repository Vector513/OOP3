#include "Application.h"
#include <iostream>

Application::Application() {}

Application::~Application() {}

void Application::exec(Polynom& polynom) {
    const char separator[] = "------------------------------------------------------------------------------------------------------------------------";
    const char commands[] = "1) ������ �������� ������� � �������\n"
        "2) ���������� ������� � ��� ��������� �������\n"
        "3) ������������� �������� ������� �� ����������� ��� ��������\n"
        "4) �������� ����������� �������\n"
        "5) �������� �������� �������� �������\n"
        "s) ������� ������� �������� �������\n"
        "c) ������� ������ ������\n"
        "e) ����� �� ���������\n";

    char command = 'c';

    do {
        if (command == 'e') {
            std::cout << "��������� ���� ��������� �� ���� ������������\n";
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
            std::cout << "������ ��� ������� �������� ��������� ����������\n";
        }
        else if (command == '2') {
            try {
                std::cout << "������� ��������: " << array.average() << '\n';
                std::cout << "���: " << array.MSD() << '\n';
            }
            catch (std::exception& ex) {
                std::cout << "������ ��� ����������: " << ex.what() << '\n';
            }
        }
        else if (command == '3') {
            std::cout << "������������� �� �����������? (y/n): ";
            char isIncreased;
            std::cin >> isIncreased;
            if (isIncreased == 'y') {
                array.sort();
                std::cout << "�������� ������� ���� ������� ������������� �� �����������\n";
                array.show(std::cout);
            }
            else if (isIncreased == 'n') {
                array.sort(true);
                std::cout << "�������� ������� ���� ������� ������������� �� ��������\n";
                array.show(std::cout);
            }
            else {
                std::cout << "�� ����� ������������ ������, ������ �� ��� ������������\n";
            }
        }
        else if (command == '4') {
            std::cout << "������� ����� ����������� �������� �������: ";
            int newCapacity;
            std::cin >> newCapacity;
            resize(newCapacity);
            std::cout << "������ ������� ��� ������� ������ �� " << newCapacity << '\n';
        }
        else if (command == '5') {
            std::cout << "������� ������ � ����� �������� �������� �������: ";
            int index;
            number value;
            std::cin >> index >> value;
            try {
                array[index] = value;
                std::cout << "�������� �������� ������� � �������� " << index << " ���� ������� ��������\n";
                array.show(std::cout);
            }
            catch (std::out_of_range& ex) {
                std::cout << "������: " << ex.what() << '\n';
            }
        }

        std::cout << separator << '\n';
        std::cout << "������� �������: ";
        std::cin >> command;
        std::cout << '\n';

    } while (true);
}

void Application::fill()
{
    std::string input;
    std::cout << "������� �������� ������: ";
    std::cin.ignore();  // ���������� ������ ����� ������, ����������� ����� ����������� cin
    std::getline(std::cin, input);
    array.fill(input);
}