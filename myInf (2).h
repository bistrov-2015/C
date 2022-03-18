#ifndef _MYINF_H_
#define _MYINF_H_
#include <iostream>
#include <time.h>
using namespace std;
struct my_s{
	int nomer;
	char name_author[35];
	char surname_initials[12];
	time_t datout;//char datin[20];
	time_t datin;//char datout[20];
	};

typedef my_s info;
ostream& operator<<(std::ostream& os, const info& val);
istream& operator>>(std::istream& is, info& val);

#endif
