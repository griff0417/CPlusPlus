#ifndef BOOKSTORE_H
#define BOOKSTORE_H

const int CAPACITY = 30;

class BookStore
{
	public:

		// Constructor to set the number of books to zero
		BookStore();

		// A function to add a book to the list
		// If the array is full, return false, else add the book to the list and return true
		// If the book is already in the list, then replace it with aBook 
		bool addBook(Book aBook);

		// A function to delete a book from the list
		// if the array is empty, or the book is not in the array return false, else remove  
		// the book from the list and return true
		bool deleteBook(Book  aBook);

		// A function that returns a Book from the list
		// The input parameter aBook may hold only part or all of the information about 
		// the book, but must have the book isbn number( to be able to 
		// compare it  with a book in the list)
		// The function returns true if aBook was in the list, else it returns false
		bool retrieveBook(Book & aBook);

		// a function that returns the total cost that the bookStore invested in books
		double totalInvestment();
		
		// Print the bookStore
		// For each book print the book ISBN number, book author, book title and cost,
		// overload the << operator a function to print all the books in the bookStore in 
		// ascending order by cost of  the book.  
		// For each book print the book ISBN number, book author, book title and cost,  
		friend ostream& operator << (ostream& out, BookStore book);

	private:

		int count; 				 	// Actual number of books in store
		Book list[CAPACITY];  		// Array of books
		void sort();  				// A method to sort the books in the 
};
#endif
