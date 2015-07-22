#pragma once
#include <string>
#include <TinyXML/tinyxml2.h>
class XmlElementReader
{
public:
	static std::string getName(tinyxml2::XMLElement * e);
};
