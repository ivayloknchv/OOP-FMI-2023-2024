#include "saveFunctions.h"

void saveTD(std::ofstream& ofs, const char* field)
{
	ofs << "		<td>";
	ofs << field;
	ofs << "</td>" << std::endl;
}

void saveTH(std::ofstream& ofs, const char* field)
{
	ofs << "		<th>";
	ofs << field;
	ofs << "</th>" << std::endl;
}

void saveRow(std::ofstream& ofs, const Row& currentRow)
{
	ofs << "	<tr>" << std::endl;

	for (int i = 0; i < currentRow.colCount; i++)
	{
		if (currentRow.headingsHistogram[i])
		{
			saveTH(ofs, (const char*)&currentRow.fields[i]);
		}
		else
		{
			saveTD(ofs, (const char*)&currentRow.fields[i]);
		}
	}

	ofs << "	</tr>" << std::endl;
}

void saveToFile(std::ofstream& ofs, const htmlTable& table)
{
	ofs << "<table>" << std::endl;

	for (int i = 0; i < table.rowCount; i++)
	{
		saveRow(ofs, table.rows[i]);
	}

	ofs << "</table>" << std::endl;
}

void saveToFile(const htmlTable& table, const char* fileName)
{
	if (!fileName)
	{
		return;
	}

	std::ofstream ofs(fileName, std::ios::out);

	if (!ofs.is_open())
	{
		return;
	}

	saveToFile(ofs, table);

	ofs.close();
}