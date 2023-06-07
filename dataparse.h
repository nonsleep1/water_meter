#pragma once
#ifndef DATAPARSE_H
#define DATAPARSE_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>


class dataparse
{
public:
	dataparse(int howmanytimestolookfor);
	~dataparse();
	void datafromfile(std::ifstream &fromFILE, std::string &SourceofWebPage);
	void intregexline(std::string& line, std::string& lookfor, int& found);
	void datafromvariable(std::string &SourceofWebpage);
	void datafromvariable_old(std::string& SourceofWebpage);
	int getnumber();
	
private:
	std::ifstream fromFILE;
	std::string SourceofWebPage, findTHIS, regexsearch;
	int HTimesDoloop;
	int intnumber;
};
#endif // !DATAPARSE_H
