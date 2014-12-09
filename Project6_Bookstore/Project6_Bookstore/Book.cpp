#include <string>;
#include "Book.h"

using namespace std;

/*
* Initialize a new book.
*/
Book::Book()
{
	isbn = 0;
	author = "";
	title = "";
	cost = 0.0;
}

Book::Book(int isbn)
{
	this-> isbn = isbn;
	author = "";
	title = "";
	cost = 0.0;
}

Book::Book(int isbn, string author, string title, double cost)
{
	this->isbn = isbn;
	this->author = author;
	this->title = title;
	this->cost = cost;
}

ostream& operator << (ostream& out, Book book)
{
	out << book.getISBN() << ", "
		<< book.getAuthor() << ", "
		<< book.getTitle() << ", "
		<< book.getCost();

	return out;
}

void Book::setISBN(int isbn)
{
	this->isbn = isbn;
}

void Book::setAuthor(string author)
{
	this->author = author;
}

void Book::setTitle(string title)
{
	this->title = title;
}

void Book::setCost(double cost)
{
	this->cost = cost;
}

int Book::getISBN()
{
	return isbn;
}

string Book::getAuthor()
{
	return author;
}

string Book::getTitle()
{
	return title;
}

double Book::getCost()
{
	return cost;
}