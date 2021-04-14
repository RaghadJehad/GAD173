#include "SaveLoad.h"
#include <iostream>
#include <fstream>
using namespace std;

void SaveLoad::Save(std::string filename, int* buffer, int X_COUNT, int Y_COUNT)
{
	ofstream myfile;
	myfile.open(filename);

	for (size_t x = 0; x < X_COUNT; x++)
	{
		for (size_t y = 0; y < Y_COUNT; y++)
		{
			int i = x + y * X_COUNT;
			myfile << buffer[i] << (", ");
		}
		myfile << std::endl;
	}
	myfile.close();
}
void SaveLoad::Load(std::string& filename) 
{

}
	