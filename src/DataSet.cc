//*******************************************************************************
//* DataSet.cc
//* C++ Class Implementation of the DataSet Class
//*
//* Copyright (C) 2000, John A. Kassebaum - All Rights Reserved.
//*
//* See file "COPYING" for Licensing Info.
//*
//* Version: $Id: DataSet.cc,v 1.1 2000/05/08 23:32:24 jak Exp $
//*
//* See DataSet.h for the Interface description and Usage directions.
//*
//******************************************************************************/

static char rcsid_DataSet_cc[] = "$Id: DataSet.cc,v 1.1 2000/05/08 23:32:24 jak Exp $";

#include "DataSet.h"

namespace BisNet {

 	//  Class Data
	//
	std::map< std::string, DataSet& > DataSet::DataSetMap;
    
	//  Factory
	//
	DataSet & DataSet::getDataSet( std::string aName ) {
		if ( 0 == DataSet.count( aName ) ) {
		    DataSet & dataSet = new DataSet( aName );
		    DataSetMap.insert( std::map< std::string, DataSet& >::value_type( aName, dataSet ) );
		}
		return DataSetMap[ aName ];
	}
	
	void DataSet::deleteDataSet( std::string aName ) {
	    if ( 0 != DataSet.count( aName ) ) {
		    DataSet & tmp = DataSetMap[ aName ];
		    DataSetMap.erase( aName );
			delete tmp;
		}
	}

	//  Constructor(s)
	//
	DataSet::DataSet( std::string aName ) : name( aName )
	{
	    training_input  = new Matrix( matrix_market_stream< double >( aName + "trn.in" ) );
		training_output = new Matrix( matrix_market_stream< double >( aName + "trn.out" ) );
		testing_input   = new Matrix( matrix_market_stream< double >( aName + "tst.in" ) );
		testing_output  = new Matrix( matrix_market_stream< double >( aName + "tst.out" ) );
	}

	//  Destructor
	//
	DataSet::~DataSet()
	{
	    delete training_input;
		delete training_output;
		delete testing_input;
		delete testing_output;
	}

	// Class Methods
	//

	// Instance Methods
	//

}

