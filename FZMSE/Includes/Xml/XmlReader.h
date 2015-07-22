#pragma once

#include "TinyXML/tinyxml2.h"
#include <vector>
#include <string>
using namespace tinyxml2;

class XmlReader {
protected:
	XMLElement* currElement;
public:
	XmlReader(XMLDocument* doc);
	XmlReader(XMLElement* doc);
	virtual ~XmlReader();
	XMLElement * getCurrElement();
	std::vector <XMLElement*> getChildrens(std::string tag);
	XMLElement * getFirstChildren(std::string tag);
	XMLElement * getChildrenByAttr(std::string tag, std::string attr, std::string value);
	void setCurrElement(XMLElement * newElement);
	void setNextElement();
	void goFirstChild();

};
