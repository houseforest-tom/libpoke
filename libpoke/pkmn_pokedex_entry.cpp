#include "pkmn_pokedex_entry.h"

namespace pkmn
{
	PokedexEntry::PokedexEntry(
		uint16_t id,
		const string &name,
		const string &species,
		const string &description,
		uint8_t catchrate,
		uint16_t eggcycles,
		uint16_t expyield,
		EGrowthRate growth,
		uint8_t happiness,
		float height,
		float weight)
	{
		m_abilities.reserve(5);
		enum_foreach(EStat, s)
		{
			m_stats.insert(make_pair(s, 0));
			m_evYields.insert(make_pair(s, 0));
		}
	}
}