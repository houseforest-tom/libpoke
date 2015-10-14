#pragma once

#include "util_csv.h"

namespace pkmn
{
	using namespace std;

	class Ability : public util::CSVConstructable
	{
	private:
		// Internal id
		uint16_t m_id;
		
		// Display name
		string m_name;

		// Descriptive text
		string m_desc;

	public:
		// Ctor
		Ability(const util::CSVParsedObj &csvobj);

		// Getters
		inline uint16_t getId(void) const { return m_id; }
		inline const string &getName(void) const { return m_name; }
		inline const string &getDescription(void) const { return m_desc; }
	};
}