/**
	CS 231 Project 2
	util.cpp
	Purpose: Implementation of several useful "utility functions" for the "Sea Battle!" game.
	
	@author <Earl Moss>
	@version 1.0
*/

#include "util.h"
#include "grid.h"

using namespace std;

/**
    Generates and returns a pseudorandom number

    @param max The upper bound of the pseudorandom number
    @return A pseudorandom number n in the range 0 <= n < max
*/
int randint(int max) {

	return ( rand() % max );

} // End randint()

/**
    Reads from standard input until an integer character is found
    (Copied from sample code provided in "Errors, Part 2" lecture notes)
    
*/
void skip_to_int() {
	
	if ( cin.fail() ) {                       				/* We found something that isn't an integer */
   
		cin.clear();                          				/* We'd like to look at the characters */
		char ch;
      
		while ( cin >> ch ) {                 				/* Throw away non-digit characters */
      
			if ( isdigit(ch) || ch == '-' ) { 				/* We found a digit or a '-' */
         	
				cin.unget();                  				/* Put the digit back so it can be read */
				return;
            
			} // end if()
         
		} // end while()
      
	} // end if()
   
	throw runtime_error("No input!");         				/* eof() or bad(): give up */
   
} // end skip_to_int()

/**
    Read and return an integer from standard input
    (Copied from sample code provided in "Errors, Part 2" lecture notes)

    @return An integer value read from standard input
*/
int get_int() {

	int n = 0;
	
	while (true) {											/* Keep reading until an int is available */
		
		if ( cin >> n )										/* Is this an int? */
			return n;										/* If so, read and return it */
			
		skip_to_int();										/* If not, keep scanning cin until an int is found */
		
	} // end while()
	
} // end get_int()

/**
    Read and validate a pair of coordinates (row and column) from the user, and return as a Cell.
	(If invalid values for the column and/or row are provided, the user is repeatedly prompted until
	valid values are provided.)

	@param max The maximum allowed value of the column and row; corresponds to the size of the grid
    @return An integer value read from standard input
*/
Cell get_cell(int max) {
	
	char c;													/* char portion of new cell */
	int n;													/* row portion of new cell */
	Cell new_cell;

	while (true) {

		cin >> c;											/* Read column (a char) and uppercase it */
		c = toupper(c);

		n = get_int();										/* Read row (an int) */

		if ( 1 <= n && n <= max ) {							/* Check if row is in range */

			if ( 'A' <= c && c < ('A' + max) ) {	    	/* Check if column is in range */

				new_cell.col = c;							/* If in range, convert column letter to column index */
				new_cell.row = n;							/* If in range, convert row number to row index */

				return new_cell;							/* Return coordinates as Cell */

			} // end if (col)

		} // end if (row)

		cout << "Please Try Again: ";						/* If not in range, print error and repeat */

	} // end while()

} // end get_cell()
