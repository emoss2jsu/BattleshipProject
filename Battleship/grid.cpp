/**
	CS 231 Project 2
	grid.cpp
	Purpose: Implementation of the Grid class for the "Sea Battle!" game.
	
	@author <Earl Moss>
	@version 1.0
*/

#include "util.h"
#include "grid.h"

using namespace std;

/**
    CONSTRUCTOR

    @param s The initial size (width and height) of the grid.
    @param n The name of the grid.
*/
Grid::Grid(int s, string n) {
	
	grid_size = s;
	name = n;
	grid = vector< vector<char> >( grid_size, vector<char>( grid_size, '-' ) );
	
}

/**
	Deploys the specified list of ships into the grid.  The position and orientation of
	the ships should be chosen at random, and the ships should not overlap.
	
	@param ship_type A vector of char symbols corresponding to the ship types.
	@param ship_size A vector of int values corresponding to the ship sizes (lengths).
*/
void Grid::deploy_fleet(const vector<char>& ship_type, const vector<int>& ship_size) {
	
	/* Define State Variables */

	int alignment = 0;						/* Ship Alignment (0=horizontal, 1=vertical) */
	int row = 0;							/* Column of First Ship Cell (chosen at random) */
	int col = 0;							/* Row of First Ship Cell (chosen at random) */
	int empty_count = 0;					/* Empty Space Counter */
	int next_ship_size = 0;					/* Ship Length */
	char next_ship_type;					/* Ship Character */
	bool empty;								/* Empty Ship Footprint */
	
	int num_ships = ship_type.size();		/* Get number of ships from fleet data */

	/* Arrange Ships */

	for (int i = 0; i < num_ships; ++i) {

		empty = false;
		
		/* Get code and size for the next ship in the fleet */

		next_ship_type = ship_type[i];
		next_ship_size = ship_size[i];

		/* Begin search for footprint for next ship; exit loop only if entire footprint is empty */

		while ( !empty ) { 

			/* Reset empty space counter */

			empty_count = 0;

			/* Select alignment at random */

			alignment = randint(2); // (0 is horizontal, 1 is vertical)
			
			/* Select row and column at random */

			if (alignment) {
				
				/* Ship will be vertical; select row and column, and ensure row is within range! */
				
				row = randint(grid_size - next_ship_size + 1);
				col = randint(grid_size);
				
			}

			else {
				
				/* Ship will be horizontal; select row and column, and ensure column is within range! */
				row = randint(grid_size);
				col = randint(grid_size - next_ship_size + 1);
			}

			/* Count empty spaces within footprint */
			
			for(int j = 0; j < next_ship_size; ++j){
			
				

				/* If vertical, check for empty space in next row; increment counter if space is empty */
				if(alignment){
					if(grid[row + j][col] == '-')
						++empty_count;
				}
				
				/* If horizontal, check for empty space in next column; increment counter if space is empty */
				else{
					if(grid[row][col+j] == '-')
						++empty_count;
				}
			}
			/* If empty space count equals ship size, footprint is not occupied; flip flag and end search */

			if ( empty_count == next_ship_size ) {

				empty = true;

			}
			
		} // end while()

		/* Place ship inside empty footprint */

		for (int j = 0; j < next_ship_size; ++j) {

			if ( alignment ) {
				
				/* Ship is vertical; place next piece in the next row */

				grid[row + j][col] = next_ship_type;

			}

			else {
				
				/* Ship is horizontal; place next piece in the next column */

				grid[row][col + j] = next_ship_type;

			}

		} // end for()

	} // end for()
	
} // end deploy_fleet()

/**
	Sets the contents of a cell in the grid to the specified char.
	
	@param c The Cell containing the column and row of the cell in the grid to be changed.
	@param k The char to be placed into the specified cell.
*/
void Grid::set(Cell c, char k) {
	
	int row = ( c.row - 1 );															/* Convert column label to index */
	int col = ( toupper(c.col) - 'A' );													/* Convert row label to index */
	
	grid[row][col] = k;
	
} // end set()

/**
	Returns the contents of one cell in the grid.
	
	@param c The Cell containing the column and row of the cell in the grid to be returned.
	@returns The char in the specified grid cell.
*/
char Grid::get(Cell c) {
	
	int row = ( c.row - 1 );															/* Convert column label to index */
	int col = ( toupper(c.col) - 'A' );													/* Convert row label to index */
	
	return grid[row][col];
	
} // end get()

/**
	Prints the grid name and contents to standard output.
*/
void Grid::print() {
	
	cout << setw(12) << left << name << "  A  B  C  D  E  F  G  H  I  J\n" << right;	/* Print header row */

	for (int i = 0; i < grid_size; ++i) {												/* Loop through rows */

		cout << setw(12) << (i + 1) << ' ';												/* Print row label */

		for (int j = 0; j < grid_size; ++j) {											/* Loop through columns */

			switch( grid[i][j] ) {

				case '-': case '/': case 'X':											/* Non-ship pieces enclosed in spaces */
					cout << ' ' << grid[i][j] << ' ';
					break;
				default:
					cout << '[' << grid[i][j] << ']';									/* Ship pieces enclosed in square brackets */

			} // end switch

		} // end for (columns)

		cout << '\n';

	} // end for (rows)
	
} // end print()
