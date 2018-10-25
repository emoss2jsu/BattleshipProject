/**
	CS 231 Project 2
	grid.h
	Purpose: Header for the Grid class for the "Sea Battle!" game.
	
	@author <Earl Moss>
	@version 1.0
*/

#pragma once
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/**
    This class manages a Grid (a primary grid or a tracking grid) for the game of "Sea Battle!".
    
*/
class Grid {

	public:

		/**
		    Constructor.
		
		    @param s The initial size (width and height) of the grid.
		    @param n The name of the grid.
		*/
		Grid(int, string);

		/**
		    Sets the contents of a cell in the grid to the specified char.
		
		    @param c The Cell containing the column and row of the cell in the grid to be changed.
		    @param k The char to be placed into the specified cell.
		*/
		void set(Cell, char);

		/**
		    Returns the contents of one cell in the grid.
		
		    @param c The Cell containing the column and row of the cell in the grid to be returned.
		    @returns The char in the specified grid cell.
		*/
		char get(Cell);

		/**
		    Deploys the specified list of ships into the grid.  The position and orientation of
		    the ships should be chosen at random, and the ships should not overlap.
		
		    @param ship_type A vector of char symbols corresponding to the ship types.
		    @param ship_size A vector of int values corresponding to the ship sizes (lengths).
		*/
		void deploy_fleet(const vector<char>&, const vector<int>&);

		/**
		    Prints the grid name and contents to standard output.
		
		*/
		void print();

	private:

		/**
		    A two-dimensional char vector containing the rows and columns of the grid.
		
		*/
		vector< vector<char> > grid;

		/**
		    The size (width and height) of the grid.
		
		*/
		int grid_size;

		/**
		    The name of the grid.
		
		*/
		string name;
	
};
