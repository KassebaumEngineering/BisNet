
//
// $Id: main.cc,v 1.1.1.1 2000/05/03 05:55:03 jak Exp $
//
// This is the main driver program for the bisnet program.
//
// Copyright: John A. Kassebaum - All Right Reserved (c) 2000.
//
// see file "COPYING" for license info.
//
//

static char rcsid_main_cc[] = "$Id: main.cc,v 1.1.1.1 2000/05/03 05:55:03 jak Exp $";

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

//
// Usage Info -------------------------------------------------------------
//
#define USAGE    "Usage: %s [args] < input data_file > output data_file\n"
#define DESCR_0    "Where args are one or more of:\n"
#define DESCR_1    " -h            prints this help message and exits.\n"
#define DESCR_2    " -v            verbosely prints out data\n"
#define DESCR_7    " -bi           set input file type to binary (float)\n"
#define DESCR_8    " -bo           set output file type to binary (float)\n"
#define DESCR_9    " -no           request no output\n"
#define DESCR_12   "\n data_file  -  A file of floating point numbers\n"
#define DESCR_13   "(default) in ascii format, with one number per line. \n "
#define DESCR_14   "example:\n"
#define DESCR_15   " -47.52\n -39.59\n -27.72\n -15.84\n"
////
// ------------------------------------------------------------------------
//

#define BLOCKSIZE    1024
#define Null(A)             ((A *) 0)
#define New(A)              ((A *) malloc( sizeof(A) ) )
#define NewBlock(A,N)       ((A *) malloc( sizeof(A) * (N)) )
#define BiggerBlock(A,B,N)  ((A *) realloc( (void *)(B), sizeof(A) * (N)))

main(int argc,char **argv)
{
    int c,i,j,k;
    int verbose, stats, flag;
	int binary_input, binary_output, no_output;

    long int data_count;
    long int space_alloc;
    float min_value, max_value;
    double tempf;
    int step_count;
    float step;
    float *data;
    float *output_data;

    verbose = 0;
    stats = 0;
	binary_input = 0;
	binary_output = 0;
	no_output = 0;
	
	
  //
  // Parse Command Line
  //
    for (c=1; c< argc; c++) {
        if ( !strcmp( argv[ c ],"-h") || !strcmp( argv[ c ],"-help")){
            fprintf(stderr,USAGE,argv[0]);
            fprintf(stderr,DESCR_0);
            fprintf(stderr,DESCR_1);
            fprintf(stderr,DESCR_2);
            fprintf(stderr,DESCR_3);
            fprintf(stderr,DESCR_7);
            fprintf(stderr,DESCR_8);
            fprintf(stderr,DESCR_9);
            fprintf(stderr,DESCR_12);
            fprintf(stderr,DESCR_13);
            fprintf(stderr,DESCR_14);
            fprintf(stderr,DESCR_15);
            exit(0);
        } else if (!strcmp( argv[ c ],"-v")){
            verbose = 1;
        } else if (!strcmp( argv[ c ],"-s")){
            stats = 1;
        } else if (!strcmp( argv[ c ],"-bi")){
			binary_input = 1;
        } else if (!strcmp( argv[ c ],"-bo")){
			binary_output = 1;
        } else if (!strcmp( argv[ c ],"-no")){
			no_output = 1;
        }
    }
    
    data_count = 0;
    space_alloc = 0;
    data = (float *)0;
    
    if( data = NewBlock( float, BLOCKSIZE ) ){
        space_alloc = BLOCKSIZE;
    } else {
        perror(argv[0]);
        abort();
    };
        
	if (binary_input) {
	  //
	  // binary input data
	  //
	    int fd, bytes_read, block_size;
		fd = 0;    // note: stdin is always fd = 0
		
		block_size = BLOCKSIZE;
	    while ((bytes_read = read( fd, (char *) &data[ data_count ], (block_size*sizeof(float)) ))
		                   > 0 )
		{
		    data_count += ( bytes_read / sizeof(float) );
			if( (block_size = (space_alloc - data_count)) < 1) {
				if( data = BiggerBlock( float, data, (space_alloc + BLOCKSIZE) ) ){
					space_alloc += BLOCKSIZE;
					block_size = space_alloc - data_count;
				} else {
					perror(argv[0]);
					abort();
				}
			}
		}
		
	    if( bytes_read == -1 ) {
			perror(argv[0]);
			abort();
		}
		
		if( verbose ){
		    for( i=0; i< data_count; i++){
		        fprintf(stderr, "%f\n", data[ i ]);
			}
		}
		
		if( stats ){
		    int i;
		    flag = 0;
		    for( i=0; i< data_count; i++){
				if (!flag) {
					min_value = max_value = data[ i ];
					flag = 1;
				} else {
					if( data[ i ] < min_value )
						min_value = data[ i ];
					if( data[ i ] > max_value )
						max_value = data[ i ];
				}
			}
		} 
		
 	} else { 
	  //
	  // ascii input data
	  //
		flag = 0;
		while ( scanf( "%f", &data[ data_count ]) != EOF ){
			if (!flag) {
				min_value = max_value = data[ data_count ];
				flag = 1;
			} else {
				if( data[ data_count ] < min_value )
					min_value = data[ data_count ];
				if( data[ data_count ] > max_value )
					max_value = data[ data_count ];
			}
			if (verbose) fprintf(stdout, "%f\n", data[ data_count ]);
			data_count++;
			if ( data_count >= space_alloc ){
				if( data = BiggerBlock( float, data, (space_alloc + BLOCKSIZE) ) ){
					space_alloc += BLOCKSIZE;
				} else {
					perror(argv[0]);
					abort();
				};
			};
		}
	}
    
    if (stats) {
        fprintf(stderr, "Space Allocated for %d floats.\n", space_alloc);
        fprintf(stderr, "Space Used for %d floats.\n", data_count);
        fprintf(stderr, "Minimum value = %f.\n", min_value);
        fprintf(stderr, "Maximum value = %f.\n", max_value);
    }
        
	//
	// Call subprogram to generate BIS Neural Network --------------
	//
	
	//
	// -------------------------------------------------------------
	//
	
	if( !no_output ) {
		if( binary_output ) {
			//
			// Binary Output Data
			//
			int fd;
			fd = 1; // stdout is always file descriptor 1
			if( write( fd, output_data, data_count*sizeof(float) ) == -1){
				perror(argv[0]);
				abort();
			}
		} else {
			//
			// Ascii Output Data
			//
			for(i=0; i< data_count; i++){
				fprintf(stdout,"%f\n",output_data[i]);
			}
		}
	}
	
    free( data );
}
