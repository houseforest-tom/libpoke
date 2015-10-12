#include "pkmn_evolution.h"
#include "pkmn_pokedex_entry.h"

namespace pkmn
{
	Evolution::Evolution(EEvolutionMethod method, const string &condition, shared_ptr<PokedexEntry> target)
		:m_method(method), m_condition(condition), m_target(target)
	{

	}
}