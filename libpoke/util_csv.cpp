#include "util_csv.h"

namespace pkmn
{
	namespace util
	{
		void CSVRow::readNextRow(istream &stream)
		{
			string line, cell;
			getline(stream, line);
			stringstream lineStream(line);

			m_data.clear();
			while (getline(lineStream, cell, ','))
			{
				m_data.push_back(cell);
			}
		}

		shared_ptr<CSVParsedObj> CSVRow::parse(const vector<string> &attributeNames) const
		{
			shared_ptr<CSVParsedObj> pObj = make_shared<CSVParsedObj>();

			for (unsigned i = 0; i < attributeNames.size(); ++i)
			{
				(*pObj)[attributeNames[i]].assign(m_data[i]);
			}

			return pObj;
		}

		string CSVParsedObj::prettyprinted(void) const
		{
			string result = "{\n";
			for (auto &attr : m_attributes)
			{
				result += "\t" + attr.first + " : " + attr.second + "\n";
			}
			return result + "}";
		}

		CSVIterator::CSVIterator(istream &stream)
			:m_pStream(stream.good() ? &stream : nullptr)
		{
			++(*this);
			for (unsigned attr = 0; attr < m_row.size(); ++attr)
				m_attributeNames.push_back(m_row[attr]);
			++(*this);
		}

		// Default ctor => iterator at end by default
		CSVIterator::CSVIterator(void)
			: m_pStream(nullptr) 
		{
		}

		// Pre increment
		CSVIterator &CSVIterator::operator++(void)
		{ 
			if (m_pStream != nullptr) 
			{ 
				(*m_pStream) >> m_row; 
				m_pStream = m_pStream->good() ? m_pStream : nullptr; 
			}

			return *this; 
		}

		// Post increment
		CSVIterator CSVIterator::operator++(int)
		{ 
			CSVIterator tmp(*this);
			++(*this);
			return tmp; 
		}

		// Comparison (also returns true if streams are both null)
		bool CSVIterator::operator==(CSVIterator const& rhs)
		{ 
			return ((this == &rhs) || ((m_pStream == nullptr) && (rhs.m_pStream == nullptr))); 
		}

		// Negated comparison operator
		bool CSVIterator::operator!=(CSVIterator const& rhs) { return !((*this) == rhs); }
	}
}
