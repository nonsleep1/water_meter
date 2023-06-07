#include "myconfig.h"

myconfig::myconfig() {
	
	
}
myconfig::~myconfig() {

}
int myconfig::loadfile(std::string const &filename) {
	try
	{
		cfg.readFile(filename.c_str()); 
		
	}
	catch (const libconfig::FileIOException& fioex)
	{
		std::cerr << "I/O error while reading file." << std::endl;
		return(EXIT_FAILURE);
	}
	catch (const libconfig::ParseException& pex)
	{
		std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
			<< " - " << pex.getError() << std::endl;
		return(EXIT_FAILURE);
	}
	return 0;
}
void myconfig::loadurl(std::string& url) {  //looks for url of scada web page
	try
	{
		std::string TempUrl = cfg.lookup("myURL");
		url = TempUrl;

		std::cout << "URL: " << url << std::endl << std::endl;
	}
	catch (const libconfig::SettingNotFoundException& nfex)
	{
		std::cerr << "No 'Url' setting in configuration file." << std::endl;
	}
}
void myconfig::loadmysql(std::string& host, std::string& database, std::string& username,
	std::string& password, std::string& unix_socket, unsigned int& port, unsigned long& client_flag) {
	//looks for mysql login info
	try
	{
		std::string TempHost = cfg.lookup("host");
		host = TempHost;
		std::cout << "Host name: " << host << std::endl << std::endl;
	}
	catch (const libconfig::SettingNotFoundException& nfex)
	{
		std::cerr << "No 'host' setting in configuration file." << std::endl;
	}
	try
	{
		std::string TempDatabase = cfg.lookup("database");
		database = TempDatabase;
		std::cout << "Database: " << database << std::endl << std::endl;
	}
	catch (const libconfig::SettingNotFoundException& nfex)
	{
		std::cerr << "No 'database' setting in configuration file." << std::endl;
	}
	try
	{
		std::string TempUsername = cfg.lookup("username");
		username = TempUsername;
		std::cout << "Username: " << username << std::endl << std::endl;
	}
	catch (const libconfig::SettingNotFoundException& nfex)
	{
		std::cerr << "No 'username' setting in configuration file." << std::endl;
	}
	try
	{
		std::string TempPassword = cfg.lookup("password");
		password = TempPassword;
		std::cout << "Password: " << password << std::endl << std::endl;
	}
	catch (const libconfig::SettingNotFoundException& nfex)
	{
		std::cerr << "No 'password' setting in configuration file." << std::endl;
	}
	try
	{
		std::string TempPort = cfg.lookup("port");
		port = std::stoi(TempPort);
		std::cout << "Port: " << port << std::endl << std::endl;
	}
	catch (const libconfig::SettingNotFoundException& nfex)
	{
		std::cerr << "No 'port' setting in configuration file." << std::endl;
	}
	try
	{
		std::string TempUnix_socket = cfg.lookup("unix_socket");
		unix_socket = TempUnix_socket;
		std::cout << "Unix socket: " << unix_socket << std::endl << std::endl;
	}
	catch (const libconfig::SettingNotFoundException& nfex)
	{
		std::cerr << "No 'unix_socket' setting in configuration file." << std::endl;
	}
	try
	{
		std::string  TempFlag = cfg.lookup("client_flag");
		client_flag = std::stol(TempFlag);
		std::cout << "Client flag: " << client_flag << std::endl << std::endl;
	}
	catch (const libconfig::SettingNotFoundException& nfex)
	{
		std::cerr << "No 'flag' setting in configuration file." << std::endl;
	}
	
}