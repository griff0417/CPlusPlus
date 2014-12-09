#include "Book.h"
#include "BookStore.h"

using namespace std;

// Constructor to set the number of books to zero
BookStore::BookStore()
{
	count = 0;
}

// A function to add a book to the list
// If the array is full, return false, else add the book to the list and return true
// If the book is already in the list, then replace it with aBook 
bool BookStore::addBook(Book aBook)
{
	Book tempBook = aBook;

	double cost = aBook.getCost();

	if (retrieveBook(tempBook)) // Search for the book
	{
		tempBook.setCost(cost); // Update the cost

		return true;
	}
	else
		if (tempBook.getAuthor() == "" || tempBook.getTitle() == "")
			return false;

	if (count < CAPACITY) // If the book can fit
	{
		list[count] = aBook; // Add the book
		count++;

		return true;
	}

	return false;
}

// A function to delete a book from the list
// if the array is empty, or the book is not in the array return false, else remove  
// the book from the list and return true
bool BookStore::deleteBook(Book aBook)
{
	if (count == 0) // If the list is empty
		return false;
	else
	{
		bool found = false;

		for (int x = 0; x < count; x++) // Search for the book and shift data if found
		{
			if (!found)
			{
				if (aBook.getISBN() == list[x].getISBN())
					found = true;
			}

			if (found) // When book is found, start shifting
			{
				list[x] = list[x + 1];
			}
		}

		list[count - 1] = NULL; // "Delete" book
		count--;

		return true;
	}
}

// A function that returns a Book from the list
// The input parameter aBook may hold only part or all of the information about 
// the book, but must have the book isbn number( to be able to 
// compare it  with a book in the list)
// The function returns true if aBook was in the list, else it returns false
bool BookStore::retrieveBook(Book& aBook)
{
	for (int x = 0; x < count; x++) 
	{
		if (aBook.getISBN() == list[x].getISBN())
		{
			aBook = list[x];
			return true;
		}	
	}

	return false;
}

// A function that returns the total cost that the bookStore invested in books
double BookStore::totalInvestment()
{	
	double total = 0;

	for (int x = 0; x < count; x++)
	{
		total = total + list[x].getCost();
	}

	return total;
}

// Print the bookStore
// For each book print the book ISBN number, book author, book title and cost,
// overload the << operator a function to print all the books in the bookStore in 
// ascending order by cost of  the book.  
// For each book print the book ISBN number, book author, book title and cost,
ostream& operator << (ostream& out, BookStore store)
{
	store.sort();

	for (int x = 0; x < store.count; x++)
	{
		out << store.list[x];
		out << "\n";
	}

	return out;
}

void BookStore::sort()
{
	Book bookShelf;//Holds book temporarily 
	for (int x = 0; x < count -1; x++)
	{
		bookShelf = list[x];

		for (int y = x+1; y < count ; y++)
		{
			if (bookShelf.getCost() > list[y].getCost())
			{
				list[x] = list[y];
				list[y] = bookShelf;
			}
		}
	}
}