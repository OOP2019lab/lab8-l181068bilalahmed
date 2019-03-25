#include <iostream>
#include <string>
using namespace std;

class Date {

	// Friend Functions

	friend ostream& operator << (ostream& op, const Date& temp){
		op << temp.monthNames[temp.month - 1] << " " << temp.date << ", " << temp.year << endl;
		return op;
	}

	friend istream& operator >> (istream& in, Date& temp){
		cout << "Enter date: ";
		in >> temp.date;
		cout << endl;
		cout << "Enter month: ";
		in >> temp.month;
		cout << endl;
		cout << "Enter year: ";
		in >> temp.year;
		return in;
	}


private:
	int date;
	int month;
	int year;
	static string monthNames[13];

public:

	//Constructors
	Date(){
		int date = 1;
		int month = 1;
		int year = 2000;
	}

	Date(int m, int d, int y){
		if (d > 0 && d < 13 && m > 0 && m < 31 && y > 999 && y < 10000){
			int date = d;
			int month = m;
			int year = y;
		}
		else{
			Date();
		}
	}

	~Date(){ //Destructor
		int date = -1;
		int month = -1;
		int year = -1;
	}


	//Operator Overloading

	bool operator == (const Date t2){
		if (this -> date == t2.date && this -> month == t2.month && this -> year == t2.year){ // compares the values of 2 objects and returns true if the are the same
			return true;
		}
	}

	Date operator + (int num){
		if ( this -> date < 31 && this -> date > 0){
			for (int i = 1; i < num; i++){ // Adds days until the required days are added
				this->date = this->date + 1;
				if ( this -> date > 30){ // if day is greater than 30, it sets day = 1 and month is incremented
					this -> date = 1;
					this->month = this-> month + 1;
				}
				if (this -> month > 12){ //if month is greater than 12, it sets month to 1, and increments year
					this -> month = 1;
					this -> year = this -> year +1;
				}
			}
		}
		return *this;
	}

	Date operator = (Date& temp){
		this -> date = date;
		this -> month = month;
		this -> year = year;
		return *this;
	}

	Date& operator -- (){
		if( this -> date != 0){ // date cannot be 0
			this ->date = this ->date - 1;
			return *this; // returns the new value of date
		}
	}

	Date& operator -- (int num){
		Date temp = *this;
		if( this -> date != 0){ // date cannot be 0
			this -> date = this -> date - 1;
			return temp; //returns previous value of date
		}
	}

	int operator [] (int index){
		if (index == 0 || index == 1 || index == 2){
			if (index == 0){
				return date;
			}
			if ( index == 1){
				return month;
			}
			if (index == 2){
				return year;
			}
		}
		else{
			cout << "Enter values between 0-2" << endl;
			return 0;
		}
	}

};

//Initializing of the static array

string Date ::  monthNames[13] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
