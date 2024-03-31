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
		cout << "Ошибка ввода. Пожалуйста, повторите попытку." << endl;
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


		cout << "\n\nВведите фамилию студента: ";
		clearStream();
		getline(cin, vvod);

		cout << "\nВведите имя студента: ";
		getline(cin, memory);
		vvod = vvod + " " + memory;

		cout << "\nВведите отчество студента: ";
		getline(cin, memory);
		vvod = vvod + " " + memory;


		student.FIO = vvod;

		char sex;
		bool flag = true;
		while (flag) {
			cout << "\nВведите пол студента:\n1.Mужчина - М \n2.Женщина -  Ж\n3.Другое - Д\n\nВаш выбор: ";
			cin >> sex;
			if (sex != 'М' and sex != 'Ж' and sex != 'Д') {
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
			cout << "\nВ какую группу студент зачислен? (1, 2 или 3)\n\nВаш выбор: ";
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
						cout << "\n\nЭта группа уже набрана :(  \n\n";
					}

					else {

						firstGroup += 1;

						student.groupNumber = 1;

						student.groupID = firstGroup;
						cout << "\nНомер студента в группе --> " << student.groupID;
						flag = false;

					}
				}break;

				case 2:
				{
					if (secondGroup >= groupLimit) {
						cout << "\n\nЭта группа уже набрана :(  \n\n";
					}

					else {

						secondGroup += 1;

						student.groupNumber = 2;

						student.groupID = secondGroup;
						cout << "\nНомер студента в группе --> " << student.groupID;
						flag = false;

					}
				}break;

				case 3:
				{
					if (thirdGroup >= groupLimit) {
						cout << "\n\nЭта группа уже набрана :( \n\n";
					}

					else {

						thirdGroup += 1;

						student.groupNumber = 3;

						student.groupID = thirdGroup;
						cout << "\nНомер студента в группе --> " << student.groupID;
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
			cout << "\nВведите оценки студента за экзамены и зачеты(через пробел) \n";
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
		cout << "\n\nСредний балл студента равен " << student.score << "\n\n";

		if (successflag == true) {
			student.success = "Отличник";
		}

		if (successflag == false and withoutScholarship == true) {
			student.success = "Хорошист";
		}

		if (successflag == false and withoutScholarship == false) {
			student.success = "Троечник";
		}

		bool moneyFlag = true;
		int money;
		cout << "\n\nВведите достаток студента: ";
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

		// Проход слева направо
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

		// Проход справа налево
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
	cout << "\n\nВыберите данные, которые вы хотите поменять: \n1.ФИО \n2.Пол \n3. Номер группы \n4. Оценки\n5. Достаток\n\nВаш выбор: ";
	cin >> changeChoose;
	switch (changeChoose){

		case (!isdigit): {
			loh();
		}break;

		case 1: {
			string vvod = "";
			string memory = "";


			cout << "\n\nВведите фамилию студента: ";
			clearStream();
			getline(cin, vvod);

			cout << "\nВведите имя студента: ";
			getline(cin, memory);
			vvod = vvod + " " + memory;

			cout << "\nВведите отчество студента: ";
			getline(cin, memory);
			vvod = vvod + " " + memory;


			database[ID].FIO = vvod;
		} break;

		case 2: {
			char sex;
			bool flag = true;
			while (flag) {
				cout << "\nВведите пол студента:\n1.Mужчина - М \n2.Женщина -  Ж\n3.Другое - Д\n\nВаш выбор: ";
				cin >> sex;
				if (sex != 'М' and sex != 'Ж' and sex != 'Д') {
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
				cout << "\n В какую группу студент зачислен? (1, 2 или 3)\n\nВаш выбор: ";
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
								cout << "\n\nЭта группа уже набрана :(  \n\n";
							}

							else {

								firstGroup += 1;

								database[ID].groupNumber = 1;

								database[ID].groupID = firstGroup;
								cout << "\nНомер студента в группе --> \n" << database[ID].groupID;
								flag = false;

							}
						}break;

						case 2:
						{
							if (secondGroup > groupLimit) {
								cout << "\n\nЭта группа уже набрана :(  \n\n";
							}

							else {

								secondGroup += 1;

								database[ID].groupNumber = 2;

								database[ID].groupID = secondGroup;
								cout << "\nНомер студента в группе --> \n" << database[ID].groupID;
								flag = false;

							}
						}break;

						case 3:
						{
							if (thirdGroup > groupLimit) {
								cout << "\n\nЭта группа уже набрана :( \n\n";
							}

							else {

								thirdGroup += 1;

								database[ID].groupNumber = 3;

								database[ID].groupID = thirdGroup;
								cout << "\nНомер студента в группе --> \n" << database[ID].groupID;
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
			cout << "\nВведите оценки студента за экзамены и зачеты(через пробел) \n";
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
			cout << "\n\nСредний балл студента равен " << database[ID].score << "\n\n";
		}break;

		case 5: {
			bool moneyFlag = true;
			int money;
			cout << "\n\nВведите достаток студента: ";
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
		cout << "\nПол: " << database[i].sex;
		cout << "\nГруппа: " << database[i].groupNumber;
		cout << "\nНомер в группе: " << database[i].groupID;
		cout << "\n" << database[i].success;
		
		cout << "\nОценки: \n";
		for (int j = 0; j < 7; j++) {
			cout << database[i].grade[j] << ", ";
		}
		cout << database[i].grade[7];
		cout<< "\nСредний балл: " << database[i].score ;
		cout << "\nДостаток :" << database[i].money<< "\n\n";
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
				cout << "\nПол: " << database[i].sex;
				cout << "\nГруппа: " << database[i].groupNumber;
				cout << "\nНомер в группе: " << database[i].groupID;

				cout << "\nОценки: \n";
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

	// лучший
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
	cout << "1.  ";
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN); 
	cout<< goldStudent.FIO;
	cout << "\nID: " << goldStudent.ID;
	cout << "\nПол: " << goldStudent.sex;
	cout << "\nГруппа: " << goldStudent.groupNumber;
	cout << "\nНомер в списке: " << goldStudent.groupID;

	cout << "\nОценки: \n";
	
	for (int j = 0; j < 8; j++) {
		cout  << goldStudent.grade[j] << ", ";
	}
	cout << "\nСредний балл: " << goldStudent.score << "\n";

	//средни
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
	cout << "2.  ";
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	cout<< silverStudent.FIO;
	cout << "\nID: " << silverStudent.ID;
	cout << "\nПол: " << silverStudent.sex;
	cout << "\nГруппа: " << silverStudent.groupNumber;
	cout << "\nНомер в списке: " << silverStudent.groupID;

	cout << "\nОценки: \n";
	for (int j = 0; j < 8; j++) {
		cout  << silverStudent.grade[j] << ", ";
	}
	cout << "\nСредний балл: " << silverStudent.score << "\n";

	//глупи
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
	cout << "3.  ";
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	cout<<bronzeStudent.FIO;
	cout << "\nID: " << bronzeStudent.ID;
	cout << "\nПол: " << bronzeStudent.sex;
	cout << "\nГруппа: " << bronzeStudent.groupNumber;
	cout << "\nНомер в списке: " << bronzeStudent.groupID;

	cout << "\nОценки: \n";
	for (int j = 0; j < 8; j++) {
		cout  << bronzeStudent.grade[j] << ", ";
	}
	cout << "\nСредний балл: " << bronzeStudent.score << "\n";
}

void sexSplitUp() {

	int woman = 0;
	int man = 0;
	int undefinite = 0;
	for (int i = 0; i < studentsCounter; i++) {
		if (database[i].sex == 'Д') {
			undefinite++;
			continue;
		}
		if (database[i].sex == 'Ж') {
			woman++;
			continue;
		}
		else
			man++;
	}

	cout << "\nКоличество девушек в университете:" << woman << "\nКоличество парней в университете:" << man << "\nКоличество неопределившихся в университете:" << undefinite;
}

void scholarship() {
	cout << "\n\nОтличники:";
	for (int i = 0; i < studentsCounter; i++) {
		
		if (database[i].success == "Отличник") {

			cout <<"\n"<< i + 1 << ".  " << database[i].FIO;
			cout << "\nID: " << database[i].ID;
			cout << "\nПол: " << database[i].sex;
			cout << "\nГруппа: " << database[i].groupNumber;
			cout << "\nНомер в группе: " << database[i].groupID;
			cout << "\n" << database[i].success;

			cout << "\nОценки: \n";
			for (int j = 0; j < 8; j++) {
				cout << database[i].grade[j] << ", ";
			}
			cout << "\nСредний балл: " << database[i].score << "\n\n";
		}
	}
	
	cout << "\n\nХорошисты:";
	for (int i = 0; i < studentsCounter; i++) {
		
		if (database[i].success == "Хорошист") {

			cout << "\n" << i + 1 << ".  " << database[i].FIO;
			cout << "\nID: " << database[i].ID;
			cout << "\nПол: " << database[i].sex;
			cout << "\nГруппа: " << database[i].groupNumber;
			cout << "\nНомер в группе: " << database[i].groupID;


			cout << "\nОценки: \n";
			for (int j = 0; j < 8; j++) {
				cout << database[i].grade[j] << ", ";
			}
			cout << "\nСредний балл: " << database[i].score << "\n\n";
		}
	}
	
	cout << "\n\nНе получают стипендию:";
	for (int i = 0; i < studentsCounter; i++) {
		
		if (database[i].success == "Троечник") {

			cout << "\n" << i + 1 << ".  " << database[i].FIO;
			cout << "\nID: " << database[i].ID;
			cout << "\nПол: " << database[i].sex;
			cout << "\nГруппа: " << database[i].groupNumber;
			cout << "\nНомер в группе: " << database[i].groupID;

			cout << "\nОценки: \n";
			for (int j = 0; j < 8; j++) {
				cout << database[i].grade[j] << ", ";
			}
			cout << "\nСредний балл: " << database[i].score << "\n\n";
		}
	}
}

void groupIDCheck(int k) {
	
	cout << "\n\nСтуденты, Которые пойдут к доске "<< k << ":";
	for (int i = 0; i < studentsCounter; i++) {
		
		if (database[i].groupID == k) {

			SetConsoleTextAttribute(handle, FOREGROUND_BLUE );
			cout << "\n" << i + 1;
			SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
			cout<< ".  " << database[i].FIO;
			cout << "\nID: " << database[i].ID;
			cout << "\nПол: " << database[i].sex;
			cout << "\nГруппа: " << database[i].groupNumber;
			cout << "\nНомер в группе: " << database[i].groupID;
			cout << "\n" << database[i].success;

			cout << "\nОценки: \n";
			for (int j = 0; j < 8; j++) {
				cout << database[i].grade[j] << ", ";
			}
			cout << "\nСредний балл: " << database[i].score << "\n\n";
		}
	}
}

void studentsHouse() {
	cocktailSort();
	cout << "\n\nОчередь на общагу:\n\n";
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
	cout << "Доброго времени суток!\n\n";
	
	cout << sizeof(Student);
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		cout << "У вас уже есть файл с записями студентов?\n1 - Да\n2 - Нет\n\nВаш выбор: ";
		SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
		cin >> fileChoose;

		switch (fileChoose) {
			case (!isdigit): {
				loh();
			}break;

			case 1: {



				while (openFile) {

					SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
					cout << "\n\nВведите полный путь к файлу: ";
					SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
					cin >> filePath;
					fin.open(filePath);

					if (!fin.is_open()) {
						SetConsoleTextAttribute(handle,  FOREGROUND_RED );
						
						cout << "\n\nОшибка открытия файла!!!";
						SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
					}

					else {
						clearStream();
						openFile = false;
						SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
						
						cout << "\n\nФайл открыт!";
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
						
						// присвоение номера в списке
						
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
								database[i].success = "Отличник";
							}

							if (successflag == false and withoutScholarship == true) {
								database[i].success = "Хорошист";
							}

							if (successflag == false and withoutScholarship == false) {
								database[i].success = "Троечник";
							}

						}

						
					}
				}
				break;
			}

			case 2: {
				cout << "\n\nТогда мы создадим свой :)\n";
			}break;

		}


		int choose = 0;

		while (choose != -1) {
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
			cout << "\n\nВыберите действие из меню ниже и введите соответствующую цифру:\n"\
				"1. Добавить нового студента в базу.\n"\
				"2. Изменить данные студента.\n"\
				"3. Вывести данные всех студентов.\n"\
				"4. Вывести данные студентов из одной группы, которую вы выыберете сами.\n"\
				"5. Вывести топ 3 самых успешных студентов.\n"\
				"6. Подсчитать студентов разного пола.\n"\
				"7. Узнать, кто учится на отлично, кто хорошо, а кто не получает стипендию.\n"\
				"8. Вывести всех студентов с одинаковым номером в группе, который вы выберете сами.\n"\
				"9. Кто же всё-таки попал в общагу????\n"\
				"10. Exit\n";
			SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

			cout << "\nВаш выбор: ";
			cin >> choose;

			switch (choose) {
				case (!isdigit): {

					loh();

				}break;

				case 10: {

					cout << "\n\nПокa-покa! :";
					SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					cout << "_";
					SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED );
					cout<<"(\n\n";
					SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
					choose = -1;

				}break;

				case 1: {		
					if (studentsCounter + 1 > universitySize) {
						cout << "\n\nВ университете больше нет бюджетных мест :(";
					}
					else {

						fout.open(filePath, ofstream::app);
						if (!fout.is_open()) {
							SetConsoleTextAttribute(handle, FOREGROUND_RED );
							
							cout << "\n\nОшибка открытия файла!!!";
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
						cout << "\nЗапись создана!\n";
						SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN); 
					}

				} break;

				case 2: {
					int ID;
					showAllStudent();
					bool errorFlag = true;
					while (errorFlag != false) {
					cout << "\n\nВыберите студента, данные которого вы хотите поменять и введите его ID.\nВаш выбор: ";
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
						cout << "\n\nОшибка открытия файла!!!";
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

					cout << "\n\nВведите группу: ";
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
					cout << "\n\nВведите номер в списке: ";
					cin >> numChoose;
					if (numChoose > 30 or numChoose < 1) {
						loh();
						cout << "В группе не больше 30 человек";
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


	
