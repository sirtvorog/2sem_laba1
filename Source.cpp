#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

void loh() {
	cout << "";
	cin.clear();                           
	cin.ignore(1000, '\n');  
	SetConsoleTextAttribute(handle, FOREGROUND_RED );
		cout << "������ �����. ����������, ��������� �������." << endl;
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
}

void clearStream() {
	cin.clear();
	cin.ignore(1000, '\n');
}


struct Student {
	int ID;
	
	string FIO;
	char sex;
	int groupNumber;
	int groupID;
	int grade[8];
	float score;
	string success;
	int money;

	Student newStudent() {
		Student student;

		student.ID = studentsCounter;
		studentsCounter += 1;

		string vvod = "";
		string memory = "";


		cout << "\n\n������� ������� ��������: ";
		clearStream();
		getline(cin, vvod);

		cout << "\n������� ��� ��������: ";
		getline(cin, memory);
		vvod = vvod + " " + memory;

		cout << "\n������� �������� ��������: ";
		getline(cin, memory);
		vvod = vvod + " " + memory;


		student.FIO = vvod;

		char sex;
		bool flag = true;
		while (flag) {
			cout << "\n������� ��� ��������:\n1.M������ - � \n2.������� -  �\n3.������ - �\n\n��� �����: ";
			cin >> sex;
			if (sex != '�' and sex != '�' and sex != '�') {
				loh();
			}

			else {
				student.sex = sex;
				flag = false;

			}
		}


		flag = true;
		int groupNumber;
		while (flag) {
			cout << "\n� ����� ������ ������� ��������? (1, 2 ��� 3)\n\n��� �����: ";
			cin >> groupNumber;

			if (groupNumber != 1 and groupNumber != 2 and groupNumber != 3) {

				loh();

			}

			else {
				switch (groupNumber) {

				case (!isdigit): {
					loh();
				}break;

				case 1:
				{
					if (firstGroup >= groupLimit) {
						cout << "\n\n��� ������ ��� ������� :(  \n\n";
					}

					else {

						firstGroup += 1;

						student.groupNumber = 1;

						student.groupID = firstGroup;
						cout << "\n����� �������� � ������ --> " << student.groupID;
						flag = false;

					}
				}break;

				case 2:
				{
					if (secondGroup >= groupLimit) {
						cout << "\n\n��� ������ ��� ������� :(  \n\n";
					}

					else {

						secondGroup += 1;

						student.groupNumber = 2;

						student.groupID = secondGroup;
						cout << "\n����� �������� � ������ --> " << student.groupID;
						flag = false;

					}
				}break;

				case 3:
				{
					if (thirdGroup >= groupLimit) {
						cout << "\n\n��� ������ ��� ������� :( \n\n";
					}

					else {

						thirdGroup += 1;

						student.groupNumber = 3;

						student.groupID = thirdGroup;
						cout << "\n����� �������� � ������ --> " << student.groupID;
						flag = false;

					}
				}break;



				}
			}
		}

		float count = 0;
		int grade;
		flag = true;
		bool successflag = true;
		bool withoutScholarship = true;
		while (flag) {
			cout << "\n������� ������ �������� �� �������� � ������(����� ������) \n";
			for (int i = 0; i < 8; i++) {

				cin >> grade;

				while (grade > 5 or grade < 2) {
					loh();
					cin >> grade;

				}

				if (grade > 0 and grade < 6) {
					student.grade[i] = grade;

					if (grade < 5) successflag = false;
					if (grade < 4) withoutScholarship = false;

					count += student.grade[i];
					flag = false;
				}


			}
		}

		student.score = count / 8;
		cout << "\n\n������� ���� �������� ����� " << student.score << "\n\n";

		if (successflag == true) {
			student.success = "��������";
		}

		if (successflag == false and withoutScholarship == true) {
			student.success = "��������";
		}

		if (successflag == false and withoutScholarship == false) {
			student.success = "��������";
		}

		bool moneyFlag = true;
		int money;
		cout << "\n\n������� �������� ��������: ";
		cin >> money;
		while (student.money != money) {
			if (moneyFlag != isdigit(money)) {
				student.money = money;
			}
			else {
				loh();
				cin >> money;
			}
		}


		database[student.ID] = student;
		return student;
	}
};


int firstGroup = 0;
int secondGroup = 0;
int thirdGroup = 0;
const int universitySize = 90;
const int groupLimit = 4;
int studentsCounter = 0;
Student database[90];



void cocktailSort() {
	bool swapped = true;
	int start = 0;
	int end = studentsCounter - 1;

	while (swapped) {
		swapped = false;

		// ������ ����� �������
		for (int i = start; i < end; ++i) {
			if (database[i].money > database[i + 1].money) {
				std::swap(database[i], database[i + 1]);
				swapped = true;
			}
		}

		if (!swapped) {
			break;
		}

		swapped = false;
		--end;

		// ������ ������ ������
		for (int i = end - 1; i >= start; --i) {
			if (database[i].money > database[i + 1].money) {
				std::swap(database[i], database[i + 1]);
				swapped = true;
			}
		}

		++start;
	}
}


void changeStudent(int ID) {
	int changeChoose;
	cout << "\n\n�������� ������, ������� �� ������ ��������: \n1.��� \n2.��� \n3. ����� ������ \n4. ������\n5. ��������\n\n��� �����: ";
	cin >> changeChoose;
	switch (changeChoose){

		case (!isdigit): {
			loh();
		}break;

		case 1: {
			string vvod = "";
			string memory = "";


			cout << "\n\n������� ������� ��������: ";
			clearStream();
			getline(cin, vvod);

			cout << "\n������� ��� ��������: ";
			getline(cin, memory);
			vvod = vvod + " " + memory;

			cout << "\n������� �������� ��������: ";
			getline(cin, memory);
			vvod = vvod + " " + memory;


			database[ID].FIO = vvod;
		} break;

		case 2: {
			char sex;
			bool flag = true;
			while (flag) {
				cout << "\n������� ��� ��������:\n1.M������ - � \n2.������� -  �\n3.������ - �\n\n��� �����: ";
				cin >> sex;
				if (sex != '�' and sex != '�' and sex != '�') {
					loh();
				}

				else {
					database[ID].sex = sex;
					flag = false;

				}
			}
		}break;

		case 3: {
			bool flag = true;
			int groupNumber;
			if (database[ID].groupNumber == 1) {
				
				for (int i = database[ID].groupID; i <= firstGroup; i++) {
					
					if(database[i].groupNumber==1) database[i].groupID--;
				}
				firstGroup--;
			}
			else {
				if (database[ID].groupNumber == 2) {
					
					for (int i = database[ID].groupID; i <= secondGroup; i++) {

						if (database[i].groupNumber == 2) database[i].groupID--;
					}
					secondGroup--;
				}
				else if (database[ID].groupNumber == 3) {
					
					for (int i = database[ID].groupID; i <= thirdGroup; i++) {

						if (database[i].groupNumber == 3) database[i].groupID--;
					}
					thirdGroup--;
				}
			}

			while (flag) {
				cout << "\n � ����� ������ ������� ��������? (1, 2 ��� 3)\n\n��� �����: ";
				cin >> groupNumber;

				if (groupNumber != 1 and groupNumber != 2 and groupNumber != 3) {

					loh();

				}

				else {
					switch (groupNumber) {

						case (!isdigit): {
							loh();
						}break;

						case 1:
						{
							if (firstGroup > groupLimit) {
								cout << "\n\n��� ������ ��� ������� :(  \n\n";
							}

							else {

								firstGroup += 1;

								database[ID].groupNumber = 1;

								database[ID].groupID = firstGroup;
								cout << "\n����� �������� � ������ --> \n" << database[ID].groupID;
								flag = false;

							}
						}break;

						case 2:
						{
							if (secondGroup > groupLimit) {
								cout << "\n\n��� ������ ��� ������� :(  \n\n";
							}

							else {

								secondGroup += 1;

								database[ID].groupNumber = 2;

								database[ID].groupID = secondGroup;
								cout << "\n����� �������� � ������ --> \n" << database[ID].groupID;
								flag = false;

							}
						}break;

						case 3:
						{
							if (thirdGroup > groupLimit) {
								cout << "\n\n��� ������ ��� ������� :( \n\n";
							}

							else {

								thirdGroup += 1;

								database[ID].groupNumber = 3;

								database[ID].groupID = thirdGroup;
								cout << "\n����� �������� � ������ --> \n" << database[ID].groupID;
								flag = false;

							}
						}break;



					}
				}

			}break;


		}break;

		case 4: {
			float count = 0;
			int grade;
			cout << "\n������� ������ �������� �� �������� � ������(����� ������) \n";
			for (int i = 0; i < 8; i++) {

				cin >> grade;

				while (grade > 5 or grade < 2) {
					loh();
					cin >> grade;

				}

				if (grade > 0 and grade < 6) {
					database[ID].grade[i] = grade;
					count += database[ID].grade[i];
				}
			}

			database[ID].score = count / 8;
			cout << "\n\n������� ���� �������� ����� " << database[ID].score << "\n\n";
		}break;

		case 5: {
			bool moneyFlag = true;
			int money;
			cout << "\n\n������� �������� ��������: ";
			cin >> money;
			while (database[ID].money != money) {
				if (moneyFlag != isdigit(money)) {
					database[ID].money = money;
				}
				else {
					loh();
					cin >> money;
				}
			}
		}
	}

	
	
}

void showAllStudent() {
	for (int i = 0; i < studentsCounter; i++) {
		SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
		cout << i + 1;
		SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
		cout<< ".  " << database[i].FIO;
		cout << "\nID: " << database[i].ID;
		cout << "\n���: " << database[i].sex;
		cout << "\n������: " << database[i].groupNumber;
		cout << "\n����� � ������: " << database[i].groupID;
		cout << "\n" << database[i].success;
		
		cout << "\n������: \n";
		for (int j = 0; j < 7; j++) {
			cout << database[i].grade[j] << ", ";
		}
		cout << database[i].grade[7];
		cout<< "\n������� ����: " << database[i].score ;
		cout << "\n�������� :" << database[i].money<< "\n\n";
	}
}

void showGroupmates(int num) {
	for (int i = 0; i < studentsCounter; i++) {
		if (database[i].groupNumber == num) {
				
			    SetConsoleTextAttribute(handle, FOREGROUND_BLUE); 
				cout << "\n" << i + 1;
				SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
				cout<< ".  " << database[i].FIO;
				cout << "\nID: " << database[i].ID;
				cout << "\n���: " << database[i].sex;
				cout << "\n������: " << database[i].groupNumber;
				cout << "\n����� � ������: " << database[i].groupID;

				cout << "\n������: \n";
				for (int j = 0; j < 8; j++) {
					cout << database[i].grade[j] << ", ";
				}
			
		}
	}
}

void topStudent(){
	
	Student top[3];
	float goldScore= 0;
	float silverScore = 0;
	float bronzeScore = 0; 
	Student goldStudent;
	Student silverStudent;
	Student bronzeStudent;

	for (int i = 0; i < studentsCounter; i++) {
		
		if (database[i].score>goldScore) {

			bronzeStudent = silverStudent;
			bronzeScore = silverScore;
			silverStudent = goldStudent;
			silverScore = goldScore;
			goldStudent = database[i];
			goldScore = database[i].score;
			continue;
		}

		if (database[i].score == goldScore) {

			bronzeStudent = silverStudent;
			bronzeScore = silverScore;
			silverStudent = database[i];
			silverScore = database[i].score;
			continue;
		}

		if (database[i].score > silverScore) {

			bronzeStudent = silverStudent;
			bronzeScore = silverScore;
			silverStudent = database[i];
			silverScore = database[i].score;
			
			continue;
		}

		if (database[i].score == silverScore) {

			bronzeStudent = silverStudent;
			bronzeScore = silverScore;
			silverStudent = database[i];
			silverScore = database[i].score;

			continue;
		}
		if (database[i].score > bronzeScore) {

			bronzeStudent = database[i];
			bronzeScore = database[i].score;

			continue;
		}

	}

	// ������
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
	cout << "1.  ";
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN); 
	cout<< goldStudent.FIO;
	cout << "\nID: " << goldStudent.ID;
	cout << "\n���: " << goldStudent.sex;
	cout << "\n������: " << goldStudent.groupNumber;
	cout << "\n����� � ������: " << goldStudent.groupID;

	cout << "\n������: \n";
	
	for (int j = 0; j < 8; j++) {
		cout  << goldStudent.grade[j] << ", ";
	}
	cout << "\n������� ����: " << goldStudent.score << "\n";

	//������
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
	cout << "2.  ";
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	cout<< silverStudent.FIO;
	cout << "\nID: " << silverStudent.ID;
	cout << "\n���: " << silverStudent.sex;
	cout << "\n������: " << silverStudent.groupNumber;
	cout << "\n����� � ������: " << silverStudent.groupID;

	cout << "\n������: \n";
	for (int j = 0; j < 8; j++) {
		cout  << silverStudent.grade[j] << ", ";
	}
	cout << "\n������� ����: " << silverStudent.score << "\n";

	//�����
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
	cout << "3.  ";
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	cout<<bronzeStudent.FIO;
	cout << "\nID: " << bronzeStudent.ID;
	cout << "\n���: " << bronzeStudent.sex;
	cout << "\n������: " << bronzeStudent.groupNumber;
	cout << "\n����� � ������: " << bronzeStudent.groupID;

	cout << "\n������: \n";
	for (int j = 0; j < 8; j++) {
		cout  << bronzeStudent.grade[j] << ", ";
	}
	cout << "\n������� ����: " << bronzeStudent.score << "\n";
}

void sexSplitUp() {

	int woman = 0;
	int man = 0;
	int undefinite = 0;
	for (int i = 0; i < studentsCounter; i++) {
		if (database[i].sex == '�') {
			undefinite++;
			continue;
		}
		if (database[i].sex == '�') {
			woman++;
			continue;
		}
		else
			man++;
	}

	cout << "\n���������� ������� � ������������:" << woman << "\n���������� ������ � ������������:" << man << "\n���������� ���������������� � ������������:" << undefinite;
}

void scholarship() {
	cout << "\n\n���������:";
	for (int i = 0; i < studentsCounter; i++) {
		
		if (database[i].success == "��������") {

			cout <<"\n"<< i + 1 << ".  " << database[i].FIO;
			cout << "\nID: " << database[i].ID;
			cout << "\n���: " << database[i].sex;
			cout << "\n������: " << database[i].groupNumber;
			cout << "\n����� � ������: " << database[i].groupID;
			cout << "\n" << database[i].success;

			cout << "\n������: \n";
			for (int j = 0; j < 8; j++) {
				cout << database[i].grade[j] << ", ";
			}
			cout << "\n������� ����: " << database[i].score << "\n\n";
		}
	}
	
	cout << "\n\n���������:";
	for (int i = 0; i < studentsCounter; i++) {
		
		if (database[i].success == "��������") {

			cout << "\n" << i + 1 << ".  " << database[i].FIO;
			cout << "\nID: " << database[i].ID;
			cout << "\n���: " << database[i].sex;
			cout << "\n������: " << database[i].groupNumber;
			cout << "\n����� � ������: " << database[i].groupID;


			cout << "\n������: \n";
			for (int j = 0; j < 8; j++) {
				cout << database[i].grade[j] << ", ";
			}
			cout << "\n������� ����: " << database[i].score << "\n\n";
		}
	}
	
	cout << "\n\n�� �������� ���������:";
	for (int i = 0; i < studentsCounter; i++) {
		
		if (database[i].success == "��������") {

			cout << "\n" << i + 1 << ".  " << database[i].FIO;
			cout << "\nID: " << database[i].ID;
			cout << "\n���: " << database[i].sex;
			cout << "\n������: " << database[i].groupNumber;
			cout << "\n����� � ������: " << database[i].groupID;

			cout << "\n������: \n";
			for (int j = 0; j < 8; j++) {
				cout << database[i].grade[j] << ", ";
			}
			cout << "\n������� ����: " << database[i].score << "\n\n";
		}
	}
}

void groupIDCheck(int k) {
	
	cout << "\n\n��������, ������� ������ � ����� "<< k << ":";
	for (int i = 0; i < studentsCounter; i++) {
		
		if (database[i].groupID == k) {

			SetConsoleTextAttribute(handle, FOREGROUND_BLUE );
			cout << "\n" << i + 1;
			SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
			cout<< ".  " << database[i].FIO;
			cout << "\nID: " << database[i].ID;
			cout << "\n���: " << database[i].sex;
			cout << "\n������: " << database[i].groupNumber;
			cout << "\n����� � ������: " << database[i].groupID;
			cout << "\n" << database[i].success;

			cout << "\n������: \n";
			for (int j = 0; j < 8; j++) {
				cout << database[i].grade[j] << ", ";
			}
			cout << "\n������� ����: " << database[i].score << "\n\n";
		}
	}
}

void studentsHouse() {
	cocktailSort();
	cout << "\n\n������� �� ������:\n\n";
	showAllStudent();
	
}

int main() {
	setlocale(0,"");
	system("chcp 1251");


	ofstream fout;
	ifstream fin;
	int fileChoose;
	char c;
	string filePath="leti.txt";
	bool openFile = true;
	cout << "������� ������� �����!\n\n";
	
	cout << sizeof(Student);
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		cout << "� ��� ��� ���� ���� � �������� ���������?\n1 - ��\n2 - ���\n\n��� �����: ";
		SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
		cin >> fileChoose;

		switch (fileChoose) {
			case (!isdigit): {
				loh();
			}break;

			case 1: {



				while (openFile) {

					SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
					cout << "\n\n������� ������ ���� � �����: ";
					SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
					cin >> filePath;
					fin.open(filePath);

					if (!fin.is_open()) {
						SetConsoleTextAttribute(handle,  FOREGROUND_RED );
						
						cout << "\n\n������ �������� �����!!!";
						SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
					}

					else {
						clearStream();
						openFile = false;
						SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
						
						cout << "\n\n���� ������!";
						SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

						while (!fin.eof()) {


							getline(fin, database[studentsCounter].FIO);
							fin >> database[studentsCounter].sex;
							fin >> database[studentsCounter].groupNumber;
							for (int i = 0; i < 8; i++) {
								fin >> database[studentsCounter].grade[i];
							}
							fin >> database[studentsCounter].money;

							studentsCounter++;

							database[studentsCounter].ID = studentsCounter;
							
							fin.get(c);


						}
						fin.close();
						
						// ���������� ������ � ������
						
						for (int i = 0; i < studentsCounter; i++) {
							if (database[i].groupNumber == 1) {
								firstGroup += 1;

								database[i].groupID = firstGroup;
							}

							else {
								if (database[i].groupNumber == 2) {
									secondGroup += 1;

									database[i].groupID = secondGroup;
								}
								else
									if (database[i].groupNumber == 3) {
										thirdGroup += 1;

										database[i].groupID = thirdGroup;

									}
							}
						}

						
						//srednyi ball
						int grade;
						for (int i = 0; i < studentsCounter; i++) {

							bool successflag = true, withoutScholarship = true;
							float count = 0;

							
							for (int j = 0; j < 8; j++) {
								grade = database[i].grade[j];
								count += database[i].grade[j];

								if (grade < 5) successflag = false;
								if (grade < 4) withoutScholarship = false;

							}
							
							database[i].score =count / 8;

							if (successflag == true) {
								database[i].success = "��������";
							}

							if (successflag == false and withoutScholarship == true) {
								database[i].success = "��������";
							}

							if (successflag == false and withoutScholarship == false) {
								database[i].success = "��������";
							}

						}

						
					}
				}
				break;
			}

			case 2: {
				cout << "\n\n����� �� �������� ���� :)\n";
			}break;

		}


		int choose = 0;

		while (choose != -1) {
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
			cout << "\n\n�������� �������� �� ���� ���� � ������� ��������������� �����:\n"\
				"1. �������� ������ �������� � ����.\n"\
				"2. �������� ������ ��������.\n"\
				"3. ������� ������ ���� ���������.\n"\
				"4. ������� ������ ��������� �� ����� ������, ������� �� ��������� ����.\n"\
				"5. ������� ��� 3 ����� �������� ���������.\n"\
				"6. ���������� ��������� ������� ����.\n"\
				"7. ������, ��� ������ �� �������, ��� ������, � ��� �� �������� ���������.\n"\
				"8. ������� ���� ��������� � ���������� ������� � ������, ������� �� �������� ����.\n"\
				"9. ��� �� ��-���� ����� � ������????\n"\
				"10. Exit\n";
			SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

			cout << "\n��� �����: ";
			cin >> choose;

			switch (choose) {
				case (!isdigit): {

					loh();

				}break;

				case 10: {

					cout << "\n\n���a-���a! :";
					SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					cout << "_";
					SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED );
					cout<<"(\n\n";
					SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
					choose = -1;

				}break;

				case 1: {		
					if (studentsCounter + 1 > universitySize) {
						cout << "\n\n� ������������ ������ ��� ��������� ���� :(";
					}
					else {

						fout.open(filePath, ofstream::app);
						if (!fout.is_open()) {
							SetConsoleTextAttribute(handle, FOREGROUND_RED );
							
							cout << "\n\n������ �������� �����!!!";
							SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
							exit(0);
						}
						else {
							if (studentsCounter == 0) {
								database[studentsCounter] = database[0].newStudent();
								fout << database[studentsCounter].FIO << '\n';
								fout << database[studentsCounter].sex << '\n';
					 			fout << database[studentsCounter].groupNumber << '\n';
								for (int i = 0; i < 7; i++) {
									fout << database[studentsCounter].grade[i] << " ";
								}
								fout << database[studentsCounter].grade[7];
								fout<< '\n'<< database[studentsCounter].money ;
							}
							else {
								database[studentsCounter] = database[0].newStudent();
								fout << '\n' << database[studentsCounter].FIO << '\n';
								fout << database[studentsCounter].sex << '\n';
								fout << database[studentsCounter].groupNumber << '\n';
								for (int i = 0; i < 7; i++) {
									fout << database[studentsCounter].grade[i] << " ";
								}
								fout << database[studentsCounter].grade[7];
								fout << '\n'<< database[studentsCounter].money ;
							}
						}
						fout.close();

						SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
						cout << "\n������ �������!\n";
						SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN); 
					}

				} break;

				case 2: {
					int ID;
					showAllStudent();
					bool errorFlag = true;
					while (errorFlag != false) {
					cout << "\n\n�������� ��������, ������ �������� �� ������ �������� � ������� ��� ID.\n��� �����: ";
						cin >> ID;
						if (ID<0 or ID>studentsCounter - 1){
							loh();
						}
						else {
							changeStudent(ID);
							errorFlag = false;
						}
						
					}
					

					fout.open(filePath);
					if (!fout.is_open()) {
						SetConsoleTextAttribute(handle, FOREGROUND_RED );
						cout << "\n\n������ �������� �����!!!";
						SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
						exit(0);
					}
					else {
						fout << database[0].FIO << '\n';
						fout << database[0].sex << '\n';
						fout << database[0].groupNumber << '\n';
						for (int j = 0; j < 7; j++) {
							fout << database[0].grade[j] << " ";
						}
						fout << database[0].grade[7];
						fout << '\n' << database[studentsCounter].money;

						for (int i = 1; i < studentsCounter; i++) {
							fout<< "\n" << database[i].FIO << '\n';
							fout << database[i].sex << '\n';
							fout << database[i].groupNumber << '\n';
							for (int j = 0; j < 7; j++) {
								fout << database[i].grade[j] << " ";
							}
							fout << database[i].grade[7];
							fout << '\n' << database[studentsCounter].money;
						}
						
					}

					fout.close();
					
				}break;

				case 3: {

					showAllStudent();

				}break;

				case 4: {
					int groupChoose;

					cout << "\n\n������� ������: ";
					cin >> groupChoose;
					switch (groupChoose) {
					case (!isdigit): {
						loh();
					}break;

					case 1: {
						showGroupmates(1);
					}break;

					case 2: {
						showGroupmates(2);
					} break;


					case 3: {
						showGroupmates(3);
					} break;

					}

				}break;

				case 5: {
					topStudent();
				}break;

				case 6: {
					sexSplitUp();
				}break;

				case 7: {
					scholarship();
				}break;

				case 8: {
					int numChoose;
					cout << "\n\n������� ����� � ������: ";
					cin >> numChoose;
					if (numChoose > 30 or numChoose < 1) {
						loh();
						cout << "� ������ �� ������ 30 �������";
					}

					else {
						groupIDCheck(numChoose);
					}
				}break;

				case 9: {
					studentsHouse();
				}
			}
		}
		
return 0;
}


	
