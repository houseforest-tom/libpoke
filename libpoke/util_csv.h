#pragma once

#include "util.h"

namespace pkmn
{
	namespace util
	{
		using namespace std;

		// Parsed object. Contains stringified key-value-pairs.
		class CSVParsedObj
		{
		private:
			// Attributes (Key-value-pairs)
			map<string, string> m_attributes;

		public:
			// Returns an attribute (readonly)
			inline const string &operator[](const string &attribute) const
			{
				if (m_attributes.find(attribute) != m_attributes.end())
					return m_attributes.at(attribute);
				return "";
			}

			// Returns an attribute (readwrite)
			inline string &operator[](const string &attribute)
			{
				// If it doesn't exist yet, create it
				if (m_attributes.find(attribute) == m_attributes.end())
					m_attributes.insert(make_pair(attribute, string()));
				return m_attributes.at(attribute);
			}

			// Returns the names of all attributes
			inline const vector<string> &getAttributeNames(void) const
			{
				vector<string> attrs;
				attrs.reserve(m_attributes.size());
				for (const auto &pair : m_attributes)
					attrs.push_back(pair.first);
				return attrs;
			}

			// "JSON" pretty-printed string
			string prettyprinted(void) const;
		};
	
		// Single row
		class CSVRow
		{
		private:
			// CSV data
			vector<string> m_data;

		public:
			// Returns the substring (attribute value) at the given index
			inline const string &operator[](unsigned index) const { return m_data[index]; }

			// Returns the number of attributes
			inline unsigned size() const { return m_data.size(); }

			// Reads the next row
			void readNextRow(istream &stream);

			// Parses this row as an object using the given attribute names
			shared_ptr<CSVParsedObj> parse(const vector<string> &attributeNames) const;
		};

		// Reads the next row into the row object
		inline istream &operator>>(istream &stream, CSVRow &row)
		{
			row.readNextRow(stream);
			return stream;
		}

		// Iterator for CSV files
		class CSVIterator
		{
		private:
			// CSV file stream
			raw_ptr<istream> m_pStream;

			// Currently parsed row
			CSVRow m_row;

			// Attribute names (first row elements)
			vector<string> m_attributeNames;

		public:
			// Type definitions
			typedef input_iterator_tag     iterator_category;
			typedef CSVRow                 value_type;
			typedef size_t                 difference_type;
			typedef raw_ptr<CSVRow>        pointer;
			typedef CSVRow&                reference;

			// Ctor constructs iterator at start of file stream
			CSVIterator(istream &stream);

			// Default ctor => iterator at end by default
			CSVIterator(void);

			// Pre increment
			CSVIterator &operator++(void);

			// Post increment
			CSVIterator operator++(int);

			// Current row
			inline const CSVRow &row(void) { return m_row; }

			// Current row as object
			inline shared_ptr<CSVParsedObj> obj(void) { return m_row.parse(m_attributeNames); };

			// Comparison (returns true if stream is null)
			bool operator==(CSVIterator const& rhs);
			bool operator!=(CSVIterator const& rhs);
		};

		// Base class for objects that can be constructed from parsed CSV data
		class CSVConstructable
		{
		public:
			// Construct this object from the parsed CSV data
			inline CSVConstructable(const CSVParsedObj &csvobj) { };
		};
	}
}