#include <iostream>
#ifndef MYFUNCS_H
#define MYFUNCS_H

using namespace std;

void console_input();

void file_input();

void cels_to_farenheit(double* farenheit, long &n);

string add_space(int &amount_of_space);

int number_width(int number);

void console_output(double* to_out, long &n);

void file_output(double* to_out, long &n);

#endif