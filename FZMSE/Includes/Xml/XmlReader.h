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
	std::vector <XMLElement*> getChildren(std::string tag);
	XMLElement * getFirstChild(std::string tag);
	void setCurrElement(XMLElement * newElement);
	void setNextElement();
	void goFirstChild();
	static std::vector<XMLElement *> getElementsWithSpecificNameAndAttribute(XMLElement * e, std::string name, std::string attributeName, std::string attributeValue);
	static std::vector<XMLElement *> getLeaves(XMLElement * e);
	static tinyxml2::XMLElement* getParent(XMLElement * e);
};
