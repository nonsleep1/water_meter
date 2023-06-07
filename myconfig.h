#pragma once
#ifndef CONFIG_H
#define CONFIG_H
#include <iostream>
#include <string>

#include <libconfig.h++>

class myconfig
{
private:
	libconfig::Config cfg{};
	std::string myurl{};
	std::string host{};
	std::string database{};
	std::string username{};
	std::string password{};
	std::string unix_socket{};
	unsigned int port{};
	unsigned long client_flag{};


public:
	myconfig();
	~myconfig();
	int loadfile(std::string const& filename);
	void loadurl(std::string &url);
	void loadmysql(std::string& host, std::string& database, std::string& username, 
		std::string& password, std::string& unix_socket, unsigned int& port, unsigned long& client_flag);

};
#endif // !CONFIG_H
