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

std::vector<XMLElement*> XmlReader::getChildren(std::string tag)
{
	std::vector<XMLElement*> children;
	XMLElement* currChildElement;
	if(tag == "")
		currChildElement = this->currElement->FirstChildElement();
	else
		currChildElement = this->currElement->FirstChildElement(tag.c_str());

	while(currChildElement != NULL)
	{
		children.push_back(currChildElement);
		currChildElement = currChildElement->NextSiblingElement();
	}
	return children;
}

XMLElement* XmlReader::getFirstChild(std::string tag)
{
	return this->currElement->FirstChildElement(tag.c_str());
}

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
