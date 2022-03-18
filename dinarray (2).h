#ifndef _DINARRAY_H
#define _DINARRAY_H
#include "myInf.h"
int GetSize();
bool Init(char*);
bool Add(info);
bool Delete(int);
bool Replace(int, info);
bool Get(int, info*);
bool Insert (int, info);
bool Save();
#endif