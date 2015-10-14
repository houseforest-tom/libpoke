#pragma once

#include "util_csv.h"

namespace pkmn
{
	// Fwd declare
	class PokedexEntry;

	using namespace std;

	class EggGroup : public util::CSVConstructable
	{
	private:
		// Internal id
		uint16_t m_id;

		// Display name
		string m_name;

		// Pokemon included within this egg group
		vector<shared_ptr<PokedexEntry>> m_members;

	public:
		// Ctor
		EggGroup(const util::CSVParsedObj &csvobj);

		// Getters
		inline uint16_t getId(void) const { return m_id; }
		inline const string &getName(void) const { return m_name; }
		inline vector<shared_ptr<PokedexEntry>> &getMembers(void) { return m_members; }
		inline const vector<shared_ptr<PokedexEntry>> &getMembers(void) const { return m_members; }
	};
}