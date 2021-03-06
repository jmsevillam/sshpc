#include "matrix.h"

// Run Matrix Calculations
int main(int argc, char** argv){
	// We create the problem initial conditions (positive integers)
	unsigned int samples;
	unsigned int size_X;
	unsigned int size_data;
	// Iterator variables
	unsigned int j,k;
	// Matrix Object
	my_prec **dataMatrix;
	// Timer example
	SimpleTimer_t t1,t2;
	// Random seed, set the seed to the random number generator
    srand(seed);

	// Setting the problem size!
	samples = 8192; size_X = 128; size_data = 512;

	// Creating the Matrix
	dataMatrix = CREATE_MATRIX(size_data,size_X);

	// Collect start time for this snippet
	SimpleTimer_start( &t1 );
	// Set all values of the matrix to 1
	for( j=0; j < size_data; j++ )
		for( k=0; k < size_X; k++ )
			dataMatrix[j][k] = 0.0;
	// Collect stop time
	SimpleTimer_stop( &t1 );
	// Print duration
	SimpleTimer_print( &t1 );


	// BEGIN: DEBUG SNIPPET
	// Why this snippet of code?
	// Collect start time for this snippet
	SimpleTimer_start( &t1 );
	// Set all values of the matrix to 1
	for( j=0; j < size_data; j++ )
		for( k=0; k < size_X; k++ )
			dataMatrix[j][k] = 2.0;
	// Collect stop time
	SimpleTimer_stop( &t1 );
	// Print duration
	SimpleTimer_print( &t1 );
	// END: DEBUG SNIPPET
	// Why does it take shorter time to run this loop?

	//
	// Reset the matrix elements to zero
	//
	SimpleTimer_start( &t2 );
	// Set all values of the matrix to 0
	SetMatrixZero(dataMatrix,size_data,size_X);
	// Collect stop time
	SimpleTimer_stop( &t2 );
	// Print duration
	SimpleTimer_print( &t2 );

	//
	// Place random elements!
	//
	SimpleTimer_start( &t2 );
	// Set all values of the matrix to 0
	SetMatrixRandom(dataMatrix,size_data,size_X);
	// Collect stop time
	SimpleTimer_stop( &t2 );
	// Print duration
	SimpleTimer_print( &t2 );
	//
	// Check out the Times!
	//

	// Finally, we clean the memory stack as suggested
	// from arrays.c
	free(dataMatrix[0]);
	free(dataMatrix), dataMatrix = NULL;

	// End
	return 0;
}
