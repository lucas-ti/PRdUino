#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

bool typeCheck (string type);
int variableLocator (string line);

int main()
{
	//Not sure how long to make this
	char content[8000000];
	
	string Filename;
	string line;
	string temp;
	string variableValues = "";
	int lineTracker = 0;
	int equalsLocation;
	int setupCheck;
	int variableLocation;

	ifstream firstFile;
	ifstream secondFile;
	ofstream newFile;
	cout << "Please enter the name of your Energia file.\n";
	cin >> Filename;
	firstFile.open("main.c");
	secondFile.open(Filename.c_str());

	// Checks to see if second file exists
	if (!secondFile.is_open())
	{
		Filename.append(".ino");
		secondFile.open(Filename.c_str());
		if (!secondFile.is_open())
		{
			cout << "File " + Filename + " could not be found\n";
			exit(1);
		}
	}
	
	newFile.open("PRUEnergiaFile.c");

	// Copies everything until main declaration
	if (firstFile.is_open())
  	{
    		while ( getline (firstFile,line) )
    		{
      			newFile << line << '\n';
			lineTracker++;
			//Line where main is
			//Must not be changed
			if (lineTracker == 14)
				break;
    		}
  	}

	// Copies everything above "void setup()" above main
	// Does not copy the equals part of variable declaration
	// Stores all of the variables into a string to be copied into setup/loop function declarations
	if (secondFile.is_open())
  	{
    		while ( getline (secondFile,line) )
    		{
			setupCheck = line.find("void setup()");
			// Checks to see if the line contains a variable type
			if (typeCheck(line))
			{
				// Determines if it has an equals
				equalsLocation = line.find('=');
				// If it has an equals, outputs only the things before the equals
				if (equalsLocation != std::string::npos)
				{
					temp = line.substr(0,equalsLocation);
					newFile << temp << ';' << '\n';
					// Collects and stores all variable values
					variableLocation = variableLocator(line);
					variableValues += '\t' + line.substr(variableLocation) + '\n';
					
				}
				else
					newFile << line << '\n';	
			}
			// Breaks if it reaches void setup()
			else if (setupCheck != std::string::npos)
				break;
      			else
				newFile << line << '\n';
    		}
  	}

	// Copies main until function declarations
	if (firstFile.is_open())
  	{
    		while ( getline (firstFile,line) )
    		{
      			newFile << line << '\n';
			lineTracker++;
			//Line where variables must be inserted
			//Must not be changed
			if (lineTracker == 17)
				break;
    		}
  	}

	newFile << variableValues << '\n';

	if (firstFile.is_open())
  	{
    		while ( getline (firstFile,line) )
    		{
      			newFile << line << '\n';
    		}
  	}

	// Copies setup and loop function definitions
	// Uses the correct arguments for setup and loop as defined above
	if (secondFile.is_open())
  	{
		newFile << "void setup()" << '\n';
    		while ( getline (secondFile,line) )
    		{
      			newFile << line << '\n';
    		}
  	}

	//Close all files
	firstFile.close();
	secondFile.close();
	newFile.close();
	
	return 0;
}

bool typeCheck (string type)
{
	if (type.find("int ") != std::string::npos ||
		type.find("bool") != std::string::npos ||
		type.find("char ") != std::string::npos ||
		type.find("word ") != std::string::npos ||
		type.find("long ") != std::string::npos ||
		type.find("short ") != std::string::npos ||
		type.find("float ") != std::string::npos ||
		type.find("double ") != std::string::npos ||
		type.find("string ") != std::string::npos)
	{
		return true;
	}
	return false;
}

int variableLocator (string line)
{
	if (line.find("volatile int") != std::string::npos)
		return 12;
	else if (line.find("volatile unsigned int") != std::string::npos)
		return 21;
	else if (line.find("volatile unsigned long") != std::string::npos)
		return 22;
	else if (line.find("unsigned int") != std::string::npos)
		return 12;
	else if (line.find("unsigned char") != std::string::npos)
		return 13;
	else if (line.find("unsigned long") != std::string::npos)
		return 13;
	else if (line.find("boolean") != std::string::npos)
		return 7;
	else if (line.find("char") != std::string::npos)
		return 4;
	else if (line.find("byte") != std::string::npos)
		return 4;
	else if (line.find("int") != std::string::npos)
		return 3;
	else if (line.find("word") != std::string::npos)
		return 4;
	else if (line.find("long") != std::string::npos)
		return 4;
	else if (line.find("short") != std::string::npos)
		return 5;
	else if (line.find("float") != std::string::npos)
		return 5;
	else if (line.find("double") != std::string::npos)
		return 6;
	else if (line.find("string") != std::string::npos)
		return 6;
	else 
		return 0;

}
