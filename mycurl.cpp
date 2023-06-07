#include "mycurl.h"

mycurl::mycurl(std::string &url, int day, int month, int year)
{
	Cccurl = url;	
	Cday = day;
	Cmonth = month;
	Cyear = year;
	//curl_global_init(CURL_GLOBAL_ALL); //I dont really know is it needed or not
	curl = curl_easy_init();
	fullparameter = "pavadinimas=6&year="+std::to_string(Cyear)+"&month="+ std::to_string(Cmonth)+"&day="+ std::to_string(Cday) +"&submit=Parodyti";
	
}
mycurl::~mycurl()
{
	curl_easy_cleanup(curl);
	std::cout << "Cleaned" << std::endl;
	
}
int mycurl::curlWriter(char* data, int size, int nmemb, std::string* buffer)
{
	int result = 0;
	if (buffer != NULL)
	{
		buffer->append(data, size * nmemb);
		result = size * nmemb;
	}
	return result;
}

std::string mycurl::getData()
{
	return std::string(curlbuffer);
}
void mycurl::gotourl()
{
	if (!curl)
	{
		throw std::string("Curl did not initialize");
	}
	try
	{

		curl_easy_setopt(curl, CURLOPT_URL, Cccurl.c_str());
		curl_easy_setopt(curl, CURLOPT_POST, 1);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, fullparameter.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &mycurl::curlWriter);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curlbuffer);
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 6.2) AppleWebKit/536.6 (KHTML, like Gecko) Chrome/20.0.1090.0 Safari/536.6");
		res = curl_easy_perform(curl);
		std::cout << curlbuffer << std::endl;
	}
	catch (const std::exception&)
	{
		std::cout << "mycurl error" << std::endl;
	}

	if (res != CURLE_OK)
	{
		std::cerr << curl_easy_strerror(res) << std::endl;
	}
}