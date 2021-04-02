#include "cmath"
#include "kf/kf_log.h"
#include "example.h"

using namespace std;

int main()
{
	Example::inst().run();
	ofstream myfile;
	myfile.open("five.txt");
	myfile << "five by five equals 10 or 25 idk";
	myfile.close();
	return 0;
}
