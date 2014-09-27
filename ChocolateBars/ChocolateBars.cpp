/*
 * ChocolateBars.cpp
 *
 * Created on: Sep 26, 2014
 * Author: Ryan Hochmuth and Jason Griffith
 *
 * This program takes an input amount of dollars
 * and determines how many chocolates you can get
 * and how many coupons you'll have remaining.  You
 * get a coupon for every chocolate.  A set amount of
 * coupons will get you a free chocolate.
 */

#include <iostream>

using namespace std;

// How many coupons get you a free chocolate
const int COUPONS_PER_CHOCOLATE = 7;

int main()
{
	// Determines if the program loop is running
	bool running = true;

	// Keeps track of total chocolate
	// over all iterations
	int totalChocolate = 0;
	// Keeps track of total iterations
	int count = 0;

	// The amount of coupons you have
	int coupons = 0;
	// The amount of chocolate you have
	int chocolate = 0;

	// The main iteration loop
	while(running == true)
	{
		// Output the greeting message
		cout << "Enter the number of dollars you have. (ex. 20): ";

		// The amount of chocolate you get is equal to
		// the amount of money input
		cin >> chocolate;

		if (chocolate < 0)
		{
			if (count == 0)
				count = 1;

			running = false;
			continue;
		}

		// You get 1 coupon per chocolate
		coupons = chocolate;

		while(coupons >= 7)
		{
			// Update how much chocolate you have from coupons
			chocolate += coupons / COUPONS_PER_CHOCOLATE;
			// Update how many coupons you gain from free chocolate
			coupons = (coupons % COUPONS_PER_CHOCOLATE) + (coupons / COUPONS_PER_CHOCOLATE);
		}

		// Output the number of chocolate and coupons
		// for this iteration
		cout << "\nChocolate: ";
		cout << chocolate;
		cout << "\nCoupons Remaining: ";
		cout << coupons;
		cout << "\n\n";

		// Increment how many iterations this
		// program has gone through
		count++;
		// Add the chocolate to the total chocolate
		totalChocolate += chocolate;
	}

	// Output the total chocolate and average chocolate
	// over all iterations
	cout << "\n\nTotal Chocolate: ";
	cout << totalChocolate;
	cout << "\nAverage Chocolate: ";
	cout << totalChocolate / count ;
	cout << "\n";
	system("PAUSE");
	return 0;
}
