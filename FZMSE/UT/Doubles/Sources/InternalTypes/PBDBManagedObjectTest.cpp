/*
 * PBDBManagedObjectTest.cpp
 *
 *  Created on: 24 lip 2015
 *      Author: pkozuch
 */

#include <gtest/gtest.h>
#include "TinyXML/tinyxml2.h"

#include <Xml/XmlElementReader.h>

#include <Xml/XmlWrapper.h>

#include "InternalTypes/PBDBManagedObject.h"

using namespace tinyxml2;
using namespace std;

using namespace InternalTypes;

TEST( PBDBManagedObject, CreateManagedObject)
{
	XMLDocument * doc = XmlWrapper::loadDocument("UT/TestFiles/PDDB/test_pddb_1.xml");
	XMLElement* mocElement = XmlReader::getElementsWithSpecificNameAndAttribute((XMLElement*) doc, "managedObject")[0];

	PBDBManagedObject * moc = new PBDBManagedObject(mocElement);

	ASSERT_EQ(true, moc->isValidMocObject());
	delete moc;
	delete doc;
}

TEST( PBDBManagedObject, CreateInvalidManagedObject)
{
	XMLDocument * doc = XmlWrapper::loadDocument("UT/TestFiles/PDDB/test_pddb_1.xml");
	XMLElement* mocElement = XmlReader::getElementsWithSpecificNameAndAttribute((XMLElement*) doc, "p")[0];

	PBDBManagedObject * moc = new PBDBManagedObject(mocElement);

	ASSERT_EQ(false, moc->isValidMocObject());
	delete moc;
	delete doc;
}

TEST( PBDBManagedObject, CreateManagedObjectWithParameters)
{
	XMLDocument * doc = XmlWrapper::loadDocument("UT/TestFiles/PDDB/test_pddb_1.xml");
	XMLElement* mocElement = XmlReader::getElementsWithSpecificNameAndAttribute((XMLElement*) doc, "managedObject")[0];

	PBDBManagedObject * moc = new PBDBManagedObject(mocElement);

	ASSERT_EQ(5, moc->getParameters().size());
	delete moc;
	delete doc;
}

TEST( PBDBManagedObject, CreateManagedObjectWithNoParameters)
{
	XMLDocument * doc = XmlWrapper::loadDocument("UT/TestFiles/PDDB/test_pddb_1_noParams.xml");
	XMLElement* mocElement = XmlReader::getElementsWithSpecificNameAndAttribute((XMLElement*) doc, "managedObject")[0];

	PBDBManagedObject * moc = new PBDBManagedObject(mocElement);

	ASSERT_EQ(0, moc->getParameters().size());
	delete moc;
	delete doc;
}
TEST( PBDBManagedObject, CreateManagedObjectWithEmptyParameter)
{
	XMLDocument * doc = XmlWrapper::loadDocument("UT/TestFiles/PDDB/test_pddb_1_emptyParams.xml");
	XMLElement* mocElement = XmlReader::getElementsWithSpecificNameAndAttribute((XMLElement*) doc, "managedObject")[0];

	PBDBManagedObject * moc = new PBDBManagedObject(mocElement);

	ASSERT_EQ(1, moc->getParameters().size());
	delete moc;
	delete doc;
}
