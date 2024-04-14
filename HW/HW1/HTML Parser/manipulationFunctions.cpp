#include"htmlTable.h"
#include "saveFunctions.h"
#include <iostream>

void instructionsMessage()
{
	std::cout << std::endl;
	std::cout << "List of functionalities:" << std::endl << std::endl;
	std::cout << "1) Add rowNumber \"value1\" \"value2\" ..." << std::endl;
	std::cout << "2) Remove rowNumber" << std::endl;
	std::cout << "3) Edit rowNumber colNumber \"newValue\"" << std::endl;
	std::cout << "4) Print" << std::endl;
	std::cout << "5) Quit" << std::endl << std::endl;
	std::cout << "All changes made will be saved to the original file!" << std::endl << std::endl;

	std::cout << "This interface also supports character entity references!" << std::endl;
	std::cout << "Example: &#97 corresponds to a" << std::endl;
	std::cout << "=============================================" << std::endl << std::endl;
}

void manipulateTable(htmlTable& table, const char* fileName)
{
	if (!fileName)
	{
		return;
	}

	instructionsMessage();

	char commands[Constants::MAX_BUFFER_SIZE]{};

	while (true)
	{
		std::cout << "> ";
		std::cin >> commands;

		if (!strcmp(commands, "Quit"))
		{
			saveToFile(table, fileName);
			std::cout << "Changes successfully saved to the original file!";
			break;
		}

		else if (!strcmp(commands, "Remove"))
		{
			table.removeRow();
			std::cin.clear();
		}

		else if (!strcmp(commands, "Edit"))
		{
			table.editCell();
			std::cin.clear();
		}

		else if (!strcmp(commands, "Add"))
		{
			table.addRow();
			std::cin.clear();
		}

		else if (!strcmp(commands, "Print"))
		{
			table.printTable();
			std::cin.clear();
		}

		else
		{
			std::cout << "Command is not recognised! Try again!" << std::endl;
		}
	}
}
