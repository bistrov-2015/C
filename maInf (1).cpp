#include "myInf.h"
#include <iostream>
#include <iomanip>
#include <time.h>
#include <ctime>
#include <stdio.h>
    //struct tm{
   //    int     tm_sec;         /* секунды */
    //    int     tm_min;         /* минуты */
     //   int     tm_hour;        /* часы */
    //    int     tm_mday;        /* день мес€ца */
    //    int     tm_mon;         /* мес€ц */
   //     int     tm_year;        /* год */
  //      };
    tm tmin, tmout;
    time_t in, out;
    time_t tm_datout = out;
    time_t tm_datin = in;


ostream& operator<<(std::ostream& os, const info& val){

    int bill = in-out;
    cout << "___________________________________________________________" << endl;
	return os << "| " << setw(3) <<
	val.nomer << "| "<< setw(3) << std::left <<
	val.name_author << " | " <<
	val.surname_initials << " | " <<
	val.datout<< " | " <<
	val.datin  << " | " <<
	ctime(&tm_datout) << " | " <<
	ctime(&tm_datin) << " | bill: " <<
	bill << " |\n___________________________________________________________" << endl;
}

istream& operator>>(std::istream& is, info& val){
	cout << "nomer ";
	is >> val.nomer;
	cout << "name_author ";
	is >> val.name_author;
	cout << "surname_initials ";
	is >> val.surname_initials;

	///Issuing a book:
	cout << "Book issue date (year.month.day)" << endl;
	cout << "year: ";
	is >> tmout.tm_year;
	tmout.tm_year-=tmout.tm_year-1900;
	cout << "month: ";
	is >> tmout.tm_mon;
	tmout.tm_mon-=1;
	cout << "day: ";
	is >> tmout.tm_mday;
	tm_datout = mktime(&tmout);

	///Book return date:
	cout << "Date of return of the book (year.month.day)" << endl;
    cout << "year: ";
	is >> tmin.tm_year;
	tmin.tm_year-=tmin.tm_year-1900;
	cout << "month: ";
	is >> tmin.tm_mon;
	tmin.tm_mon-=1;
	cout << "day: ";
	is >> tmin.tm_mday;
	tm_datin = mktime(&tmin);
	return is;
}
