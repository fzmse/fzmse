#include <gtest/gtest.h>
#include <Xml/XmlElementReader.h>

#include <Xml/XmlWrapper.h>

using namespace tinyxml2;
using namespace std;

TEST(XML_ELEMENT, GetElementXml)
{
	XMLDocument * doc = XmlWrapper::loadDocument("UT/TestFiles/PDDB/test_pddb_2.xml");
	EXPECT_EQ(XML_NO_ERROR, doc->ErrorID());

//	XMLDocument * d = doc->getDocumentHandle();
//	XmlElement * element = new XmlElement(d->RootElement());
//
//
//	EXPECT_EQ( "", element->getXML());

	delete doc;
}
