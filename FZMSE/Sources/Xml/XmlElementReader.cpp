
/*
 * XmlElementReader.cpp
 *
 *  Created on: 22 lip 2015
 *      Author: pkozuch
 */
#include <Xml/XmlElementReader.h>
#include <iostream>

using namespace tinyxml2;
using namespace std;

std::string XmlElementReader::getName(XMLElement * e)
{
	const char * c = e->Value();
	return c == NULL ? "" : std::string(c);
}

vector< pair<string, string> > XmlElementReader::getAttributes(XMLElement * e)
{
	vector< pair<string, string> > result;
	XMLAttribute * currentAttribute = (XMLAttribute*)e->FirstAttribute();
	//if ( x == NULL )
	//	return result;
	//else
	//{
	//	while ( )
	//}
	return result;
}
