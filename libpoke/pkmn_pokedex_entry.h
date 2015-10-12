#pragma once

#include <memory>
#include <vector>
#include <string>

#include "pkmn_evolution.h"
#include "pkmn_type.h"
#include "pkmn_ability.h"
#include "pkmn_egg_group.h"
#include "pkmn_learn_move.h"

namespace pkmn
{
	using namespace std;

	// Pokemon stats
	enum class EStat : uint8_t
	{
		HP,
		ATK,
		SPATK,
		DEF,
		SPDEF,
		SPEED,

		COUNT
	};

	// Pokemon experience needs aka. growth rate
	enum class EGrowthRate : uint8_t
	{
		ERRATIC,
		FAST,
		MEDIUM_FAST,
		MEDIUM_SLOW,
		SLOW,
		FLUCTUATING,

		COUNT
	};

	// Contains all information about one pokemon species
	class PokedexEntry
	{
	private:
		uint16_t m_id;
		string m_name;
		vector<shared_ptr<Ability>> m_abilities;
		string m_species;
		string m_description;
		uint8_t m_stats[(unsigned)EStat::COUNT];
		uint8_t m_catchRate;
		uint16_t m_eggCycles;
		vector<shared_ptr<EggGroup>> m_eggGroups;
		EStat m_evYieldStat;
		uint8_t m_evYieldAmount;
		uint16_t m_expYield;
		EGrowthRate m_growthRate;
		uint8_t m_happiness;
		float m_height;
		float m_weight;
		vector<shared_ptr<LearnMove>> m_moves;
		vector<shared_ptr<Evolution>> m_evolutions;
		vector<shared_ptr<Type>> m_types;
	};
}