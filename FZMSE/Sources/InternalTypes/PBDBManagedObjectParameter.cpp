/*
 * PBDBManagedObjectParameter.cpp
 *
 *  Created on: 24 lip 2015
 *      Author: pkozuch
 */
#pragma once

#include "InternalTypes/PBDBManagedObjectParameter.h"

using namespace InternalTypes;
using namespace tinyxml2;


PBDBManagedObjectParameter::PBDBManagedObjectParameter(XMLElement * e)
	: ManagedObjectRelativeElement::ManagedObjectRelativeElement(e)
{

}

PBDBManagedObjectParameter::~PBDBManagedObjectParameter()
{

}
