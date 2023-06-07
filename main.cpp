#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


#include "dataparse.h"
#include "mycurl.h"
#include "mydatabase.h"
#include "myconfig.h"

#include <chrono>
#include <ctime>





void giveyday(unsigned int& Nyear, unsigned int& Nmonth, unsigned int& Nday) { //it's not completed, but i don't think we reach year of 2400

	Nday -= 1;
	if (Nday == 0) {
		Nmonth -= 1;
		if (Nmonth == 0) {
			Nyear -= 1;
			Nmonth = 12;
		}
		if ((Nmonth == 7) || (Nmonth == 1) || (Nmonth == 3) || (Nmonth == 5) || (Nmonth == 8)
			|| (Nmonth == 10) || (Nmonth == 12)) {
			Nday = 31;
		}
		else if ((Nmonth == 4) || (Nmonth == 6) || (Nmonth == 9) || (Nmonth == 11)) {
			Nday = 30;
		}
		else if (Nmonth == 2) {
			if ((Nyear % 4) == 0) {
				Nday = 29;
			}
			else {
				Nday = 28;
			}
		}

	}
}
void timenow(unsigned int &nowYear, unsigned int &nowMonth, unsigned int &nowDay) {
	
	std::time_t rawtime;
	struct tm timeinfo;
	std::time(&rawtime);
	localtime_s(&timeinfo, &rawtime); //localtimes_s for windows _r for linux, simple localtimes is not safe for vs studio
	nowYear = timeinfo.tm_year + 1900;
	nowMonth = timeinfo.tm_mon + 1;
	nowDay = timeinfo.tm_mday;
}
int main()
{
	myconfig VandConfig{};
	
	std::string myurl{};
	VandConfig.loadfile("config.cfg");
	VandConfig.loadurl(myurl);
	std::string vandenustring{};
	unsigned int year{}, month{}, day{}, rodmuo{};
	
	timenow(year, month, day); //returns date of today in int
	giveyday(year, month, day); //returns date of yesterday in int
	
	

	mycurl vandenuURL(myurl,day,month,year);
	vandenuURL.gotourl();
	vandenustring = vandenuURL.getData();
	
	dataparse vandenudata(4);
	vandenudata.datafromvariable(vandenustring);
	std::cout << "Vandenu skaicius: " << vandenudata.getnumber();
	rodmuo = vandenudata.getnumber();
	//-------------------------------------------------------------------

	//------------------------mysql login information------------------------------------------
	std::string server{};
	std::string user{};
	std::string password{};
	std::string database{};
	unsigned int port{};
	std::string unix{};
	unsigned long flag{};
	//------------------------------------------------------------------------
	VandConfig.loadmysql(server,database,user,password,unix,port,flag);

	mydatabase vanduo(server, database, port, user, password, unix, flag);
	vanduo.connectTo();
	timenow(year, month, day); // I use it, because in MySQL i want date of today
	std::string uzklausa{}; // variable for Query
	uzklausa = "INSERT INTO `vanduo` (`metai`, `menuo`, `diena`, `rodmuo` ) VALUES ('" + std::to_string(year) + "', '" + std::to_string(month) + "', '" + std::to_string(day) + "', '" + std::to_string(rodmuo) + "');";
	vanduo.runQuery(uzklausa);
	//----------------------------------------------------------------------
	//std::cin.get();//not needed
	return 0;
}
