#include<iostream>
#include<string>

/*this is file handeling operation it uses to
create files, write information to files,
and read information from files.*/
#include<fstream> 

using namespace std;

// Structure for view Bookshop details
struct {
	string Bookshop_Name;
	string Bookshop_Email_Address;
	string Bookshop_Address;
	string Bookshop_Contact_Number;
	string Bookshop_Branches;

} View_Bookshop_Details;


// Structure for book details
struct Book_Details {

	string Book_ID;
	string Book_Name;
	int Quantity = 0;
	float unitprice = 0;

};
// Array
Book_Details Books[10];

//void funtions
void Bookshop_Details();
void Registration();
void Login();
void Resert_Username_and_Password();
void Added_Books_List();
void Updated_Books_List();
void Update_Books();
void Add_Sales_Details();
void Logout();
void Exit();


int main() {


	int Choice_Number;

	//Menu
	cout << "\n\n\n\n\t\t\t			welcome to the Genius Bookshop's login page			\n\n\n";
	cout << "\t\t\t\t*********************   Genius Bookshop menu   *********************\n\n\n";
	cout << "\t\t\t ***	Press 1 to view Bookshop details			***" << endl;
	cout << "\t\t\t ***	Press 2 to Register to the Genius Bookshop	***" << endl;
	cout << "\t\t\t ***	Press 3 to Login to the Genius Bookshop		***" << endl;
	cout << "\t\t\t ***	Press 4 to find forgot password			***" << endl;
	cout << "\t\t\t ***	Press 5 to to manage sales details		***" << endl;
	cout << "\t\t\t ***	Press 6 to logout from the system		***" << endl;
	cout << "\t\t\t ***	Press 7 to Exit from the system	wothout logout	***" << endl;

	cout << "\n\n\t\t\tEnter your selection here : ";
	cin >> Choice_Number;
	cout << endl;

	//Switch case for choosing number to the list in the menu
	switch (Choice_Number)
	{
	case 1:
		Bookshop_Details();
		break;

	case 2:
		Registration();
		break;

	case 3:
		Login();
		break;

	case 4:
		Resert_Username_and_Password();
		break;

	case 5:
		Add_Sales_Details();
		break;

	case 6:
		Logout();
		break;

	case 7:
		Exit();
		break;

	default:

		system("Cls");
		cout << "\n\t\t\t\t\t Please choose from the available choices\n\n\n" << endl;
		main();

		Added_Books_List();

		Update_Books();

		Updated_Books_List();

	}

	system("pause");
	return 0;
}

//Display Bookshop deatils
void Bookshop_Details() {

	// system Cls = Clear the command line
	system("Cls");

	View_Bookshop_Details.Bookshop_Name = "\t\t\t\tGenius Bookshop";
	View_Bookshop_Details.Bookshop_Email_Address = "\t\t\t\tgeniusbookshop@gmail.com";
	View_Bookshop_Details.Bookshop_Address = "\t\t\t\t55/B, Galle road, Colombo 04";
	View_Bookshop_Details.Bookshop_Contact_Number = "\t\t\t\t0112345678 / 0761234567";
	View_Bookshop_Details.Bookshop_Branches = "\t\t\t\tColombo / Knady\n";

	cout << View_Bookshop_Details.Bookshop_Name << "\n";
	cout << View_Bookshop_Details.Bookshop_Email_Address << "\n";
	cout << View_Bookshop_Details.Bookshop_Address << "\n";
	cout << View_Bookshop_Details.Bookshop_Contact_Number << "\n";
	cout << View_Bookshop_Details.Bookshop_Branches << "\n";


	main();


}



/*Employee registration void function
with text file*/
void Registration() {

	string Reg_User_ID, Reg_User_Paaword, Reg_ID, Reg_Password;
	system("Cls");
	cout << "\t\t\t Enter the Usernsme : ";
	cin >> Reg_User_ID;
	cout << "\t\t\t Enter the password : ";
	cin >> Reg_User_Paaword;


	// ofstream helps to write inside the file
	//ios input output stream 
	//app : open the file and append the output
	ofstream S1("database.txt", ios::app);

	/*we want some space between the username and password
	that's why we use like this ' ' */
	S1 << Reg_User_ID << ' ' << Reg_User_Paaword << endl;
	system("Cls");
	cout << "\n\n\t\t\t\t\t You are registered to the Genius Bookshop! \n";
	main();

}



// employee login function
void Login() {

	char res = 'y';
	int count = 0;
	string User_ID, User_Password, Registered_ID, Registered_Password;
	system("Cls");

	cout << "\t\t\t\t Enter your registered username and password here :" << endl;
	cout << "\t\t\t\t User_Name     : ";
	cin >> User_ID;
	cout << "\t\t\t\t User_Password : ";
	cin >> User_Password;

	//Use ifstream for read the data from file
	ifstream S2("database.txt");

	//while loop
	while (S2 >> Registered_ID >> Registered_Password) {

		if (User_ID == Registered_ID && User_Password == Registered_Password) {

			count = 1;
			system("Cls");
		}
	}
	// Close file (if opened a file it is mandatory to close)
	S2.close();

	// If else statement
	if (count == 1) {


		cout << "\n\t\t\t\tWelcome\t" << User_ID << "\tYou have successfully logged in\n";
		cout << "\n\t\t\t\tThanks for loggin to the Genius Bookshop\n" << endl;
		cout << "\n\t\t\t\tDo you want to view added books? 'y' : ";
		cin >> res;

		// If else statement
		if (res == 'y')
		{
			Added_Books_List();
		}
		else {

			main();
		}



	}

	else {

		cout << "\n\n\t\t\t\t Invalid Login please double check your username and password\n";
		main();
	}

}

/*This is restart usernameand password function.
if an employee forgot his password he can fine hit password
from this function*/
void Resert_Username_and_Password() {

	int option = 0;
	system("Cls");
	cout << "\n\n\t\t\t\t\t you forgot your password? \n";
	cout << "\n\n\t\t\t\tPress 1 to search your password by username " << endl;
	cout << "\n\t\t\t\tPress 2 to go back to the main menu " << endl;
	cout << "\n\n\t\t\t\tEnter your option :";
	cin >> option;

	// Swith case
	switch (option)
	{// we use {} after the case because there will be multiple lines
	case 1: {

		int count = 0;
		string S_User_ID, System_ID, System_Password;
		cout << "\n\t\t\t\t Please type the username which you remembered :";
		cin >> S_User_ID;

		//ifstream use to read from the file or check from the file 
		ifstream S3("database.txt");
		while (S3 >> System_ID >> System_Password); {

			if (System_ID == S_User_ID) {

				count = 1;
			}
		}
		// Close file (if opened a file it is mandatory to close)
		S3.close();

		//If else statement
		if (count == 1) {

			cout << "\n\n\t\t\t\t We fount your account! \n";
			cout << "\n\t\t\t\t Your password is :" << System_Password;
			main();
		}
		else {

			cout << "\n\t\t\t Sorry we can't find your account!";
			main();
		}
		break;

	}

	case 2:

		main();

	default:
		cout << "\t\t\t\t Wrong choice, please make a different selection." << endl;
		Resert_Username_and_Password();

	}// end switch

}

/*In here we can see added book list and
we can add book list.*/
void Added_Books_List() {

	char res = 'y';

	/*these are added book list with
	using array and structure*/
	Books[0].Book_ID = "B0001";
	Books[0].Book_Name = "Adventure stories";
	Books[0].Quantity = 1;
	Books[0].unitprice = 250;

	Books[1].Book_ID = "B0002";
	Books[1].Book_Name = "Science fiction";
	Books[1].Quantity = 1;
	Books[1].unitprice = 220;

	Books[2].Book_ID = "B0003";
	Books[2].Book_Name = "Horror";
	Books[2].Quantity = 1;
	Books[2].unitprice = 150;

	Books[3].Book_ID = "B0004";
	Books[3].Book_Name = "Mystery";
	Books[3].Quantity = 1;
	Books[3].unitprice = 300;

	Books[4].Book_ID = "B0005";
	Books[4].Book_Name = "Fantasy";
	Books[4].Quantity = 1;
	Books[4].unitprice = 100;

	Books[5].Book_ID = "B0006";
	Books[5].Book_Name = "Novellas";
	Books[5].Quantity = 1;
	Books[5].unitprice = 100;

	/*This updated books list shows the added book list
	and if we add, that book list will also be shown*/
	Updated_Books_List();

	/*Need to add more book then press 'y'
	from here and add else press any key and it will
	go to main*/
	cout << "\nDo you want to add more books? 'y' : ";
	cin >> res;

	// if else statement
	if (res == 'y')
	{
		// for loop
		for (int i = 0; i < 1; i++)
		{

			cout << "Ender Book ID : ";
			cin >> Books[6].Book_ID;
			cout << "Ender Book Name : ";
			cin >> Books[6].Book_Name;
			cout << "Ender Book Quantity : ";
			cin >> Books[6].Quantity;
			cout << "Ender Book Unitprice : ";
			cin >> Books[6].unitprice;

			Updated_Books_List();

			cout << "\nDo you want to update books? 'y' : ";
			cin >> res;

			// If else statement
			if (res == 'y')
			{
				system("Cls");
				Update_Books();

			}
			else {

				main();
			}
		}


	}
	else {
		main();
	}

}

// Updated book list function
void Updated_Books_List() {


	system("cls");

	// for loop
	for (int i = 0; i < 7; i++)
	{
		int x = Books[i].Quantity;
		if (x != 0)
		{
			cout << " Book id :" << Books[i].Book_ID << endl;
			cout << " Book name :" << Books[i].Book_Name << endl;
			cout << " Book quantity :" << Books[i].Quantity << endl;
			cout << " Book unitprice :" << Books[i].unitprice << endl;
			cout << "\n";
		}

	}
	system("pause");


}

// update book function
void Update_Books()
{
	bool Book_ID_Found = true;
	char res = 'y';
	string Book_ID;
	cout << "Enter Product ID to updat product" << endl;
	cin >> Book_ID;

	// for loop
	for (int i = 0; i <= 7; i++)
	{
		// if statement
		if (Book_ID == Books[i].Book_ID)
		{
			cout << " Book ID :" << Books[i].Book_ID << endl;
			cout << " Book name :" << Books[i].Book_Name << endl;
			cout << " Book quantity :" << Books[i].Quantity << endl;
			cout << " Book unitprice :" << Books[i].unitprice << endl;
			cout << "\n";
			Book_ID_Found = true;

			cout << " Enter new values to update product :" << endl;
			cout << " Book ID :" << endl;
			cin >> Books[i].Book_ID;
			cout << " Book Name :" << endl;
			cin >> Books[i].Book_Name;
			cout << " Book Quantity :" << endl;
			cin >> Books[i].Quantity;
			cout << " Book Unit price :" << endl;
			cin >> Books[i].unitprice;
			system("pause");
			cout << " Display updated list :" << endl;

			Updated_Books_List();


			cout << "\n\n\t\t\tDo you want to go to menu?";

			// if else statement
			if (res == 'y')
			{
				main();
			}
			else {

				Logout();
			}

			break;
		}
	}

	// If statement
	if (Book_ID_Found == false)
	{
		cout << "Invalid ID" << endl;
		Update_Books();
	}
}

// Logout function
void Logout() {

	char Res = 'y';

	cout << "\t\t\tDo you want to logout from the system? 'y' : ";
	cin >> Res;

	//If else statement
	if (Res == 'y') {

		cout << "\n\n\t\t\t\tYour are logged out from the system\n";
		cout << "\n\t\t\t\t|||	Thank you	  |||\n\n" << endl;

		cout << "Do you want to exit? 'y'";
		cin >> Res;

		//If else statement
		if (Res == 'y')
		{
			cout << "\t\t\t\t You are exiting from the system\n" << endl;
			cout << "\t\t\t\t |||		Thank you		|||\n\n" << endl;
		}
		else {
			system("cls");
			cout << "\t\t\t\t\nWrong choice" << endl;
			main();
		}
	}
	else {
		system("Cls");
		cout << "\t\t\t\t\nWrong choice" << endl;
		main();
	}


}

// Add sales details fuction
void Add_Sales_Details() {

	system("Cls");

	string Book_ID;
	int Book_Quantity = 0;
	float Total = 0, Book_Price = 0, Discount_Amount = 0, One_book_discount = 0;
	char r = 'y';

	cout << "Add sales details\n\n" << endl;

	cout << "Is that book has any discount? 'yes' \n" << endl;
	

	// If else statement
	if (r == 'y')
	{

		cout << "Enter book id :" << endl;
		cin >> Book_ID;

		cout << "Enter book price :" << endl;
		cin >> Book_Price;

		cout << "Enter book quantity :" << endl;
		cin >> Book_Quantity;

		cout << "Enter total discount amount :" << endl;
		cin >> Discount_Amount;

		Total = Book_Price * Book_Quantity;
		cout << "Total amount is :" << Total << endl;

		One_book_discount = Discount_Amount / Book_Quantity;
		cout << "Discount for 1 book :" << One_book_discount << endl;

		Discount_Amount = Total - Discount_Amount;
		cout << "Total amount with discount is :" << Discount_Amount << endl;

		cout << "\n\nSales detail display below\n\n" << endl;

		cout << "Book id is :" << Book_ID << endl;
		cout << "Book price is :" << Book_Price << endl;
		cout << "Book quantity is :" << Book_Quantity << endl;
		cout << "Discount for 1 book :" << One_book_discount << endl;
		cout << "Total amount with discount is :" << Discount_Amount << endl;

	}
	else {

		cout << "Enter book id :" << endl;
		cin >> Book_ID;

		cout << "Enter book price :" << endl;
		cin >> Book_Price;

		cout << "Enter book quantity :" << endl;
		cin >> Book_Quantity;

		Total = Book_Price * Book_Quantity;
		cout << "Total amount is :" << Total << endl;

		cout << "\n\nSales detail display below\n\n" << endl;

		cout << "Book id is :" << Book_ID << endl;
		cout << "Book price is :" << Book_Price << endl;
		cout << "Book quantity is :" << Book_Quantity << endl;
		cout << "Total is :" << Total << endl;

	}

	cout << "\n\t\tDo you want to go to the manu? 'y'" << endl;
	cin >> r;

	// If else statement
	if (r == 'y')
	{
		main();
	}
	else {
		Logout();
	}
}

// Exit function
void Exit() {

	cout << "\t\t\t\t You are exiting from the system\n" << endl;
	cout << "\t\t\t\t |||		Thank you		|||\n\n" << endl;
}