#include <string>
#include <iostream>
using namespace std;

#ifndef STR_MIDDLE_H_INCLUDED
#define STR_MIDDLE_H_INCLUDED

bool itc_isDigit(unsigned char);

unsigned char itc_toUpper(unsigned char);

unsigned char itc_changeCase(unsigned char);

bool itc_ñompare(string, string);

int itc_countWords(string);

char itc_sameChar(string);

bool itc_isFirstInSecond(string, string);

string itc_Cezar(string, int);

string itc_rmFreeSpace(string);

bool itc_isIp(string);

#endif