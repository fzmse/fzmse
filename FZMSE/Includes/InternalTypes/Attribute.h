
#pragma once

#include <string>
#include <utility>

namespace InternalTypes
{
	struct Attribute : std::pair<std::string, std::string>
	{
	public:
		Attribute ( std::string key, std::string value );
		Attribute ( std::pair<std::string, std::string> );

		std::string getKey();
		std::string getValue();

		void setKey( std::string k );
		void setValue( std::string v );

	protected:
		Attribute();

		std::string key;
		std::string value;
	};
}
