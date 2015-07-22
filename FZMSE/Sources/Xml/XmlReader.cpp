/*
 * XmlReader.cpp
 *
 *  Created on: 22 lip 2015
 *      Author: pfert
 */

#include "Xml/XmlReader.h"

XmlReader::XmlReader(XMLDocument* doc)
{
	this->currElement = doc->RootElement();
}

XmlReader::XmlReader(XMLElement* element)
{
	this->currElement = element;
}

XmlReader::~XmlReader()
{
}

XMLElement* XmlReader::getCurrElement()
{
	return this->currElement;
}

std::vector<XMLElement*> XmlReader::getChildrens(std::string tag)
{
	std::vector<XMLElement*> childrens;
	XMLElement* currChildElement;
	if(tag == "")
		currChildElement = this->currElement->FirstChildElement();
	else
		currChildElement = this->currElement->FirstChildElement(tag.c_str());

	while(currChildElement != NULL)
	{
		childrens.push_back(currChildElement);
		currChildElement = currChildElement->NextSiblingElement();
	}
	return childrens;
}

//XMLElement* XmlReader::getFirstChildren(std::string tag)
//{
//	XMLElement * a;
//	return a;
//}
//
//
//XMLElement* XmlReader::getChildrenByAttr(std::string tag, std::string attr,
//		std::string value)
//{
//	XMLElement * a;
//	return a;
//}

void XmlReader::setCurrElement(XMLElement* newElement)
{
	this->currElement = newElement;
}

void XmlReader::setNextElement()
{
	this->currElement = this->currElement->NextSiblingElement();
}

void XmlReader::goFirstChild()
{
	this->currElement->FirstChildElement();
}
