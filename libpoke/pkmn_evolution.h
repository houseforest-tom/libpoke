#pragma once

#include "util_csv.h"

namespace pkmn
{
	// Fwd declare
	class PokedexEntry;

	using namespace std;

	// Evolution methods
	enum class EEvolutionMethod : uint8_t
	{
		LEVELUP,
		TRADE
	};

	// Evolution information
	class Evolution : public util::CSVConstructable
	{
	private:
		// Method
		EEvolutionMethod m_method;
		
		// Extra condition to be met, e.g. level, held item, etc.
		string m_condition;

		// Target pokemon
		shared_ptr<PokedexEntry> m_target;

	public:
		// Ctor
		Evolution(const util::CSVParsedObj &csvobj);
	
		// Getters
		inline EEvolutionMethod getMethod(void) const { return m_method; }
		inline const string &getCondition(void) const { return m_condition; }
		inline shared_ptr<PokedexEntry> getTarget(void) { return m_target; }
	};
}