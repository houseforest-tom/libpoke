#include "pkmn_move.h"

namespace pkmn
{
	Move::Move(uint16_t id, const string &name, const string &desc, EMoveCategory category, uint8_t power, uint8_t acc, uint8_t pp)
		:m_id(id), m_name(name), m_desc(desc), m_cat(category), m_power(power), m_accuracy(acc), m_pp(pp)
	{

	}
}