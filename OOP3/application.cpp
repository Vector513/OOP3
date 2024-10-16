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
        "1) ������ �������� �������� � �������\n"
        "2) �������� ����������� An ��� ������ �� �������\n"
        "3) ��������� �������� �������� � �����\n"
        "4) �������� ����������� ������� ������\n"
        "s) ������� ������� � ����� 1 ��� 2\n"
        "c) ������� ������ ������\n"
        "e) ����� �� ���������\n";

    std::string command = "c";

    do {
        if (command == "e") {
            std::cout << "��������� ���������.\n";
            break;
        }
        else if (command == "c") {
            std::cout << commands;
        }
        else if (command == "s") {
            std::string form;
            std::cout << "������� ������� � ����� 1 ��� 2 (������� 1 ��� 2): ";
            std::getline(std::cin, form);
            if (form == "1") {
                polynom.show(std::cout);
            }
            else if (form == "2") {
                polynom.show(std::cout, false);
            }
            else {
                std::cerr << "������: �������� ����� ������.\n";
            }
        }
        else if (command == "1") {
            std::cout << "������� ����������� An � N �������� ��� ������: ";
            number An;
            std::cin >> An;
            polynom.setAn(An);
            std::string input;
            std::getline(std::cin, input);
            polynom.fillRoots(input);
            std::cout << "������ ������ ������� �������� ��������� ����������.\n";
        }
        else if (command == "2") {
            std::cout << "�������, ��� �������� (An/������ �����): ";
            std::string changeOption;
            std::getline(std::cin, changeOption);

            if (changeOption == "An") {
                std::cout << "������� ����� �������� An: ";
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
                        std::cout << "������� ����� �������� ��� ����� � �������� " << index << ": ";
                        std::cin >> newRoot;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        polynom.setRoot(index, newRoot);
                    }
                    else {
                        std::cerr << "������: �������� ������ �����.\n";
                    }
                }
                catch (const std::invalid_argument&) {
                    std::cerr << "������: �������� ������ �������.\n";
                }
            }
        }
        else if (command == "3") {
            number x;
            std::cout << "������� �������� ����� x ��� ���������� ��������: ";
            std::cin >> x;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            number result = polynom.evaluate(x);
            std::cout << "�������� �������� � ����� " << x << ": " << result << '\n';
        }
        else if (command == "4") {
            size_t newSize;
            std::cout << "������� ����� ����������� ������� ������: ";
            std::cin >> newSize;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            polynom.resize(newSize);
            std::cout << "������ ������� ������ ������ �� " << newSize << ".\n";
        }
        else {
            std::cout << "������������ �������! ���������� �����.\n";
        }

        std::cout << separator << '\n';
        std::cout << "������� �������: ";
        std::getline(std::cin, command);

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "������������ ����! ���������� �����.\n";
            command = "c";
        }

    } while (true);
}
