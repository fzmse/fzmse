#include <gtest/gtest.h>
#include <Utilities/UtilVector.hpp>
#include <Xml/XmlReader.h>
#include "TinyXML/tinyxml2.h"
#include <Xml/XmlWrapper.h>
#include <Xml/XmlElementReader.h>


using namespace tinyxml2;
using namespace std;


TEST(XML_READER, CreateWithXMLDocument)
{
	XMLDocument * doc = XmlWrapper::loadDocument("UT/TestFiles/PDDB/test_pddb_2.xml");
	XMLElement * doc_element = doc->RootElement();
	XmlReader * reader = new XmlReader(doc);
	EXPECT_EQ(doc_element, reader->getCurrElement());
	delete reader;
	delete doc;
}

TEST(XML_READER, CreateWithXMLElement)
{
	XMLDocument * doc = XmlWrapper::loadDocument("UT/TestFiles/PDDB/test_pddb_1.xml");
	XMLElement * doc_element = doc->FirstChildElement();
	XmlReader * reader = new XmlReader(doc_element);
	EXPECT_EQ(reader->getCurrElement(), doc_element);
	delete reader;
	delete doc;
}

TEST(XML_READER, FirstChildIsRoot)
{
	XMLDocument * doc = XmlWrapper::loadDocument("UT/TestFiles/PDDB/test_pddb_1.xml");
	XMLElement * doc_element = doc->FirstChildElement();
	XmlReader * reader = new XmlReader(doc);
	EXPECT_EQ(reader->getCurrElement(), doc_element);
	delete reader;
	delete doc;
}

TEST(XML_READER, ChildrensArrayNoTag)
{
	XMLDocument * doc = XmlWrapper::loadDocument("UT/TestFiles/PDDB/test_pddb_1.xml");
	XmlReader * reader = new XmlReader(doc);
	std::string tag = "";
	std::vector<XMLElement*> result;
	reader->goFirstChild();
	result = reader->getChildren(tag);
	for (std::vector<XMLElement*>::iterator it = result.begin() ; it != result.end(); ++it)
	{
		std::cout << XmlElementReader::getName(*it).c_str() << endl;
	}
	delete reader;
	delete doc;
}

TEST(XML_READER, ChildrensArrayWithTag)
{
	XMLDocument * doc = XmlWrapper::loadDocument("UT/TestFiles/PDDB/test_pddb_1.xml");
	XmlReader * reader = new XmlReader(doc);
	std::string tag = "managedObject";
	std::vector<XMLElement*> result;
	reader->goFirstChild();
	result = reader->getChildren(tag);
	for (std::vector<XMLElement*>::iterator it = result.begin() ; it != result.end(); ++it)
	{
		std::cout << XmlElementReader::getName(*it).c_str() << endl;
	}
	delete reader;
	delete doc;
}

TEST(XML_READER, FindElementWithSpecificAttributeOnIt)
{
	XMLDocument * doc = XmlWrapper::loadDocument("UT/TestFiles/PDDB/test_pddb_3.xml");
	XmlReader * reader = new XmlReader(doc);

	vector<XMLElement *> matches = XmlReader::getElementsWithSpecificNameAndAttribute((XMLElement*)doc, "managedObject", "class", "AMLEPR");

	ASSERT_EQ(1, matches.size());

	delete reader;
	delete doc;
}

TEST(XML_READER, FindElementWithSpecificAttributeOnIt_AllElements)
{
	XMLDocument * doc = XmlWrapper::loadDocument("UT/TestFiles/PDDB/test_pddb_2.xml");
	XmlReader * reader = new XmlReader(doc);

	vector<XMLElement *> matches = XmlReader::getElementsWithSpecificNameAndAttribute((XMLElement*)doc, "", "", "");

	ASSERT_EQ(6, matches.size());

	delete reader;
	delete doc;
}



TEST(XML_READER, FindLeaves)
{
	XMLDocument * doc = XmlWrapper::loadDocument("UT/TestFiles/PDDB/test_pddb_2.xml");
	XmlReader * reader = new XmlReader(doc);

	vector<XMLElement *> matches = XmlReader::getLeaves((XMLElement*) doc);

	ASSERT_EQ(2, matches.size());

	printXMLElementVector(matches);

	delete reader;
	delete doc;
}
