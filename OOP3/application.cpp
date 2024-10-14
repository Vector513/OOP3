#include "Application.h"
#include <iostream>
#include <string>

Application::Application() {}

Application::~Application() {}

void Application::exec(Polynom& polynom) {
    const char separator[] = "------------------------------------------------------------------------------------------------------------------------";
    const char commands[] = "1) ������ �������� �������� � �������\n"
        "s) ������� ������� �������� �������\n"
        "c) ������� ������ ������\n"
        "e) ����� �� ���������\n";

    std::string command = "c";

    do {
        if (command == "e") {
            std::cout << "��������� ���� ��������� �� ���� ������������\n";
            break;
        }
        else if (command == "c") {
            std::cout << commands;
        }
        else if (command == "s") {
            polynom.show(std::cout, false);
            polynom.show(std::cout);
        }
        else if (command == "1") {
            // 23-4i 24-3i 234 53 53-523i 234 2i
            //polynom.clear();
            std::cout << "������� ����������� An � N �������� ��� ������: ";
            std::cin.ignore();
            std::cin >> polynom.An;
            std::string input;
            std::getline(std::cin, input);
            polynom.fillRoots(input);
            
            std::cout << "������ ��� ������� �������� ��������� ����������\n";
        }
        /*
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

        */

        std::cout << separator << '\n';
        std::cout << "������� �������: ";
        std::cin >> command;
        std::cout << '\n';

    } while (true);
}