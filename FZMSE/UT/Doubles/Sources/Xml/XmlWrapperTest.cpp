/*
 * XmlWrapperTest.cpp
 *
 *  Created on: 22 lip 2015
 *      Author: pkozuch
 */
#include <gtest/gtest.h>

#include <Xml/XmlWrapper.h>
#include <Xml/XmlDocument.h>

using namespace std;
using namespace tr1;

TEST(XML_LOAD_FILE, LoadValidFileThatExists)
{
	XmlDocument * doc = XmlWrapper::loadDocument("UT/TestFiles/PDDB/test_pddb_1.xml");
	EXPECT_DOUBLE_EQ(tinyxml2::XML_NO_ERROR, doc->getLastError());
	delete doc;
}

TEST(XML_LOAD_FILE, LoadFileThatDoesNotExist)
{
	XmlDocument * doc = XmlWrapper::loadDocument("UT_notExists_/test_pddb_12.xml");
	EXPECT_DOUBLE_EQ(tinyxml2::XML_ERROR_FILE_NOT_FOUND, doc->getLastError());
	delete doc;
}

TEST(XML_LOAD_FILE, LoadFileThatIsNotValidXml)
{
	XmlDocument * doc = XmlWrapper::loadDocument("UT/TestFiles/resources/notXml.txt");
	EXPECT_DOUBLE_EQ(tinyxml2::XML_ERROR_PARSING_TEXT, doc->getLastError());
	delete doc;
}

