#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>
using namespace std;
namespace fs = std::filesystem;


int main()
{
	string name;
	int finder;
	cout << "Enter device:" << " ";
	cin >> name;
	finder = name.find("garbage");
	if (finder == -1)
	{
		for (auto& p : fs::directory_iterator("logs"))
		{
			int count = 0;
			int count1 = 0;
			string date = p.path().string();
			for (int i = 0; i < date.size(); i++)
			{
				if (date[count] == '(')
				{
					count++;
					date = date.substr(count);
					break;
				}
				else
				{
					count++;
				}
			}
			for (int l = 0; l < date.size(); l++)
			{
				if (date[count1] == ')')
				{
					date = date.substr(0, count1);
					break;
				}
				else
				{
					count1++;
				}
			}

			ifstream file;
			file.open(p.path());
			string check, sec, value;
			while (!file.eof())
			{
				getline(file, check);
				if (check.size() == 0)
				{
					continue;
				}
				int counter = 0;
				int counter1 = 0;
				string current;

				
				for (int j = 0; j < check.size(); j++)
				{

					if (check[counter] == ':')
					{
						current = check.substr(counter + 1);
						counter--;
						sec = check[counter];
						counter++;
						break;
					}
					else
					{
						counter++;
					}

				}

				for (int k = 0; k < current.size(); k++)
				{
					if (current[counter1] == ':')
					{
						value = current.substr(counter1);
						current = current.substr(0, counter1);
						break;
					}
					else
					{
						counter1++;
					}
				}

				if (current == name)
				{
					cout << date << "-" << sec <<":"<< " " << current <<" "<< value << endl;
				}
				
			}

		}
	}
	else
	{
		cout << "Nothing found" << endl;
	}
	system("pause");
}