#include "stdafx.h"
#include <iostream>
using namespace std;

//xml output file of UT result 
static const std::string ksTestOutputFile = "xml:XFilmingServiceUT_result.xml";

int main(int argc, char* argv[])
{
	testing::GTEST_FLAG(output)=ksTestOutputFile;
	testing::InitGoogleTest(&argc, argv);  

	(void)RUN_ALL_TESTS();

	cout << "Press Any Key to continue" << endl;
	char c;
	cin  >> c;

	return 0;
}