#pragma once
#ifndef MYCURL_H
#define MYCURL_H
#define CURL_STATICLIB
#include <curl/curl.h>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


class mycurl
{
private:
	CURL* curl;
	CURLcode res;
	int Cday;
	int Cmonth;
	int Cyear;
	std::string curlbuffer;
	std::string bufferiukas;
	std::string Cccurl;
	std::string fullparameter;
	

public:
	mycurl(std::string &url,int day, int month, int year);
	~mycurl();
	static int curlWriter(char* data, int size, int nmemb, std::string* buffer);
	std::string getData();
	void gotourl();
	
	
};
#endif // !MYCURL.H
