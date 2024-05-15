#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include"AVL.h"
#include <conio.h>
#include<direct.h>
#include <sys/types.h>
#include <sys/stat.h>
//#include"Header.h"
using namespace std;

int main()
{
	 
	_mkdir("d:/DBMS");
	_mkdir("d:/DBMS/AVL");
	_mkdir("d:/DBMS/AVL/State");
	_mkdir("d:/DBMS/AVL/Years");
	_mkdir("d:/DBMS/AVL/Disease");
	_mkdir("d:/DBMS/AVL/All");
	string path = "d:/DBMS/AVL/State";
	ofstream file(path);
	file.close();

//	string* states = new string[];


	AVL<int, int, int, float> x;

	string filename = "\0";
	
	int line_no = 0;

	int totalenteries = 0;

	string one = "datafiles/NCHS_-_Leading_Causes_of_Death__United_States_";
	string digit = "1";
	string files[10];
	for (int i = 0; i < 9; i++) {
		string combine = one + digit;
		files[i] = combine;
		digit[0]++;
	}
	files[9] = "datafiles/NCHS_-_Leading_Causes_of_Death__United_States_10";
	string Text;
	int id = 0, year = 0, deaths=0;
	float deathrate = 0;
	string cause113, causename, state;


	for (int i = 0; i < 10; i++)
	{
		ifstream MyReadFile(files[i] + ".csv");
		 filename = "\0";
		 line_no = 0;

		  filename = files[i] + ".csv";
		
		
		while (getline(MyReadFile, Text)) {
		//	cout << Text << endl;
			line_no++;
			totalenteries++;
			bool idf = true, yearf = false, deathsf = false, causenamef = false, cause113f = false, statef = false, deathratef = false;
			bool brc = false, cmms = false;
			int count = 0;
			string one = "\0", two = "\0", three = "\0", four = "\0", five = "\0", six = "\0", seven = "\0";
			for (int i = 0; i < Text.length(); i++) {

				if (Text[0] == 'I' && Text[1] == 'D') {
					line_no--;
					// totalenteries--;
					break;
				}

				if (Text[i] == '(') {
					brc = true;
				}
				if (Text[i] == ')' && brc == true) {
					brc = false;
				}

				
				if (int(Text[i]) == 34) {
					count++;
				}


				if (idf == true) { one += Text[i]; }
				if (yearf == true) { two += Text[i]; }
				if (cause113f == true) { three += Text[i]; }
				if (causenamef == true) { four += Text[i]; }
				if (statef == true) { five += Text[i]; }
				if (deathsf == true) { six += Text[i]; }
				if (deathratef == true) { seven += Text[i]; }

				if (Text[i + 1] == ',' && idf == true) {
					idf = false;
					yearf = true;
					i++;

				}

				if (Text[i + 1] == ',' && yearf == true) {
					yearf = false;
					cause113f = true;
					i++;
				}

				if (Text[i + 1] == ',' && cause113f == true && brc == false && (count == 2 || count == 0)) {
					cause113f = false;
					causenamef = true;
					i++;
				}




				if (Text[i + 1] == ',' && causenamef == true) {
					causenamef = false;
					statef = true;
					i++;
				}

				if (Text[i + 1] == ',' && statef == true) {
					statef = false;
					deathsf = true;
					i++;
				}

				if (Text[i + 1] == ',' && deathsf == true) {
					deathsf = false;
					deathratef = true;
					i++;
				}


			}
			//	int id = stoi(one);

			if (one == "\0") {
				continue;
			}

			//cout << " 1: " <<one.length() << " 2: " << two.length() << " 3: " << three.length() << " 4: " << four.length() << " 5:" << five.length() << " 6: " << six.length() << " 7: " << seven.length() << endl;
			//cout << Text << endl;

			// data for the each node from cvs files 
			int id = std::stoi(one);
			int year = std::stoi(two);
			string  Cause113 = three;
			string  CauseName = four;
			string state = five;
			float adjustedrate = std::stof(six);
			int deaths = std::stoi(seven);
			count++;
			x.root = x.insert(x.root, id, year, Cause113, CauseName, state, adjustedrate, deaths);

		}
	}

	
	string *y= x.createstatefiles(x.root);
	int nos = x.noofstates(x.root);
	x.PutDatainstates(x.root, y,nos);

	int *a= x.createyearfiles(x.root);
	int noy = x.noofyears(x.root);
	x.PutDatainyears(x.root,a,noy);




	//cout << line_no << " " <<filename<< endl;
	jump:
	cout << "----->>main menu<<-----" << endl;
	cout << "----->>Enter 1 : To Search Data  <<-----" <<  endl;
	cout << "----->>Enter 2 : To Update Data  <<-----" << endl;
	cout << "----->>Enter 3 : To Delete Data <<-----" << endl;
	cout << "----->>Enter 3 : To Exit <<-----" << endl;
	int c = 0;
	cin >> c;
	if (c == 1)
	{
			jump1:
			cout << "----->> Search Menu<<-----" << endl;
			cout << "----->>Enter 1 : To view Data By States <<-----" << endl;
			cout << "----->>Enter 2 : To view Data By Years <<-----" << endl;
			cout << "----->>Enter 3 : To view Data By of Disease <<-----" << endl;
			cout << "----->>Enter 4 : To view Data By of ID <<-----" << endl;
			cout << "----->>Enter 5 : To Go Back <<-----" << endl;	
			cout << "----->>Enter 6 : To Exit <<-----" << endl;
			int c1 = 0;
			cin >> c1;

			if(c1==1){		
				cout << "Enter the name of the state :";
				string name = "\0";
				cin >> name;
				cout << endl;
				searchstate(name);
					
			}
			else if (c1 == 2) {
				cout << "----->>Enter 1 : To Search year By one <<-----" << endl;
				cout << "----->>Enter 2 : To Search years in a range <<-----" << endl;
				int c3 = 0;
				cin >> c3;
					
					 if (c3 == 1) {
						 cout << "Enter the year to be Searched :";
						 string name = "\0";
						 cin >> name;
						 cout << endl;
						 searchsyear(name);
						 goto jump1;
							
					 }
					else if (c3 == 2) {
						 string name2 = "\0";
						 cout << "Enter the year to be Search from  : ";
						 string name1 = "\0";
						 cin >> name1;
						 cout << "- To : ";
						 cin >> name2;
						 cout << endl;
						 searchsyearrange(name1, name2);
						 goto jump1;
					 }


				
			}
		
			else if (c1==3){}
			else if (c1==4) {}
			else if (c1 == 5) { goto jump; }
			else if (c1==6) {}
		












	}
	else if (c==2 ){
	
	
	}
	else if (c==3) {

	}
	else if(c==4){}
	else {
		goto jump;
	}

	
	 















}




















































