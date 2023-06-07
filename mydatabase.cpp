#include "mydatabase.h"

mydatabase::mydatabase(std::string& Server, std::string& Database, unsigned int& Port, std::string& User, std::string& Password, std::string& Unix_socket, unsigned long& Client_flag)
{
	server = Server;
	database = Database;
	port = Port;
	user = User;
	password = Password;
	unix_socket = Unix_socket;
	//unix_socket = "NULL";
	client_flag = Client_flag;
	std::cout << "\nPriskyrimai \n";
	connect = mysql_init(NULL);

}
mydatabase::~mydatabase()
{

	mysql_close;
}
void mydatabase::showerrors(MYSQL* Connect)
{
	std::cerr << mysql_error(connect) << '\n';
	exit(1);
}
void mydatabase::connectTo()
{

	std::cout << "Connecting...\n";
	if (!mysql_real_connect(connect, server.c_str(), user.c_str(), password.c_str(), database.c_str(), port, unix_socket.c_str(), client_flag))
	{
		showerrors(connect);
		std::cerr << mysql_error(connect) << std::endl;
		std::cout << "Not Connected\n";
		exit(1);
	}
	std::cout << "Connected\n";
}
void mydatabase::runQuery(std::string SQLquery)
{
	sqlquery = SQLquery;

	if (mysql_query(connect, sqlquery.c_str()))
	{
		showerrors(connect);
	}
}
void mydatabase::showtables()
{
	if (mysql_query(connect, "Show tables"))
	{
		showerrors(connect);
	}
	MYSQL_RES* res = mysql_use_result(connect);
	std::cout << "MySQL Tables in mysql database:\n";
	while ((row = mysql_fetch_row(res)) != NULL)
		std::cout << "\n" << row[0];
	std::cout << '\n';
	mysql_free_result(res);
}
void mydatabase::mysqlinfo() {
	std::cout << "\nMySQL client: " << mysql_get_client_info() << std::endl;
	std::cout << "\nMySQL server: " << mysql_get_server_info(connect) << std::endl;
}
void mydatabase::showResultOfThisQuery(std::string SQLquery) {
	result = nullptr;
	sqlquery = SQLquery;

	if (mysql_query(connect, sqlquery.c_str()))
	{
		showerrors(connect);
	}
	result = mysql_store_result(connect);
	if (result == NULL)
	{
		showerrors(connect);
	}
	int num_fields = mysql_num_fields(result);
	row = NULL;
	while ((row = mysql_fetch_row(result)))
	{
		for (int i = 0; i < num_fields; i++)
		{
			std::cout << (row[i] ? row[i] : "NULL") << " ";
		}
		std::cout << "\n";
	}

}