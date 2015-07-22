
/*
 * XmlElement.cpp
 *
 *  Created on: 22 lip 2015
 *      Author: pkozuch
 */
#include <Xml/XmlElementReader.h>
#include <iostream>
#include <string>

using namespace tinyxml2;
using namespace std;

std::string XmlElementReader::getName(XMLElement * e)
{
	const char * c = e->Value();
	return c == NULL ? "" : std::string(c);
}
