#include<iostream>
#include<string>
using namespace std;
void percentage_cal(int computer_marks[], int math_marks[], int percentage_array[], string grades_array[]) 
{
	int percentage = 0;
	for (int i = 0; i < 5; i++) {
		percentage = static_cast<int>((static_cast<double>(computer_marks[i] + math_marks[i]) / 200) * 100);
		percentage_array[i] = percentage;
		if (percentage_array[i] >= 90 && percentage_array[i] <= 100) {
			grades_array[i] = "A";
		}
		else if (percentage_array[i] >= 75 && percentage_array[i] <= 90) {
			grades_array[i] = "B";
		}
		else if (percentage_array[i] >= 60 && percentage_array[i] < 75) {
			grades_array[i] = "C";
		}
		else if (percentage_array[i] >= 50 && percentage_array[i] < 60) {
			grades_array[i] = "D";
		}
		else {
			grades_array[i] = "F";
		}
	}
}



int main()
{
	int student_roll_no[5] = { 0 }, math_marks[5] = { 0 }, computer_marks[5] = { 0 };
	int percentage_array[5] = { 0 };
	int roll_no = 0, maths = 0, computer = 0;
	string choice, advance_oper_choice;
	int choice1;
	string grades_array[5];
	int percentage = 0;
	bool flag = false;
	cout << "=====================================" << endl;
	cout << " Welcome to ADMIN PANEL " << endl;
	cout << "=====================================" << endl;
	cout << endl << endl;
	string grade;
	cout << " Enter Roll number and their data to enroll student " << endl;
	while (flag == false)
	{
		for (int i = 0;i < 5;i++)
		{
			bool flag1 = false;
			cout << endl;
			cout << " Enter the roll no of student " << i + 1 << ":";
			cin >> roll_no;
			student_roll_no[i] = roll_no;
			cout << "Enter marks of computer science of stuednt " << i + 1 << ":";
			cin >> computer;
			computer_marks[i] = computer;
			cout << " Enter marks of Maths of student " << i + 1 << ":";
			cin >> maths;
			math_marks[i] = maths;
			cout << endl;
			cout << " Enter Y/y to continue adding student and their data  and N/n to stop : ";
			cin >> choice;
			if (choice == "N" || choice == "n")
			{
				flag1 = true;
				break;
			}
		}
		// percentage calclutation

		

		percentage_cal(computer_marks, math_marks, percentage_array, grades_array);
		// percentage cal ended 

		// Displaying info....
		cout << "=============================================" << endl;
		cout << " Do you want to perform any of the following operation ?" << endl;
		cout << " Press Y/y for YES " << endl;
		cout << " Press N/n for NO " << endl;
		cout << " Enter your choice ";
		cin >> advance_oper_choice;
		if (advance_oper_choice == "N" || advance_oper_choice == "n")
		{
			for (int i = 0;i < 5;i++)
			{
				cout << endl;
				cout << " Roll number of student " << i + 1 << " is : " << student_roll_no[i] << endl;
				cout << " Marks of Computer Science of student " << i + 1 << " is : " << computer_marks[i] << endl;
				cout << " Marks of Maths of student " << i + 1 << " is " << math_marks[i] << endl;
				cout << " Percentage of student " << i + 1 << " is : " << percentage_array[i] << endl;

				cout << "Grade of Student " << i + 1 << " is : " << grades_array[i] << endl;
				cout << endl;

			}


		}






		else if (advance_oper_choice == "Y" || advance_oper_choice == "y")
		{
			cout << endl;
			cout << " Press 1 to update Roll Number of a particular Student" << endl;
			cout << " Press 2 to update marks of a particular student for CS." << endl;
			cout << " Press 3 to update marks of CS for all students who are already enrolled " << endl;
			cout << " Press 4 to update marks for Mathematics." << endl;
			cout << " Press 5 to update marks of Mathematics for all students who are already enrolled " << endl;
			cout << " Press6 to sort the data on the basis of generated percentages. " << endl;
			cout << " Press 7 to delete the record of a particular student. " << endl;
			cout << endl;
			cout << "   Enter your choice : ";
			cin >> choice1;


			if (choice1 == 1)
			{
				int stu = 0;
				cout << " Enter student number whose roll no to be updated ";
				cin >> roll_no;
				cout << " Enter roll number to update ";
				cin >> stu;
				student_roll_no[roll_no - 1] = stu;

			}
			else if (choice1 == 2)
			{

				cout << " Enter student roll number whose computer science marks to be updates ";
				cin >> roll_no;
				cout << " Enter marks of computer science ";
				cin >> computer;
				computer_marks[roll_no - 1] = computer;

			}
			else if (choice1 == 3)
			{
				for (int i = 0;i < 5;i++)
				{
					cout << " Enter computer science of student " << i + 1 << ":";
					cin >> computer;
					computer_marks[i] = computer;
				}
			}
			else if (choice1 == 4)
			{

				cout << " Enter student roll number whose computer science marks to be updates ";
				cin >> roll_no;
				cout << " Enter marks of maths ";
				cin >> maths;
				computer_marks[roll_no - 1] = maths;
			}
			else if (choice1 == 5)
			{
				for (int i = 0;i < 5;i++)
				{
					cout << " Enter marks of student " << i + 1 << ":";
					cin >> maths;
					math_marks[i] = maths;
				}
			}
			else if (choice1 == 6)
			{
				//6.	Press6 to sort the data on the basis of generated
				//percentages. The data must be sorted in ascending order. 
				//Also make sure that all the record should be sorted
				//on the basis on percentage.
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5 - i - 1; j++)
					{
						if (percentage_array[j] > percentage_array[j + 1])
						{
							// Swap the elements
							swap(percentage_array[j], percentage_array[j + 1]);

							// Swap corresponding roll numbers, computer marks, and math marks
							swap(student_roll_no[j], student_roll_no[j + 1]);
							swap(computer_marks[j], computer_marks[j + 1]);
							swap(math_marks[j], math_marks[j + 1]);
						}
					}
				}
				// Display the sorted data
				cout << "Sorted Data based on Percentage:" << endl;
				for (int i = 0; i < 5; i++)
				{
					cout << "Roll No: " << student_roll_no[i] << ", Percentage: " << percentage_array[i] << ", Maths marks : " << math_marks[i] << " ,Computer marks " << computer_marks[i] << endl;
				}
			}
			else if (choice1 == 7)
			{
				cout << " Enter roll no of student you want to delete data ";
				cin >> roll_no;
				student_roll_no[roll_no - 1] = 0;
				computer_marks[roll_no - 1] = 0;
				math_marks[roll_no - 1] = 0;
				percentage_array[roll_no - 1] = 0;

			}




		}
		// Again calcluate percentage and assgin grages..
		
		percentage_cal(computer_marks, math_marks, percentage_array, grades_array);
		// percent cal ended..


		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Student Name           Maths Marks       Computer Science Marks     Percentage       Grade " << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		for (int i = 0;i < 5;i++)
		{
			cout << student_roll_no[i] << "                        " << math_marks[i] << "                        " << computer_marks[i] << "                        " << percentage_array[i] << "             " << grades_array[i] << endl;
		}
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

		flag = true;
		break;

	}
	cout << endl << endl;
	cout << "=======================================================================================================================" << endl;
	cout << " ********       PROGRAM END       ********  " << endl;
	cout << "=======================================================================================================================" << endl;
}