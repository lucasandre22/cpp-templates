#include "MapTemplate.h"
#include <map>
#include <iostream>
#include <string>

int main()
{
	MapTemplate<int, std::string> mapa;
	std::map <int, std::string> map;
	mapa.add(19, "Lucas");
	mapa.add(33, "Lucas");
	mapa.add(14, "Lucas2");
	mapa.add(172, "Lucas1");
	mapa.forEach([](int i) {std::cout << i << std::endl; });
	std::cout << mapa.contains(2) << std::endl;
	std::cout << mapa[0] << std::endl;
}