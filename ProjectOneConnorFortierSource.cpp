//Connor Fortier
//Project One
//CS 210
//1/24/2021

#include <iostream>;										//input and output stream
#include <windows.h>;										//used for sleep function
using namespace std;										//standard naming conventions

//all clock values inizilized to start clock at 12:00:00 A M or 00:00:00
//just like a new digital clock would come out of the box from a factory
//values will need to be adjusted by user according to desired time zone

//declare and initialize global variables

int clock12Hour = 12;										//hour variable for Clock12
int clock12Minute = 00;										//minute variable for Clock12
int clock12Second = 00;										//second variable for Clock12
int clock24Hour = 00;										//hour variable for Clock24
int clock24Minute = 00;										//minute variable for Clock24
int clock24Second = 00;										//second variable for Clock24

bool isPM = false;											//boolean value for AM or PM

//functions used to reduce size of main

void displayClocks() {													//function to display clocks
	//first line of output for clocks(27 *'s)
	cout << "***************************" << "        ";
	cout << "***************************" << endl;

	//second line of output for clock display
	cout << "*      " << "12-Hour Clock" << "      *" << "        ";
	cout << "*      " << "24-Hour Clock" << "      *" << endl;

	//third line of output for Clock12
	cout << "*      ";
	if (clock12Hour < 10) {												//adds 0 for formatting
		cout << '0';
	}
	cout << clock12Hour << ':';
	if (clock12Minute < 10) {											//adds 0 for formatting
		cout << '0';
	}
	cout << clock12Minute << ':';
	if (clock12Second < 10) {											//adds 0 for formatting
		cout << '0';
	}
	cout << clock12Second << " ";
	if (isPM == false) {												//check for A M condition
		cout << "A M" << "       *" << "        ";
	}
	if (isPM == true) {													//check for A M condition
		cout << "P M" << "       *" << "        ";
	}

	//third line of output for Clock24
	cout << "*        ";
	if (clock24Hour < 10) {												//adds 0 for formatting
		cout << '0';
	}
	cout << clock24Hour << ':';
	if (clock24Minute < 10) {											//adds 0 for formatting
		cout << '0';
	}
	cout << clock24Minute << ':';
	if (clock24Second < 10) {											//adds 0 for formatting
		cout << '0';
	}
	cout << clock24Second << "         *" << endl;

	//fourth line of output for clock display
	cout << "***************************" << "        ";
	cout << "***************************" << endl << endl;
}

void displayMenu() {													//function to display menu prompt
	//first line of menu display(27 *'s)
	cout << endl << "***************************" << endl;

	//second and third lines of menu
	cout << "* 1 - Add One Hour" << "        *" << endl << endl;		//8 spaces and extra line

	//fourth and fifth lines of menu
	cout << "* 2 - Add One Minute" << "      *" << endl << endl;		//6 spaces and extra line

	//sixth and seventh lines of menu
	cout << "* 3 - Add One Second" << "      *" << endl << endl;		//6 spaces and extra line

	//eighth line of menu
	cout << "* 4 - Exit Program" << "        *" << endl;				//8 spaces

	//ninth line of menu
	cout << "***************************" << endl << endl;
}

void changeStatus() {													// function to interchage A M and P M
	//change isPM value to true to display "P M"
	if (isPM == false) {
		isPM = true;
	}
	//change isPM value to false to display "A M"
	else if (isPM == true) {
		isPM = false;
	}
}

int main() {															//main function to run program
	//declare and initialize local variables
	int buttonPress = 0;												//user button press selection
	int menuChoice = 0;													//user menu selection


	while (menuChoice != 4) {
		//display clear screen
		cout << "	" << endl;

		//call function to display time in multiple formats
		displayClocks();

		//from this line on my intentions were to put the rest of the while loop into two seperate functions
		//this did not work outside of main due to compilation errors from calling functions within a function

		//output to user if they would like to press a button
		cout << "Would you like to PRESS A BUTTON(1 = YES, 2 = NO)?" << endl;
		cout << "Yes to display menu, No to continue." << endl;
		
		//input from user for button press
		cin >> buttonPress;

		//check for bad user input
		if (buttonPress < 1 || buttonPress > 2) {
			cout << "Bad user input! Choices are 1 or 2." << endl;
		}

		//execute for choice of 1(YES)
		else if (buttonPress == 1) {
			//display menu to user
			displayMenu();

			//input from user for menu choice
			cout << "Please make a selection(4 to Quit)." << endl;
			cin >> menuChoice;

			//if logic for menu choice 1
			if (menuChoice == 1) {
				//add one hour to clocks
				clock12Hour += 1;
				//adjust A M or P M accordingly to the time of day
				if (clock12Hour == 12) {
					changeStatus();
				}
				clock24Hour += 1;
			}

			//else if logic for menu choice 2
			else if (menuChoice == 2) {
				//add one minute to clocks
				clock12Minute += 1;
				clock24Minute += 1;
			}

			//else if logic for menu choice 3
			else if (menuChoice == 3) {
				//add one second to clocks
				clock12Second += 1;
				clock24Second += 1;
			}

			//else if logic for menu choice 4
			else if (menuChoice == 4) {
				//return to exit with code 0
				return 0;
			}

			//check for bad input from user
			else if (menuChoice <= 0 || menuChoice >= 5) {
				cout << "Bad user input! Choices are 1 - 4.";
			}
		}

		//execute for choice of 2(NO)
		else if (buttonPress == 2) {
			//add one second
			clock12Second += 1;
			clock24Second += 1;

			//wait one second(1000 milliseconds), then continue
			Sleep(1000);
		}

		//validate limits of Clock12 values
		if (clock12Second > 59) {
			//clear current second value
			clock12Second = 00;
			//add one to clock12 minute value
			clock12Minute += 1;
		}
		if (clock12Minute > 59) {
			//clear current minute value
			clock12Minute = 00;
			//add one to clock12 hour value
			clock12Hour += 1;
			//adjust A M or P M accordingly to the time of day
			if (clock12Hour == 12) {
				changeStatus();
			}
		}
		if (clock12Hour > 12) {
			//correct "13 A M" to "1 P M"
			clock12Hour = 01;
		}

		//validate limits of Clock24 values
		if (clock24Second > 59) {
			//clear current second value
			clock24Second = 00;
			//add one to clock12 minute value
			clock24Minute += 1;
		}
		if (clock24Minute > 59) {
			//clear current minute value
			clock24Minute = 00;
			//add one to clock12 hour value
			clock24Hour += 1;
		}
		if (clock24Hour > 23) {
			//correct "24:00" to "00:00" for new day
			clock24Hour = 00;
		}
	}

	//return to exit main with code 0
	return 0;
}