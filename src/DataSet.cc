//*******************************************************************************
//* DataSet.cc
//* C++ Class Implementation of the DataSet Class
//*
//* Copyright (C) 2000, John A. Kassebaum - All Rights Reserved.
//*
//* See file "COPYING" for Licensing Info.
//*
//* Version: $Id: DataSet.cc,v 1.2 2000/05/10 06:20:27 jak Exp $
//*
//* See DataSet.h for the Interface description and Usage directions.
//*
//******************************************************************************/

static char rcsid_DataSet_cc[] = "$Id: DataSet.cc,v 1.2 2000/05/10 06:20:27 jak Exp $";

#include "DataSet.h"

namespace BisNet {

 	//  Class Data
	//
	DataSet::ByLabel DataSet::DataSetMap;
    
	//  Factory
	//
	DataSet & DataSet::getDataSet( std::string aName ) {
		if ( 0 == DataSetMap.count( aName ) ) {
		    DataSet *dataSet_p = new DataSet( aName );
		    DataSetMap.insert( ByLabel::value_type( aName, dataSet_p ) );
		}
		return *(DataSetMap[ aName ]);
	}
	
	void DataSet::deleteDataSet( std::string aName ) {
	    if ( 0 != DataSetMap.count( aName ) ) {
		    DataSet *tmp_p = DataSetMap[ aName ];
		    DataSetMap.erase( aName );
			delete tmp_p;
		}
	}

	//  Constructor(s)
	//
	DataSet::DataSet( std::string aName ) : name( aName )
	{
	    MatrixStream trn_in_stream( (char *)(name + ".trn.in").c_str() );
	    training_input  = new Matrix( trn_in_stream );
		
	    MatrixStream trn_out_stream( (char *)(name + ".trn.out").c_str() );
		training_output = new Matrix( trn_out_stream );
		
	    MatrixStream tst_in_stream( (char *)(name + ".tst.in").c_str() );
		testing_input   = new Matrix( tst_in_stream );
		
	    MatrixStream tst_out_stream( (char *)(name + ".tst.out").c_str() );
		testing_output  = new Matrix( tst_out_stream );
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

