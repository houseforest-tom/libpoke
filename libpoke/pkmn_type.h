#pragma once

#include "util_csv.h"

namespace pkmn
{
	using namespace std;

	// Pokemon typing
	class Type : public util::CSVConstructable
	{
	private:
		// Internal id
		uint16_t m_id;

		// Display name
		string m_name;

		// Cross-type relations
		vector<shared_ptr<Type>> m_effectiveAgainst,	// x2   if attacking
			m_ineffectiveAgainst,						// x0.5 if attacking
			m_noEffectAgainst,							// x0	if attacking
			m_weaknesses,								// x2	if attacked
			m_resistances,								// x0.5	if attacked
			m_immunities;								// x0	if attacked

	public:
		// Ctor
		Type(const util::CSVParsedObj &csvobj);
	};
}