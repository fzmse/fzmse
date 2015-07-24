/*
 * PBDBManagedObject.cpp
 *
 *  Created on: 24 lip 2015
 *      Author: pkozuch
 */

#include "InternalTypes/PBDBManagedObject.h"

using namespace std;

using namespace InternalTypes;
using namespace tinyxml2;

PBDBManagedObject::PBDBManagedObject(XMLElement * e)
	: ManagedObjectRelativeElement::ManagedObjectRelativeElement(e)
{
	this->validMocObject = false;
	if ( e != NULL )
	{
		if ( XmlElementReader::getName(e) == MANAGED_OBJECT_XML_NAME )
		{
			this->validMocObject = true;

			vector<XMLElement * > pElements = XmlReader::getElementsWithSpecificNameAndAttribute(e, "");
			for ( vector<XMLElement * >::iterator it = pElements.begin(); it != pElements.end(); ++ it )
			{
				if ( XmlElementReader::getName(*it) == MANAGED_OBJECT_PARAMETER_XML_NAME )
					this->parameters.push_back( new PBDBManagedObjectParameter(*it) );
			}

		}

	}
}

PBDBManagedObject::~PBDBManagedObject()
{
	for ( vector<PBDBManagedObjectParameter *>::iterator it = this->parameters.begin();
			it != this->parameters.end(); ++ it )
	{
		delete (*it);
	}
}

bool PBDBManagedObject::isValidMocObject()
{
	return this->validMocObject;
}

vector<PBDBManagedObjectParameter *> PBDBManagedObject::getParameters()
{
	return this->parameters;
}
