#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void encrypt(string filename);
void decrypt(string filename);
void getKey(char arr[]);
const int numberOfLines(string filename);

int main()
{
	string input;
	string file1 = "text.txt";
	string file2 = "textEncrypted.txt";
	int exit = 0;

	//While loop to ensure that the user inputs a possible choice in the prompter
	while (exit == 0)
	{
		cout << "Please enter 'en' for encryption and 'de' for decryption: ";
		cin >> input;
		if (input == "en")
		{
			encrypt(file1);
			cout << "Files encryptionKey.txt and text.txt are being processed...\n"
				<< "Please open the output file textEncrypted.txt\n\n";
			exit = 1;
		}
		else if (input == "de")
		{
			decrypt(file2);
			cout << "Files encryptionKey.txt and textEncrypted.txt are being processed...\n"
				<< "Please open the file textDecrypted.txt\n\n";
			exit = 1;
		}
		else
		{
			cout << "Not a valid input, please try again" << endl;
		}

	}

	system("pause");
	return 0;
}

void encrypt(string filename)
{
	int count = 0;
	count = numberOfLines("encryptionKey.txt");

	/*The following code creates dyamic string arrays to 
	store the files into memory */
	typedef string * stringArr;
	const int lines = numberOfLines(filename);
	stringArr arr = new string[lines];  
	stringArr key = new string[count];
	//////////////////////////////////
	// opening the fstream library to read text from files 
	// and store them in memory
	// code lines 68-90 read the encrpytion key and file text and store them
	//////////////////////////////////
	ifstream inText;
	inText.open(filename);
	if (!inText)
	{
		cout << "ERROR\n\n";
		system("pause");
	}
	for (int i = 0; i < lines; i++)
	{
		getline(inText, arr[i]);
	}
	inText.close();
	inText.open("encryptionKey.txt");
	if (!inText)
	{
		cout << "ERROR\n\n";
		system("pause");
	}
	for (int i = 0; i < count; i++)
	{
		getline(inText, key[i]);
	}
	inText.close();
	/////////////////////////////////////////////
	/*The following nested for loops compare
	each string with the encrption key and swaps the values*/
	ofstream outFile("textEncrypted.txt");
	for (int i = 0; i < lines; i++)
	{
		string holder1 = arr[i];
		for (int j = 0; j < holder1.size(); ++j)
		{
			for (int k = 0; k < count; k++)
			{
				string holder2 = key[k];
				if (holder2[0] == holder1[j])
				{
					holder1[j] = holder2[2];
				}

			}
			outFile << holder1[j];
		}
		outFile << endl;
	}
	outFile.close();
}

void decrypt(string filename)
{
	string holder = filename;
	int count = 0;
	count = numberOfLines("encryptionKey.txt");

	/*The following code creates dyamic string arrays to
	store the files into memory */
	typedef string * stringArr;
	const int lines = numberOfLines(holder);
	stringArr arr = new string[lines];
	stringArr key = new string[count];
	//////////////////////////////////
	// opening the fstream library to read text from files 
	// and store them in memory
	// code lines 133-158 read the encrpytion key and file text and store them
	//////////////////////////////////
	ifstream inText;
	inText.open(filename);
	if (!inText)
	{
		cout << "ERROR\n\n";
		system("pause");
	}

	for (int i = 0; i < lines; i++)
	{
		getline(inText, arr[i]);
	}
	inText.close();
	inText.open("encryptionKey.txt");
	if (!inText)
	{
		cout << "ERROR\n\n";
		system("pause");
	}
	for (int i = 0; i < count; i++)
	{
		getline(inText, key[i]);
	}
	inText.close();
	/////////////////////////////////
	/*The following nested for loops compare
	each string with the encrption key and swaps the values*/
	ofstream outFile("textDecrypted.txt");
	for (int i = 0; i < lines; i++)
	{
		string holder1 = arr[i];
		for (int j = 0; j < holder1.size(); ++j)
		{
			for (int k = 0; k < count; k++)
			{
				string holder2 = key[k];
				if (holder2[2] == holder1[j])
				{
					holder1[j] = holder2[0];
				}

			}
			outFile << holder1[j];
		}
		outFile << endl;
	}
	outFile.close();
}

//Function calculates the number of lines in 
//the file sent to the function
const int numberOfLines(string filename)
{
	string line;
	int number = 0;
	ifstream infile(filename); // Opening fstream library read files
	if (infile)  
	{
		while (getline(infile, line))  
		{
			number++;
		}
	}
	else
	{
		cout << "Can't Count\nRestart Program";
		return 0;
	}
	infile.close();
	return number;
}