#include <gtest/gtest.h>

#include <Xml/XmlWrapper.h>
#include <Xml/XmlElement.h>

using namespace tinyxml2;

TEST(XML_ELEMENT, GetElementXml)
{
	XmlDocument * doc = XmlWrapper::loadDocument("UT/TestFiles/PDDB/test_pddb_2.xml");
	ASSERT_EQ(XML_NO_ERROR, doc->getLastError());
}
