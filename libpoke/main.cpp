#include "pkmn_pokedex_entry.h"
#include "util_csv.h"

using namespace std;

int main(int argc, char **argv)
{
	vector<string> csvFileNames = {"pokemon", "pokemon_stats" };
	pkmn::util::CSVIterator iter;
	ifstream file;
	map<string, vector<shared_ptr<pkmn::util::CSVParsedObj>>> csvParsedObjs;

	for (const auto &fname : csvFileNames)
	{
		file.open("./data/csv/" + fname + ".csv", ifstream::in);
		for (iter = pkmn::util::CSVIterator(file); iter != pkmn::util::CSVIterator(); ++iter)
		{
			csvParsedObjs[fname].push_back(iter.obj());
		}
		file.close();
	}

	return getchar();
}