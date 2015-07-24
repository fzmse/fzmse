/*
 * PBDBManagedObjectParameter.h
 *
 *  Created on: 24 lip 2015
 *      Author: pkozuch
 */

#pragma once

#include "TinyXML/tinyxml2.h"
#include "ManagedObjectRelativeElement.h"

namespace InternalTypes
{
	class PBDBManagedObjectParameter : public ManagedObjectRelativeElement
	{
	public:
		PBDBManagedObjectParameter( tinyxml2::XMLElement * pElement );
		virtual ~PBDBManagedObjectParameter();

	};
}
