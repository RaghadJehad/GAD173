#include "SaveLoad.h"
#include <iostream>
#include <fstream>  //writes & reads files

using namespace std;

void SaveLoad::Save(std::string filename, int* buffer, int X_COUNT, int Y_COUNT)
{
	ofstream myfile;           //writes on files
	myfile.open(filename);

	for (size_t y = 0; y < Y_COUNT; y++)
	{
		for (size_t x = 0; x < X_COUNT; x++)
		{
			int i = x + y * X_COUNT;
			myfile << buffer[i] << (", ");
		}
		myfile << (" $");
		myfile << std::endl;
	}
	myfile.close();
}
void SaveLoad::Load(std::string filename, int mapArraySize, Map& map)
{
	string line;
	ifstream myfile(filename);		//reads from files
	if (myfile.is_open())
	{
		int start = 0;
		bool firstComma = true;
		int previousComma = 0;
		int mapIndex = 0;

		while (getline(myfile, line))
		{
			for (int i = 0; ; i++)
			{
				if (line[i] == ',')
				{
					if (firstComma)
					{
						start = 0;
						firstComma = false;
					}
					else
						start = previousComma;

					string numStr = line.substr(start, i - previousComma);
					std::cout << numStr << " ";
					map.map[mapIndex] = std::stoi(numStr);
					previousComma = i + 1;
					mapIndex++;
				}
				if (line[i] == '$')
				{
					firstComma = true;
					start = 0;
					previousComma = 0;
					break;
				}
			}
			std::cout << endl;
		}
		myfile.close();
	}
	else cout << "Unable to open file";
	map.Load();
}
	
	/*string line = "4, 20, 9, 11";
	int cutStart = 0;
	int commaIndex = -1;

	while (true)
	{	
		cutStart = commaIndex + 1;
			commaIndex = line.find(',', commaIndex + 1);
			string numStr2 = line.substr(cutStart, commaIndex - cutStart);
			int num = std::stoi(numStr2);
			std::cout << num << endl;
		if (commaIndex < 0)
		{
			break;
		}
		std::cout << "\n";
		
	}*/
	