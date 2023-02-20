#include <iostream>
#include <string>
#include <fstream>
#include "myconsts.h"

using namespace std;

long console_input()
{
    while(true)
    {
        string input;
        long n;
        cout << "Введите значение n: ";
        getline(cin, input);
        try
        {
            n = stoi(input);
        }
        catch(const std::exception& e)
        {
            cout << "Значение некорректно! n - целое число." << endl;
            continue;
        }

        if (n < 0)
        {
            cout << "Значение некорректно! n - натуральное число." << endl;
            continue;
        }
        return n;
    }
    return -1;
}

long file_input()
{
    while(true)
    {
        ifstream input("input.txt");
        if (!input)
        {
            cout << "Файл не создан! Создайте файл input.txt в директории с программой." << endl
            << "Затем перезапустите программу и попробуйте ещё раз." <<endl << endl;
            exit(1);
        }
        long n;
        string line;
        getline(input, line);
        try
        {
            n = stoi(line);
        }
        catch(const std::exception& e)
        {
            cout << "Значение некорректно! n - целое число." << endl
            << "Вставьте нужное число в файл и перезапустите программу." << endl << endl;
            exit(1);
        }

        if (n < 0)
        {
            cout << "Значение некорректно! n - натуральное число." << endl 
            << "Вставьте нужное число в файл и перезапустите программу." << endl << endl;
            exit(1);
        }
        return n;
    }
    return -1;
}

void cels_to_farenheit(double* farenheit, long n)
{
    for (int t = 0; t < n+1; t++)
        farenheit[t] = 1.8*t + 32;
}

string add_space(int amount_of_space)
{
    string space;
    for (int i = 0; i < amount_of_space; i++ )
        space += " ";
    return space;
}

int number_width(int number)
{
    if (number == 0)
        return 1;
    
    int width;
    
    while (number > 0)
    {
        number /= 10;
        width += 1;
    }

    return width;
}

void console_output(double* to_out, long &n)
{
    cout << table_head << endl;
    for (int i = 0; i < n + 1; i++)
    {
        cout << i << add_space((coulmn_width[0] - number_width(i)))
        << to_out[i] << add_space((coulmn_width[1] - number_width(i))) << endl;  
    } 
}

void file_output(double* to_out, long &n)
{
    ofstream output("output.txt");
    for (int i = 0; i < n + 1; i++)
    {
        output << i << add_space((coulmn_width[0] - number_width(i)))
        << to_out[i] << add_space((coulmn_width[1] - number_width(i))) << endl;  
    }
}