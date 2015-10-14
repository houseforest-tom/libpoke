#pragma once

#include "util.h"
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
		// Internal id
		uint16_t m_id;

		// Display name
		string m_name;

		// List of possible abilities
		vector<shared_ptr<Ability>> m_abilities;

		// Species name (pokedex classification)
		string m_species;

		// Description text as seen in pokedex
		string m_description;

		// Base stats
		map<EStat, uint8_t> m_stats;

		// Catch rate (smaller rate <=> harder to catch)
		uint8_t m_catchRate;

		// Egg cycles
		uint16_t m_eggCycles;

		// List of egg groups this pokemon belongs to
		vector<shared_ptr<EggGroup>> m_eggGroups;

		// Effort value yields
		map<EStat, uint8_t> m_evYields;

		// Amount of base experience yielded per kill
		uint16_t m_expYield;

		// Growth rate => determines exp need per level
		EGrowthRate m_growthRate;

		// Base happiness
		uint8_t m_happiness;

		// Height [m]
		float m_height;

		// Weight [kg]
		float m_weight;

		// Moves this pokemon can learn
		vector<shared_ptr<LearnMove>> m_moves;

		// Possible evolutions
		vector<shared_ptr<Evolution>> m_evolutions;

		// Contains the one or two type(s) this pokemon has
		vector<shared_ptr<Type>> m_types;

	public:
		// Ctor
		PokedexEntry(
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
			float weight);
	};
}