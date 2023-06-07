#pragma once
#ifndef MYDATABASE_H
#define MYDATABASE_H
#include <iostream>
#include <mysql/mysql.h>
#include <string>

class mydatabase
{
private:
	MYSQL* connect{};
	MYSQL_ROW row{};
	MYSQL_RES* result{};
	std::string server{};
	unsigned int port{};
	std::string database{};
	std::string user{};
	std::string password{};
	std::string unix_socket{};
	unsigned long client_flag{};
	std::string sqlquery{};


public:

	~mydatabase();
	mydatabase(std::string& Server, std::string& Database, unsigned int& Port, std::string& User, std::string& Password, std::string& Unix_socket, unsigned long& Client_flag);
	void showerrors(MYSQL* Connect);
	void connectTo();
	void runQuery(std::string SQLquery);
	void showtables();
	void mysqlinfo();
	void showResultOfThisQuery(std::string SQLquery);

};



#endif // !MYDATABASE_H
