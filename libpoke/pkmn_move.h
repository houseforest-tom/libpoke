#pragma once

#include "util_csv.h"

namespace pkmn
{
	using namespace std;

	// Move categories
	enum class EMoveCategory : uint8_t
	{
		PHYSICAL,
		SPECIAL,
		STATUS,

		COUNT
	};

	// Move information
	class Move : public util::CSVConstructable
	{
	private:
		// Internal id
		uint16_t m_id;

		// Display name
		string m_name;

		// Description text
		string m_desc;

		// Move category
		EMoveCategory m_cat;

		// Base power
		uint8_t m_power;

		// Accuracy [0..100]
		uint8_t m_accuracy;

		// Default amount of maximum PP
		uint8_t m_pp;

	public:
		// Ctor
		Move(const util::CSVParsedObj &csvobj);

		// Getters
		inline uint16_t getId(void) const { return m_id; }
		inline const string &getName(void) const { return m_name; }
		inline const string &getDescription(void) const { return m_desc; }
		inline EMoveCategory getCategory(void) const { return m_cat; }
		inline uint8_t getPower(void) const { return m_power; }
		inline uint8_t getAccuracy(void) const { return m_accuracy; }
		inline uint8_t getPP(void) const { return m_pp; }
	};
}