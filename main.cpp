#include "MapTemplate.h"
#include <iostream>
#include <string>

int main()
{
	MapTemplate<int, std::string> mapa;
	mapa.add(0, "Lucas");
	mapa.add(1, "Lucas");
	mapa.add(2, "Lucas");
	mapa.forEach([](int i) {std::cout << i << std::endl; });
	//std::cout << mapa.contains(2) << std::endl;
}