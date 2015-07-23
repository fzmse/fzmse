/*
 * XmlReader.cpp
 *
 *  Created on: 22 lip 2015
 *      Author: pfert
 */

#include <iostream>

#include "Xml/XmlReader.h"
#include "Xml/XmlElementReader.h"


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
	if(tag == "")
		return this->currElement->FirstChildElement();
	else
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

bool isElementSearchMatch(XMLElement * e, std::string name, std::string attributeName, std::string attributeValue)
{
	if ( name == "" )
		return true;
	else
	{
		if ( XmlElementReader::getName(e) == name )
		{
			if ( attributeName == "" )
				return true;
			else
			{
				return XmlElementReader::getAttributeByName(e, attributeName) == attributeValue;
			}
		}
		else
			return false;
	}
}

void getElementsWithSpecificNameAndAttributeRecursive( XMLElement * e, std::string name, std::string attributeName, std::string attributeValue, std::vector<XMLElement *> & resultsVector, int & depth)
{
	if ( e != NULL )
	{
		int newDepth = *(&depth);
		int newRelDepth = newDepth + 1;
		for( XMLElement* node= e->FirstChildElement(); node; node = node->NextSiblingElement() )
		{
			if ( node != NULL )
			{
				if ( isElementSearchMatch(node, name, attributeName, attributeValue) )
					resultsVector.push_back(node);
				getElementsWithSpecificNameAndAttributeRecursive(node, name, attributeName, attributeValue, resultsVector, newRelDepth);
			}
		}
	}
}

std::vector<XMLElement *> XmlReader::getElementsWithSpecificNameAndAttribute(XMLElement * e, std::string name, std::string attributeName, std::string attributeValue)
{
	std::vector<XMLElement *> results;

	int depth = 0;

	for( XMLElement* node= e->FirstChildElement(); node; node = node->NextSiblingElement() )
	{
		if ( node != NULL )
		{
			if ( isElementSearchMatch(node, name, attributeName, attributeValue) )
				results.push_back(node);
			depth ++;
			getElementsWithSpecificNameAndAttributeRecursive(node, name, attributeName, attributeValue, results, depth);
		}
	}

	return results;
}

void fetchLower(XMLElement * e, std::vector<XMLElement *> & results)
{
	for( XMLElement* node= e; node; node = node->NextSiblingElement() )
	{
		if ( node != NULL )
		{
			if ( node->FirstChildElement() == NULL )
				results.push_back(node);
			else
				fetchLower(node->FirstChildElement(), results);
		}
	}
}

std::vector<XMLElement *> XmlReader::getLeaves(XMLElement * e)
{
	std::vector<XMLElement *> results;

	for( XMLElement* node= e; node; node = node->NextSiblingElement() )
	{
		if ( node != NULL )
		{
			if ( node->FirstChildElement() == NULL )
				results.push_back(node);
			else
				fetchLower(node->FirstChildElement(), results);
		}
	}

	return results;
}

XMLElement* XmlReader::getParent(XMLElement * e)
{
	XMLNode * n = e->Parent();
	return n == NULL ? NULL : (XMLElement*)n;
}

