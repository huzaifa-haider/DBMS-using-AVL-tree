#include <iostream>
#include<fstream>
#include <string>
using namespace std;
class node {
public:

	int id;
	int	year;
	string cause113;
	string cause;
	string State;
	unsigned int deaths;
	int age;
	

	node() = default;

	bool operator==(const node& other) const
	{
		return id == other.id && year == other.year && cause113 == other.cause113 && cause == other.cause && State == other.State && deaths == other.deaths && age == other.age;
	}
};
void readFromFile(node*& obj) {//reading data from file of task 1
	string text;
	int obj_iterator = 0;
	int cols_in_datasheet = 10;
	ifstream in_file;
	string sep[10]; int k = 0;
	in_file.open("E:\\uni\\Semester 3\\DS\\DataProject\\datafiles\\NCHS_-_Leading_Causes_of_Death__United_States_1.csv");
	while (getline(in_file, text)) {
		if (text[0] == 'I' && text[1] == 'D')//if its first head row then skip it 
			continue;
		//cout << text << endl;
		//cout << text[text.length()-2] << endl;
		for (int j = 0; j < text.length(); j++) {//extracting data by comma into sep[] string array
			if (text[j] == ',') {
				k++;
				continue;

			}

			sep[k] += text[j];
		}
		//loading data into object array
		obj[obj_iterator].id = stoi(sep[0]);
		obj[obj_iterator].year = stoi(sep[1]);
		obj[obj_iterator].cause113 = sep[2];
		obj[obj_iterator].cause = sep[3];
		obj[obj_iterator].State = sep[4];
		obj[obj_iterator].deaths = stoul(sep[5]);
		obj[obj_iterator].age = stof(sep[6]);



		obj_iterator++;
		for (int i = 0; i < cols_in_datasheet; i++)
			sep[i] = "";
		k = 0;
		cout << obj[obj_iterator].id << " " << obj[obj_iterator].year << " " << obj[obj_iterator].cause113 << " " << obj[obj_iterator].cause << " " << obj[obj_iterator].State << " " << obj[obj_iterator].deaths << endl;
	
	}

}