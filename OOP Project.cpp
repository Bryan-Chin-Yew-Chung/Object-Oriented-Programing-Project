#include <iostream>
using namespace std;

 
class Main // Base Class Main
{
	private:

		float courtA = 9 , courtB = 15 , courtC = 22;
		string memberY = "Yes" , memberN = "No";
		string am = "am", pm = "pm";
		string goodBye;
			

	public:

		int people;
		char C , day , member , amPm;
		string name , dayOutput , amPmoutput , memberOutput;
		float time , courtPrice , hours , totalPrice , discountPrice;

		Main(): goodBye(){}
		friend string printGoodBye(Main);	// Declare Friend Function printGoodBye


		string setName()	// Function to get name
			{
				cout << "What is your name?" << endl;
				cin >> name;
				return name;
			}

		string membership() // Function to get membership status
			{
				cout << "Do you have membership? Y[1] N[2]" << endl;
				cin >> member;

				if (member == '1')
					{
						memberOutput = memberY;
						cout << "Membership entails a 30 percent discount !!" << endl << endl;
					}
				if (member == '2')
					{
						memberOutput = memberN;
						cout << "We do recomend signing up for our membership :(" << endl << endl;
					}
				else if (member != '1' && member != '2')	
					{
						cout << "Please enter a valid number :(" << endl;
						membership();
					}
				return memberOutput;				
			}		

		float setTime() // Function to get time
			{
				cout << "What time do you want to start the booking? (Hourly)" << endl;
				cin >> time;

				if(time <= 12.00 && time >= 1.00)
					{						
						return time;
					}

				else
					{
						cout << "Please enter a valid input :(" << endl;
						setTime();
					}
				return time;

			}

		string setamPm() // Function to get if am or pm
			{
				cout << "Am[1] or Pm[2] " << endl;
				cin >> amPm;

				if(amPm == '1')
					{
						amPmoutput = am;
					}
				if(amPm == '2')
					{
						amPmoutput = pm;
					}
				else if(amPm != '1' && amPm != '2')
					{
						cout << "Please enter a valid input :(" << endl;
						setamPm();
					}

				cout << "You have choosen a booking at " << time << amPmoutput << endl << endl;

				return amPmoutput;

			}

		float setPrice() // Function to get which court
			{
				cout << "Which court do you want to book ?" << endl;
				cin >> C;
				cout << "You have selected court " << C << endl;

				if(C == '1')
					{
						courtPrice = courtA;
					}
				if(C == '2')
					{
						courtPrice = courtB;
					}
				if(C == '3')
					{
						courtPrice = courtC;
					}
				else if (C != '1' && C != '2' && C != '3' )
					{
						cout << "Please enter a valid input :(" << endl << endl;
						setPrice();
					}

				cout << "Your price per hour is RM" << courtPrice << endl << endl;
				return courtPrice;
			}

		string setDay() // Function to get which day
			{
				cout << "What day would you like to book on?" << endl;
				cout << "Mon[1] Tues[2] Wed[3] Thurs[4] Fri[5] Sat[6] Sun[7]" << endl;
				cin >> day;


				if(day == '1')
					{
						dayOutput = "Monday";
					}
				if(day == '2')
					{
						dayOutput = "Tuesday";
					}
				if(day == '3')
					{
						dayOutput = "Wednesday";
					}
				if(day == '4')
					{
						dayOutput = "Thursday";
					}
				if(day == '5')
					{
						dayOutput = "Friday";
					}
				if(day == '6')
					{
						dayOutput = "Saturday";
					}
				if(day == '7')
					{
						dayOutput = "Sunday";
					}
				else if(day != '1' && day != '2' && day != '3' && day != '4' && day != '5' && day != '6' && day != '7') 
					{
						cout << "Please enter a valid number :(" << endl;
					}
		
				cout << "You have chosen " << dayOutput << endl << endl;
				return dayOutput;
			}

		float setHours() // Function to get what time
			{
				cout << "How many hours would you like to book for?" << endl;
				cin >> hours; 

				cout << "You have chosen to book " << hours << " hours." << endl << endl;
				return hours;
			}	

		int numberPeople() // Function to get amount of people
			{
				cout << "How many people will be attending ?" << endl;
				cin >> people;

				cout << "There will be " << people << " people attending." << endl << endl;
				return people;
			}


};

class Reciept : public Main // Derived Class Reciept mostly to print stuff
	{
		public:

			void displayName(string a) // Function to welcome user
				{
					cout << "Hello " << a << "!" << endl << endl;
				}

			void returnTop() // Function to print reciept
				{
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					cout << "~           RECEIPT            ~" << endl;
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

				}
			void Name(string a) // Function to print name 
				{
					cout << "Main Booker: " << a << endl;
				}

			void returnMember(string a) // Function to print membership status
				{
					cout << "Membership?: " <<  a << endl;
				}

			void returnCourt(char a) // Function to print court chosen
				{
					cout << "Court Chosen: Court " << a << endl;
				}

			void returnBooking(string a, float b , string c) // Function to print booking day and time
				{
					cout << "Start Of Booking: " << a << " , " << b  << c << endl;

				}
			
			void returnHours(int a) // Function to print hours booked
				{
					cout << "Booked Hours: " << a << endl;
				}

			void returnTotal(float a) // Function to print price before discount
				{
					cout << "Total: " << a << endl;
				}

	};

class Math : public Main // Derived class Math to calculate and display prices
	{
		public:

 			void multiply (float a, float b) // Function to calculate price * hours and print total price before discount
				{
					totalPrice = (a * b);
					cout << "Price: RM" << totalPrice << endl;
				} 

			void displayDiscount (float a)	// Function to calculate discount price if membership is detected
				{
					discountPrice = (a * 70) / 100;
					cout << "Discounted Price: RM" << discountPrice << endl;
				}
		

			
	};

class People : public Main	// Derived Class People to set people names
	{
		public:
			int i;
			string namePeople[40]; // Allocate array for the names

			string namesPeople(int a) // Array to take in names of attendees acording to the amount that the user inputs
				{
					cout << "Please enter names of attendees." << endl;
					
							for(i=0; i <= a; i++)	// Get input until i reaches the amount user stated
								{
									getline(cin , namePeople[i]);
								}
					return namePeople[i];

				}
			
	};

string printGoodBye(Main A) // Friend Function To Print Footer
	{
		A.goodBye = "Thanks For Booking DAYUM COURTZ, Enjoy Your Game.";
		return A.goodBye;
	}



void welcome() // Function For Welcome Text
	{
		cout << "-------------------------------------" << endl;
    	cout << "-----  Welcome to DAYUM COURTZ  -----" << endl;
    	cout << "-------------------------------------" << endl << endl;

		cout << "This is our automated booking service!" << endl;
	}

void booking() // Function For Booking Prices
	{
		cout << "We currently have 3 courts available for booking." << endl << endl;
		cout << "Courts and Prices" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Court A | RM  9 per hour [1]" << endl;
		cout << "Court B | RM 15 per hour [2]" << endl;
		cout << "Court C | RM 22 per hour [3]" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}
 


int main()
	{
		int i;
		Reciept setInput , output; 				// Create Objects for classes
		Math calc;
		People name;
		Main A;

		welcome();								// Call function to print welcome	
		setInput.setName();						// Call function to get name
		output.displayName(setInput.name);		// Call function to say hello
		setInput.membership();					// Call function to get membership status
		booking();								// Call function to print booking prices
		setInput.setPrice();					// Call function to get price depending on court chosen
		setInput.setDay();						// Call function to get day
		setInput.setTime();						// Call function to get time
		setInput.setamPm();						// Call function to get if am or pm
		setInput.setHours();					// Call function to get hours booked
							
		setInput.numberPeople();				// Call function to set amount of atendees
		name.namesPeople(setInput.people);		// Call function to set an array for names of people attending


		output.returnTop();																	// Call function to print RECIEPT
		output.Name(setInput.name);															// Call function to print name
		output.returnMember(setInput.memberOutput);											// Call function to print membership status
		output.returnCourt(setInput.C);														// Call function to print court chosen
		output.returnBooking(setInput.dayOutput , setInput.time , setInput.amPmoutput);		// Call function to print day and time
		output.returnHours(setInput.hours); 												// Call function to print hours booked


		calc.multiply(setInput.courtPrice , setInput.hours);			// Call function to get and display total price


		if(setInput.memberOutput == "Yes") 								// If else to test membership status for discount
		{
			calc.displayDiscount(calc.totalPrice);						// Call function to get and display discounted price
		}

		

		cout << endl << "People Attending:";

		for (int i = 0; i<= setInput.people; i++)						// Display Array Of Names Stored In Class
				{
					cout << name.namePeople[i] << endl;
				}

		output.returnTop();												// Call function to print RECIEPT

		cout << endl << endl << printGoodBye(A) << endl;				// Call function to print from friend class
}