#include <iostream>
#include <string>
using namespace std;

long long itc_len(string s) {
	long long l = 0;
	char c = s[l];
	while (c != '\0') {
		l++;
		c = s[l];
	}
	return l;
}

bool itc_isChar(unsigned char c) {
	return (((65 <= c) && (c <= 90)) || ((97 <= c) && (c <= 122)) || ((192 <= c) && (c <= 255)));
}

bool itc_isDigit(unsigned char c) {
	return ((48 <= c) && (c <= 57));
}

unsigned char itc_toUpper(unsigned char c) {
	if ((97 <= c) && (c <= 122)) {
		c -= 32;
	}
	return c;
}

unsigned char itc_changeCase(unsigned char c) {
	if ((97 <= c) && (c <= 122)) {
		c -= 32;
	}
	else if ((65 <= c) && (c <= 90)) {
		c += 32;
	}
	return c;
}

bool itc_ñompare(string s1, string s2) {
	bool is_com = 1;
	int x = itc_len(s1);
	if (x != itc_len(s2))
		return 0;
	for (int i = 0; i < x; i++) {
		if (s1[i] != s2[i]) {
			is_com = 0;
			break;
		}
	}
	return is_com;
}

int itc_countWords(string str) {
	int count = 0;
	//int len = itc_len(str);
	bool word = 0, space = 1;
	for (int i = 0; str[i] != '\0'; i++) {
		if (itc_isChar(str[i]) && space) {
			word = 1;
			space = 0;
		}
		else if ((str[i] == ' ') && word) {
			word = 0;
			space = 1;
			count++;
		}
		if (!(itc_isChar(str[i]))) {
			word = 0;
		}
	}
	if (word)
		count++;
	return count;
}

char itc_sameChar(string str) {
	bool ch[256];
	for (int i = 0; i < 256; i++) {
		ch[i] = 0;
	}
	for (int i = 0; str[i] != '\0'; i++) {
		if (ch[str[i]] == 0) {
			ch[str[i]] = 1;
		}
		else {
			return str[i];
		}
	}
}

bool itc_isFirstInSecond(string s1, string s2) {
	int l1 = itc_len(s1), l2 = itc_len(s2);
	if (l1 < l2)
		return 0;
	for (int i = 0; i <= l1 - l2; i++) {
		if (s1[i] == s2[0]) {
			bool v = 1;
			for (int j = 1; j < l2; j++) {
				i++;
				if (s1[i] != s2[j]) {
					v = 0;
					break;
				}
			}
			if (v)
				return 1;
		}
	}
	return 0;
}

string itc_Cezar(string str, int k) {
	k %= 26;
	for (int i = 0; str[i] != '\0'; i++) {
		str[i] += k;
		if (str[i] < 'a')
			str[i] += 26;
		if (str[i] > 'z')
			str[i] -= 26;
	}
	return str;
}

string itc_rmFreeSpace(string str) {
	bool word = 1;
	int a = 0, n = 0;
	string s = "";
	for (int i = 0; str[i] == ' '; i++) {
		n++;
	}
	for (int i = n; str[i] != '\0'; i++) {
		if (str[i] != ' ') {
			s += str[i];
			a++;
			word = 1;
		}
		if ((str[i] == ' ') && word) {
			s += ' ';
			a++;
			word = 0;
		}
	}
	str = "";
	if (s[a - 1] == ' ') {
		for (int i = 0; i < a - 1; i++) {
			str += s[i];
		}
	}
	else
		str = s;
	return str;
}

bool itc_isIp(string str) {
	string p[4];
	p[0] = "";
	p[1] = "";
	p[2] = "";
	p[3] = "";
	int j = 0, t = 0;
	bool b = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '.') {
			t++;
			j++;
		}
		else {
			p[j] += str[i];
		}
	}
	if (t != 3)
		return 0;
	for (int i = 0; i < 4; i++) {
		if ((itc_len(p[i]) > 3) || (itc_len(p[i]) == 0)) {
			return 0;
		}
		if ((p[i] > "255") && (itc_len(p[i]) == 3))
			return 0;
		for (int j = 0; j < itc_len(p[i]); j++)
			if (!(itc_isDigit(p[i][j])))
				return 0;
	}
	return 1;
}