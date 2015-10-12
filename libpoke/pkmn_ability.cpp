#include "pkmn_ability.h"

namespace pkmn
{
	Ability::Ability(uint16_t id, const string &name, const string &desc)
		:m_id(id), m_name(name), m_desc(desc)
	{

	}
}