#include <bits/stdc++.h>
using namespace std;
vector<string> title, row;
bool found = false;
int entity_no = 0;

int select() {
	cout << "Press 1: To search by Station" << endl;
	cout << "Press 2: To search by Air Quality" << endl;
	cout << "Press 3: To search by O3 Value" << endl;
	cout << "Press 4: To search by NO2 Value" << endl;
	cout << "Press 5: To search by PM10 Value" << endl;
	cout << "Press 0: To Terminate" << endl;
	cout << "===================================\n" << endl;
	cout << "Press any Option: ";
	int key;
	cin >>  key;
	cout << endl;

	return key;
}

string selctTitle(int opt) {
	string val, v;

	if(opt == 1) {
		v = "Barcelona - ";
		cout << "Enter any city name [Ex- Sants]: ";
		cin >> val;
		v += val;
		val = v;
	}
	else if(opt == 2) {
		cout << "Enter Air Quality type(Good/Moderate) [Ex- Good]: ";
		cin >> val;
	}
	else if(opt == 3) {
		cout << "Enter O3 Value [Ex- 2h]: ";
		cin >> val;
	}
	else if(opt == 4) {
		cout << "Enter N02 Value[Ex- 1]:  ";
		cin >> val;
	}
	else if(opt == 5) {
		cout << "Enter the PM10 Value [Ex- 20]:  ";
		cin >> val;
	}
	v = "\"";
	v += val;
	val = v;
	val += "\"";
	return val;
}

void show() {
	found = true;
	entity_no++;
	cout << "================================================" << endl;
	cout << setw(20) << "Matched : " << entity_no << setw(20) << endl;
	cout << "================================================" << endl;
	for(int i = 0; i < title.size(); i++) {
		int formatsize = 15 - title[i].size();
		cout << title[i] << setw(formatsize) << ": " << row[i] << endl;
	}
	cout << "=================================================\n" << endl;
}

void check(int opt, string val) {
	if(opt == 1) {
		if(row[0] == val) show();
	}
	else if(opt == 2) {
		if(row[1] == val) show();
	}
	else if(opt == 3) {
		if(row[6] == val) show();
	}
	else if(opt == 4) {
		if(row[9] == val) show();
	}
	else if(opt == 5) {
		if(row[12] == val) show();
	}
}


int main() {
	while(true) {
		ifstream myFile;
		myFile.open("air_quality_Nov2017.csv");  //file opened for reading


		string line, word;
		found = false;
		entity_no = 0;

		title.clear();
		int counter = 0;

		int option = select();
		if(option == 0) break;
		string select_Title = selctTitle(option);


		while(myFile.good()) {
			row.clear();

			getline(myFile, line);
			stringstream ss(line);


			while(getline(ss, word, ',')) {
				if(counter < 15) {
					title.push_back(word);
					counter++;
				}
				else {
					row.push_back(word);
				}
			}
			if(row.size() > 0) check(option, select_Title);
		}

		// Error : expected data doesn't exist.
		if(found == false) {
			cout << "Your searching data doesn't exist\n" << endl;
		}
	}

	return 0;
}
