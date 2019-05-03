// Name: Timothy Nkata
// Summary: This code is meant display cinema seatings.
// The most difficult aspect is working out the updating of prices and purchasing a ticket.
// It took about 6 hours to write the code
// 04/25/2019 Rev. A
// 05/02/2019 Rev. B added comments and organized the code
/*
1.  View Available Seats
2.  View Seating Prices
3.  Update seating Prices
4.  Purchase a ticket
5.  View Ticket Sales
6.  QUIT
Enter Your Choice
1

				Seats
		123456789012345678901234567890
Row:1   ##############################
Row:2   ##############################
Row:3   ##############################
Row:4   ##############################
Row:5   ##############################
Row:6   ##############################
Row:7   ##############################
Row:8   ##############################
Row:9   ##############################
Row:10  ##############################
Row:11  ##############################
Row:12  ##############################
Row:13  ##############################
Row:14  ##############################
Row:15  ##############################
# = Available Seat(s)
* = Taken Seat(s)
1.  View Available Seats
2.  View Seating Prices
3.  Update seating Prices
4.  Purchase a ticket
5.  View Ticket Sales
6.  QUIT
Enter Your Choice
2
Row 1   23
Row 2   23
Row 3   24
Row 4   24
Row 5   24
Row 6   25
Row 7   25
Row 8   25
Row 9   25
Row 10  25
Row 11  24
Row 12  24
Row 13  24
Row 14  23
Row 15  23
1.  View Available Seats
2.  View Seating Prices
3.  Update seating Prices
4.  Purchase a ticket
5.  View Ticket Sales
6.  QUIT
Enter Your Choice
6
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
ofstream outputfile; // Set Up an output file globally.
ifstream inputfile; // Set up an input file globally.
const int ROW = 15; const int COLS = 30; // Set up Row and columns globally.
char seatChart[ROW][COLS];
double seePrices[ROW] = { 23, 23, 24, 24, 24, 25, 25, 25, 25, 25, 24, 24, 24, 23, 23 };
double totalSales;
int ticketSold = 0;
const char TAKENSEAT = '*';
const char AVAILABLESEAT = '#';
void displayMenu(); // This dispalys the 
int getChoice();
void displaySeats(char[][COLS]);
void displayPrices(double *);
void updatePrices(double *);
void displaySales(double);
void purchaseTicket(char[][COLS], double*, double&);

int main()
{

	
	for (int i = 0; i < ROW; i++) // This for loop sets up the global seating chart varible.
	{
		for (int z = 0; z < COLS; z++)
		{
			seatChart[i][z] = AVAILABLESEAT; // available Seat is equal to the pound key or "#".
		}
	}
	int user;
	
	do { // Sets up a do while loop to limit the users choices.
		displayMenu();
		user = getChoice();
	} while (user != 6);
	
	

	system("pause");
	return 0;
}
void displayMenu() // This function sets up the display Menu.
{
	cout << "1.  View Available Seats\n";
	cout << "2.  View Seating Prices\n";
	cout << "3.  Update seating Prices\n";
	cout << "4.  Purchase a ticket\n";
	cout << "5.  View Ticket Sales\n";
	cout << "6.  QUIT\n";
}



int getChoice() // The function sets up to get the users choice and passes it down to the following
// functions.
{
	int choice;
	cout << "Enter Your Choice" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1: displaySeats(seatChart); // passes seat chart as a parameter in the function
		break;
	case 2: displayPrices(seePrices); // passes see prices as a parameter in the function
		break;
	case 3: updatePrices(seePrices); // passes see prices as a parameter in the function
		break;
	case 4: purchaseTicket(seatChart, seePrices, totalSales); // passes in 3 parameters
		break;
	case 5: displaySales(totalSales); // passes total sales as a parameter in the function
		break;
	case 6: exit(0); // Exit choice
		break;
	default: cout << "You did not enter the correct choice!\n";
	}
	return choice;
} // Ends the Get Choice Function

void displaySeats(char seatChart[][COLS]) // This function has two parameters.
{
	
		cout << "\n\t\tSeats\n";
		cout << "\t123456789012345678901234567890\n";
		for (int i = 0; i < ROW; i++)
		{
			cout << "Row:" << i + 1 << "\t";
			for (int z = 0; z < COLS; z++)
			{
				cout << seatChart[i][z]; // This loop displays the seat Chart
			}
			cout << endl;
		}
		cout << AVAILABLESEAT << " = Available Seat(s)\n"; // These two lines are the legend.
		cout << TAKENSEAT << " = Taken Seat(s)\n";
	
} // Ends Display Seats Function.

void displayPrices(double *seePrices) //This function is made to display the prices
{
		for (int i = 0; i < ROW; i++)
		{
			cout << "Row " << i + 1 << "\t";
			cout << *(seePrices + i) << endl; // Changed from array to a pointer. 
		}
}
void updatePrices(double *seePrices)// This function is made to update Prices 
{
	double var; // This variable is for the user to enter.
	outputfile.open("theaterPrices.txt");
	cout << "What is the price for each row?" << endl;
	for (int i = 0; i < ROW; i++)
	{
		cout << "Enter row price " << i + 1 << ":";
		cin >> var; // User enter into the file
		outputfile << var << endl;
	}
	outputfile.close();
	inputfile.open("theaterPrices.txt");
	for (int i = 0; i < ROW; i++)
	{
		inputfile >> *(seePrices + i); //The file is pulled and put into the program.
	}
	inputfile.close();
}// Ends the Update Prices Function.

void displaySales(double totalSales) 
{
	cout << " This is how many tickets were sold: ";
	cout << ticketSold << endl; // Displays the tickets Sold
	cout << "This is how much you made: \n"; // This is an extra step.
	cout << totalSales << endl; // This displays how mcuh money was made the movie business
	// From the tickets.

} // Ends Display Sales Function

void purchaseTicket(char seatChart[][COLS], double *seePrices, double &totalSales)
{
	char userChoice; // Sets up the character for the user's choice.
	int userRow; 
	int userCol;
	cout << "You have selected to purchase a ticket\n";
	cout << " Here are the prices:\n";
	cout << "Here is the Seat Chart: \n";
	displaySeats(seatChart); // Calls the displaySears function within this function to save time
	// and space.
	do { // do while loop set up to allow the user to enter in if they want to buy
		// more than once.
		cout << "Which Row would you like to buy?\n";
		cin >> userRow;
		while (userRow < 1 || userRow >15) // While loop set up to limit userRow choice.
		{
			cout << "Please only enter from 1 to 15\n";
			cout << " Which Row would you like to buy?\n";
			cin >> userRow;
		}
		cout << " Which Column would you like to buy?\n";
		cin >> userCol;
		while (userCol < 1 || userCol >30) // While loop set up to limit userCol choice.
		{
			cout << "Please only enter from 1 to 30\n";
			cout << " Which Column would you like to buy?\n";
			cin >> userCol;
		}
		if (seatChart[userRow - 1][userCol - 1] == TAKENSEAT) // This if statement is made to show what
			// happens if the seat has been taken.
		{
			cout << "This seat has been taken\n";
			purchaseTicket(seatChart, seePrices, totalSales);
		}
		else if (seatChart[userRow - 1][userCol - 1] != TAKENSEAT) // This is made to show what happens
			// if the seat is available
		{
			seatChart[userRow - 1][userCol - 1] = TAKENSEAT;
			ticketSold++;
			totalSales+= *(seePrices + userRow - 1 );
			cout << "Do you want to run the program again?" << endl;
			cout << "Enter Y to run again. If you don't then the program will end" << endl;
			cin >> userChoice; // allows user to decide whether they want to run it again.
		}
		
	} while (userChoice == 'Y'); // If the user wants to run it again they type in uppercase y.
} // Ends Purchase Ticket Function
