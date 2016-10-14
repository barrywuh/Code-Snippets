
#include <fstream>  
#include <string>  
#include <iostream> 
#include <random>

using namespace std;

int ageRange(string shopperID);

int main()
{
	ifstream file("prediction.csv");
	
	ofstream dataFile;
	dataFile.open("prediction4.csv", ios::app);
	string value;
	int i=0;
	//process the first line;
	if (file.good()){
		getline(file, value);
		dataFile << value << endl;
	}
	//process the other lines;
	while (file.good())
	{				
		getline(file, value);		
		string tmpStr;
		int tmp = value.find_last_of(',');
		tmpStr = value.substr(0, tmp);
		dataFile << tmpStr << ",";

		string shopperID;
		int temp = value.find_first_of(',');
		shopperID = value.substr(0, temp);
		int tempAge = ageRange(shopperID);
		//cout << "shopperID is " << shopperID << endl;
		//cout << "ageRang is " << tempAge << endl;
		
		double tmpRdm = (double)(rand() % 10000 + 1); // a random number in range [1,10000];
		tmpRdm = tmpRdm / 10000;

		if (tempAge > 5 && tmpRdm <0.5){						
			dataFile << tmpRdm << endl;
		}
		else if (tempAge > 5)
			dataFile << 1 - tmpRdm << endl;
		else if (tmpRdm < 0.5)
			dataFile << 1 - tmpRdm << endl;
		else
			dataFile << tmpRdm << endl;

		cout << "---"<<i << endl;
		i++;		
		//if (i > 10)
			//break;
	}
	dataFile.close();	
	return 0;
}

int ageRange(string shopperID)
{
	ifstream userFile("user_info_format1.csv");
	while (userFile.good())
	{
		string userStr;
		getline(userFile, userStr);
		size_t found = userStr.find(shopperID);
		if (found != string::npos)
		{
			int tmp = userStr.find_first_of(',');
			int tmp1 = userStr.find_last_of(',');
			string ageStr = userStr.substr(tmp + 1, tmp1);
			if (ageStr == "NULL")
				return 8;
			else
				return stoi(ageStr);
		}		
	}
	return 7;

}