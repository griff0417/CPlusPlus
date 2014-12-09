#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"
#include "BookStore.h"

using namespace std;


// Used for parsing strings.
// each string feild is set with
// meaningful string information
struct MenuData
{
	string a;
	string b;
	string c;
	string d;
	string e;
};


/*
* @precondition
* Must have elements on string line
* @postcondition
* Will take the menuCall input line and
* parse it into several strings to be evaluated.
* preforms operation called for in line and uses
* remaining items on line to preform that operation
*/
void menuCall(MenuData&, string, BookStore&, ostream&);

/*
* @precondition
* File must exist
* @postcondition
* Items on line are taken and parsed into Book objs
* once completed with line the book is added to store obj
*/
void createBookstoreFromFile(string, BookStore&);

/*
* @precondition
* Must be sent a string and a struct
* @postcondition
* Parses from string in menuCall()
* adds parsed strings to different string feilds
* in struct MenuData
*/
void parseLine(string, MenuData&);

int main()
{
	// Fundamentals to making a bookstore (A bookstore for books!!!) 
	BookStore store;
	MenuData menuData;

	// Input and output
	ofstream out;
	out.open("output.txt");

	// Create a book store from text file
	menuCall(menuData, "1,input.txt", store, out);
	out << store;
	out << "\n";
	// Add a book
	menuCall(menuData, "2,66778,Daniel Liang,Intro to Java,150", store, out);
	out << store;

	// Delete a book
	menuCall(menuData, "3,23456", store, out);
	out << store;

	// Print a book's info
	menuCall(menuData, "4,34567", store, out);

	// Update a book
	menuCall(menuData, "5,45678,250", store, out);
	menuCall(menuData, "8,45678", store, out);

	// Print all book store data
	menuCall(menuData, "6", store, out);

	// Exit
	menuCall(menuData, "7", store, out);

	out.close();
}

/*
* @precondition
* File must exist
* @postcondition
* Items on line are taken and parsed into Book objs
* once completed with line the book is added to store obj
*/
// Parse data from a text file and create a bookstore based
// on the information
void createBookstoreFromFile(string file, BookStore& store)
{
	ifstream inStream;
	inStream.open(file);
	int count;
	string line;
	string construction;

	while (!inStream.eof())
	{
		Book book;

		line = "";
		construction = "";
		count = 0;
		getline(inStream, line);

		int lineSize = line.length();

		for (int x = 0; x < lineSize; x++)
		{
			if (line[x] == ' ' || isalpha(line[x]) || isdigit(line[x]) || line[x] == '.')
				construction += line[x];
			else if (line[x] == ',')
			{
				switch (count)
				{
					case 0:
						book.setISBN(stoi(construction));
						break;

					case 1:
						book.setAuthor(construction);
						break;

					case 2:
						book.setTitle(construction);
						break;
				}

				construction = "";

				// This count var is to know which meaningful part of the string has been parsed and constructed
				count++;
			}
			else
				continue;
		}

		book.setCost(stod(construction));

		store.addBook(book);
	}

	inStream.close();
}

/*
* @precondition
* Must be sent a string and a struct
* @postcondition
* Parses from string in menuCall()
* adds parsed strings to different string feilds
* in struct MenuData
*/
// Parse a given string into a string array
void parseLine(string line, MenuData& menuData)
{
	int count;
	string construction;

	construction = "";
	count = 0;

	int lineSize = line.length();

	for (int x = 0; x < lineSize; x++)
	{
		if (line[x] == ' ' || isalpha(line[x]) || isdigit(line[x]) || line[x] == '.')
			construction += line[x];
		else if (line[x] == ',')
		{
			switch (count)
			{
				case 0:
					menuData.a = construction;
					break;

				case 1:
					menuData.b = construction;
					break;

				case 2:
					menuData.c = construction;
					break;

				case 3:
					menuData.d = construction;
					break;
			}

			construction = "";

			// This count var is to know which meaningful part of the string has been parsed and constructed
			count++;
		}
		else
			continue;
	}

	if (lineSize > 1)
		menuData.e = construction;
	else
		menuData.a = construction;
}
/*
* @precondition
* Must have elements on string line
* @postcondition
* Will take the menuCall input line and
* parse it into several strings to be evaluated.
* preforms operation called for in line and uses
* remaining items on line to preform that operation
*/
void menuCall(MenuData& menuData, string line, BookStore& store, ostream& out)
{
	parseLine(line, menuData);

	Book book;

	switch (stoi(menuData.a))
	{
		case 1:
			out << "------------------------ - \n";
			out << "Create the DataBase\n";
			out << "------------------------ - \n";
			out << endl;

			createBookstoreFromFile(menuData.e, store);

			out << "\n\n";
			break;

		case 2:
			out << "------------\n";
			out << "Add a book: "<< line <<"\n";
			out << "------------\n";
			out << endl;

			book.setISBN(stoi(menuData.b));
			book.setAuthor(menuData.c);
			book.setTitle(menuData.d);
			book.setCost(stod(menuData.e));

			store.addBook(book);

			out << "\n\n";
			break;

		case 3:
			out << "-------------- - \n";
			out << "Delete a book: " << line <<"\n";
			out << "-------------- - \n";
			out << endl;

			book.setISBN(stoi(menuData.e));

			store.deleteBook(book);

			out << "\n\n";
			break;

		case 4:
			out << "------------------------------ - \n";
			out << "Retrieve a book and print it: " << line<<"\n";
			out << "------------------------------ - \n";
			out << endl;

			book.setISBN(stoi(menuData.e));
			if (!store.retrieveBook(book))
				out << "Book not found";

			else
				out << book;

			out << "\n\n";
			break;

		case 5:
			out << "------------------------\n";
			out << "Update a book's cost : " << line <<"\n";
			out << "------------------------\n";
			out << endl;

			book.setISBN(stoi(menuData.b));
			book.setCost(stod(menuData.e));
			
			if (!store.addBook(book))
				out << "Book not found";
			out << "\n\n";
			break;

		case 6:
			out << "---------------------- - \n";
			out << "Print the DataBase in ascending order \n ";
			out << "---------------------- - \n";
			out << endl;

			out << store;
			out << "Total Investment: " << store.totalInvestment();

			out << "\n\n";
			break;

		case 7:
			out << "---------------------- - \n";
			out << "Exit \n ";
			out << "---------------------- - \n";
			out << endl;

			out << "\n\n";

			exit(0);
			break;

		case 8:

			book.setISBN(stoi(menuData.e));
			if (!store.retrieveBook(book))
				out << "Book not found";

			else
				out << book;

			out << "\n\n";
			break;
	}
}