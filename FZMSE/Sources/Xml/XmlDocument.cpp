#include <Xml/XmlDocument.h>

using namespace tinyxml2;

XmlDocument::XmlDocument(XMLDocument* doc)
{
	this->doc = doc;
}

XmlDocument::~XmlDocument() {
	if ( this->doc != NULL )
	{
		delete this->doc;
		this->doc = NULL;
	}
}

XMLError XmlDocument::getLastError()
{
	return this->doc->ErrorID();
}

