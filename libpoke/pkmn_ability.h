#pragma once

#include <string>

namespace pkmn
{
	using namespace std;

	class Ability
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
		Ability(uint16_t id, const string &name, const string &desc);

		// Getters
		inline uint16_t getId(void) const { return m_id; }
		inline const string &getName(void) const { return m_name; }
		inline const string &getDescription(void) const { return m_desc; }
	};
}