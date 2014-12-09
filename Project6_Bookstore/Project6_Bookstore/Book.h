// HEADER FILE Book.h
//
//
// Class to keep track of a book in the store
// the class to set and get information about an book: the ISBN author, title, and cost  
#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;

class Book
{
	public:
		Book();
		Book(int);
		Book(int, string, string, double);

		void setISBN(int isbn);
		void setAuthor(string author);
		void setTitle(string title);
		void setCost(double cost);
		int getISBN();
		string getAuthor();
		string getTitle();
		double getCost();
		friend ostream& operator << (ostream& out, Book book);

	private:

		int isbn;
		string author;
		string title;
		double cost;
};
#endif 