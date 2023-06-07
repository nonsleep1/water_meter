#include "dataparse.h"


dataparse::dataparse(int howmanytimestolookfor)
{
	HTimesDoloop = howmanytimestolookfor;
	regexsearch = "\\d+";
	//findTHIS = "<td colspan=3>";
	findTHIS = "<td colspan=8>";

}
dataparse::~dataparse()
{
	fromFILE.close();
}
void dataparse::datafromfile(std::ifstream& fromFILE, std::string &SourceofWebPage)
{
	std::stringstream ss, sstemp;
	std::string str;
	while (fromFILE >> ss.rdbuf());
	
	size_t b = 0;
	try
	{
		for (int a = 0; a < HTimesDoloop; a++)
		{
			if (a == 0)
			{
				b = ss.str().find(findTHIS);
			}
			else
			{
				b = ss.str().find(findTHIS, b + a);
			}
		}
		sstemp << ss.str().substr((b + 14), 25);//b - nuo kur, kiek simboliu paimti
		sstemp >> str;
		intregexline(str, regexsearch, intnumber);//sitas mes klaida jei neras nieko
	}
	catch (const std::exception&)
	{
		//std::cerr << e.what() << '\n';
		std::cout << "error! \n";
	}
}
void dataparse::datafromvariable_old(std::string& SourceofWebpage)
{
	
	std::stringstream ss, sstemp;
	ss << SourceofWebpage;
	std::string str;
	size_t b = 0;
	try
	{
		for (int a = 0; a < HTimesDoloop; a++)
		{
			if (a == 0)
			{
				b = ss.str().find(findTHIS);
			}
			else
			{
				b = ss.str().find(findTHIS, b + a);
			}
		}
		sstemp << ss.str().substr((b + 14), 25);//b - nuo kur, kiek simboliu paimti
		sstemp >> str;
		std::cout<<str<<"\n";
		intregexline(str, regexsearch, intnumber);//sitas mes klaida jei neras nieko
	}
	catch (const std::exception&)
	{
		//std::cerr << e.what() << '\n';
		std::cout << "parse error!\n";
	}
}
void dataparse::datafromvariable(std::string& SourceofWebpage)
{

	std::stringstream ss, sstemp;
	ss << SourceofWebpage;
	std::string str;
	size_t b = 0;
	try
	{
		b = ss.str().find(findTHIS);
		
		sstemp << ss.str().substr((b + 14), 25);//b - nuo kur, kiek simboliu paimti
		sstemp >> str;
		std::cout << str << "\n";
		intregexline(str, regexsearch, intnumber);//sitas mes klaida jei neras nieko
	}
	catch (const std::exception&)
	{
		//std::cerr << e.what() << '\n';
		std::cout << "parse error!\n";
	}
}
void dataparse::intregexline(std::string& line, std::string& lookfor, int& found)
{
	std::regex r(lookfor);
	std::smatch m;
	std::regex_search(line, m, r);
	for (auto x : m)
		found = std::stoi(x);
}
int dataparse::getnumber()
{

	return intnumber;
}