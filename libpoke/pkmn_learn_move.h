#pragma once

#include "util_csv.h"
#include "pkmn_move.h"

namespace pkmn
{
	// Learn methods
	enum class ELearnMethod : uint8_t
	{
		LEVELUP,
		MACHINE,
		TUTOR,

		COUNT
	};

	// Describes how a move will be learned by a pokemon
	class LearnMove : public util::CSVConstructable
	{
	private:
		// Move to learn
		shared_ptr<Move> m_move;

		// Learn method
		ELearnMethod m_method;

		// Learn condition (depends on method)
		string m_condition;

	public:
		// Ctor
		LearnMove(const util::CSVParsedObj &csvobj);
		
		// Getters
		inline shared_ptr<Move> getMove(void) { return m_move; }
		inline const shared_ptr<Move> &getMove(void) const { return m_move; }
		inline ELearnMethod getMethod(void) const { return m_method; }
		inline const string &getCondition(void) const { return m_condition; }
	};
}