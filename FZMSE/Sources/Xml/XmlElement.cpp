
/*
 * XmlElement.cpp
 *
 *  Created on: 22 lip 2015
 *      Author: pkozuch
 */

#include <Xml/XmlElement.h>

#include <string>

using namespace std;
using namespace tinyxml2;



XmlElement::XmlElement(XMLElement* element)
{
	this->element = element;
}

XmlElement::~XmlElement()
{

}


XMLElement* XmlElement::getElement()
{
	return this->element;
}

string XmlElement::getXML()
{
	return "";
}
