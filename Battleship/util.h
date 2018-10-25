/**
	CS 231 Project 2
	util.h
	Purpose: Header for several useful "utility functions" for the "Sea Battle!" game.
	
	@author <Earl Moss>
	@version 1.0
*/

#pragma once
#include <stdexcept>
#include <cstdlib>

using namespace std;

/**
    This Cell struct represents a single cell in the grid.  It contains a row (int) and a column (char).

*/
struct Cell {

	/**
	    The row of the cell (1 <= row <= GRID_SIZE).
	
	*/
	int row;
	
	/**
	    The column of the cell ('A' <= col <= ('A' + GRID_SIZE))
	
	*/
	char col;

};

/**
    Generates and returns a pseudorandom number

    @param max The upper bound of the pseudorandom number
    @return a pseudorandom number n in the range 0 <= n < max
*/
int randint(int);

/**
    Reads from standard input until an integer character is found
    (Copied from sample code provided in "Errors, Part 2" lecture notes)
    
*/
void skip_to_int();

/**
    Read and return an integer from standard input
    (Copied from sample code provided in "Errors, Part 2" lecture notes)

    @return An integer value read from standard input
*/
int get_int();

/**
    Read and validate a pair of coordinates (row and column) from the user, and return as a Cell.
	(If invalid values for the column and/or row are provided, the user is repeatedly prompted until
	valid values are provided.)

	@param max The maximum allowed value of the column and row; corresponds to the size of the grid
    @return An integer value read from standard input
*/
Cell get_cell(int);
