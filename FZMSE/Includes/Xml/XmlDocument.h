#pragma once

#include <TinyXML/tinyxml2.h>

class XmlDocument
{
public:

	XmlDocument(tinyxml2::XMLDocument * doc);
	~XmlDocument();

	tinyxml2::XMLError getLastError();

protected:
	XmlDocument();
	tinyxml2::XMLDocument * doc;
};
