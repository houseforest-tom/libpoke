#include "pkmn_learn_move.h"

namespace pkmn
{
	LearnMove::LearnMove(shared_ptr<Move> move, ELearnMethod method, const string &condition)
		:m_move(move), m_method(method), m_condition(condition)
	{

	}
}