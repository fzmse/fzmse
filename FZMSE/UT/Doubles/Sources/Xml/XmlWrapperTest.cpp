/*
 * XmlWrapperTest.cpp
 *
 *  Created on: 22 lip 2015
 *      Author: pkozuch
 */
#include <gtest/gtest.h>

#include <Xml/XmlWrapper.h>

using namespace std;
using namespace tinyxml2;

TEST(XML_LOAD_FILE, LoadValidFileThatExists)
{
	XMLDocument * doc = XmlWrapper::loadDocument("UT/TestFiles/PDDB/test_pddb_1.xml");
	EXPECT_EQ(tinyxml2::XML_NO_ERROR, doc->ErrorID());
	delete doc;
}

TEST(XML_LOAD_FILE, LoadFileThatDoesNotExist)
{
	XMLDocument * doc = XmlWrapper::loadDocument("UT_notExists_/test_pddb_12.xml");
	EXPECT_EQ(tinyxml2::XML_ERROR_FILE_NOT_FOUND, doc->ErrorID());
	delete doc;
}

TEST(XML_LOAD_FILE, LoadFileThatIsNotValidXml)
{
	XMLDocument * doc = XmlWrapper::loadDocument("UT/TestFiles/resources/notXml.txt");
	EXPECT_EQ(tinyxml2::XML_ERROR_PARSING_TEXT, doc->ErrorID());
	delete doc;
}

