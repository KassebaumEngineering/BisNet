//*******************************************************************************
//* DataSet.h
//* C++ Class Interface Definition of the DataSet Class
//*
//* Copyright (C) 2000, John A. Kassebaum - All Rights Reserved.
//*
//* See file "COPYING" for Licensing Info.
//*
//* Version: $Id: DataSet.h,v 1.2 2000/05/10 06:20:27 jak Exp $
//*
//******************************************************************************/

#ifndef _DataSet_H
#define _DataSet_H

static char rcsid_DataSet_h[] = "$Id: DataSet.h,v 1.2 2000/05/10 06:20:27 jak Exp $";

#include <mtl/mtl.h>
#include <mtl/utils.h>
#include <mtl/matrix_market_stream.h>
#include <string>
#include <map>

namespace BisNet {
	class DataSet {

		// Class Type Definitions
		//
		typedef std::map< std::string, DataSet* > ByLabel;
		typedef mtl::matrix< double, mtl::rectangle<>, mtl::dense<>, mtl::column_major >::type Matrix;
		typedef mtl::matrix_market_stream< double > MatrixStream;

		// Class Data Members
		//
		static ByLabel DataSetMap;
		
		// Instance Data Members
		//
		std::string name;
		Matrix *training_input;
		Matrix *training_output;
		Matrix *testing_input;
		Matrix *testing_output;

	public:
	    static DataSet & getDataSet( string aName );
	    static void      deleteDataSet( std::string aName );
	
	private:
		// Constructor and Destructor
		DataSet( std::string aName );
		virtual ~DataSet();

		// Class Methods
		
		// Instance Methods
		Matrix & getTrainingInput( void ) const;
		void setTrainingInput( const Matrix & inputdata );
		
		Matrix & getTrainingOutput( void ) const;
		void setTrainingOutput( const Matrix & outputdata );
		
		Matrix & getTestingInput( void ) const;
		void setTestingInput( const Matrix & inputdata );
		
		Matrix & getTestingOutput( void ) const;
		void setTestingOutput( const Matrix & outputdata );
	};
}

// Include Inline Methods
#include "DataSet.inl"

#endif // _DataSet_H

