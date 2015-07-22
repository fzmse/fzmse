#include <vector>

#include <gtest/gtest.h>
#include <Xml/XmlElementReader.h>

#include <Xml/XmlWrapper.h>

using namespace tinyxml2;
using namespace std;

bool isVectorsIdentical(vector<string> a, vector<string> b)
{
	if ( a.size() != b.size() )
		return false;

	if ( a.size() == 0 )
		return true;

	vector<string>::iterator itA = a.begin();
	vector<string>::iterator itB = b.begin();

	while( itA != a.end() && itB != b.end())
	{
		if ( (*itA) == (*itB) )
		{
			++ itA;
			++ itB;
		}
		else
			return false;
	}

	return true;
}

TEST(XML_ELEMENT_READER, GetElementName)
{
	XMLDocument * doc = XmlWrapper::loadDocument("UT/TestFiles/PDDB/test_pddb_2.xml");
	ASSERT_EQ(XML_NO_ERROR, doc->ErrorID());

	EXPECT_EQ("relatedParameters", XmlElementReader::getName(doc->RootElement()));

	delete doc;
}

TEST(XML_ELEMENT_READER, GetAttributes)
{
	XMLDocument * doc = XmlWrapper::loadDocument("UT/TestFiles/PDDB/test_pddb_2.xml");
	ASSERT_EQ(XML_NO_ERROR, doc->ErrorID());

	XMLElement * el = doc->RootElement()->FirstChildElement();
	XmlElementReader::getAttributes(el);


}
