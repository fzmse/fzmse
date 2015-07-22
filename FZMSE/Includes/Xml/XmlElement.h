#pragma once
#include <string>
#include <TinyXML/tinyxml2.h>
class XmlElement
{
public:
	XmlElement( tinyxml2::XMLElement * element );
	virtual ~XmlElement();

	tinyxml2::XMLElement * getElement();
	std::string getXML();

protected:
	XmlElement();
	tinyxml2::XMLElement * element;
};
