/*
 * XmlWrapper.cpp
 *
 *  Created on: 22 lip 2015
 *      Author: pkozuch
 */

#include <Xml/XmlWrapper.h>

using namespace tinyxml2;

XmlDocument * XmlWrapper::loadDocument(std::string filename)
{
	XMLDocument * doc = new XMLDocument();
	doc->LoadFile(filename.c_str());
	return new XmlDocument(doc);
}

XmlWrapper::~XmlWrapper()
{
}