//*******************************************************************************
//* DataSet.inl
//* C++ Class Inline Methods of the DataSet Class
//*
//* Copyright (C) 2000, John A. Kassebaum - All Rights Reserved.
//*
//* See file "COPYING" for Licensing Info.
//*
//* Version: $Id: DataSet.inl,v 1.2 2000/05/10 06:20:27 jak Exp $
//*
//******************************************************************************/
#ifndef _DataSet_I
#define _DataSet_I

static char rcsid_DataSet_inl[] = "$Id: DataSet.inl,v 1.2 2000/05/10 06:20:27 jak Exp $";

#ifndef NOINLINES
#define INLINE inline
#else
#define INLINE 
#endif // NOINLINES

namespace BisNet {
	// Inline Methods
	//
	DataSet::Matrix & DataSet::getTrainingInput() const { return *training_input; }
	void DataSet::setTrainingInput( const DataSet::Matrix &inputdata ){ 
	    if ( (Matrix *)0 != training_input ) delete training_input;
	    training_input = new Matrix( inputdata ); 
	}

	DataSet::Matrix & DataSet::getTrainingOutput() const { return *training_output; }
	void DataSet::setTrainingOutput( const DataSet::Matrix &outputdata ) { 
	    if ( (Matrix *)0 != training_output ) delete training_output;
	    training_output = new Matrix( outputdata ); 
	}

	DataSet::Matrix & DataSet::getTestingInput() const { return *testing_input; }
	void DataSet::setTestingInput( const DataSet::Matrix &inputdata ) { 
	    if ( (Matrix *)0 != testing_input ) delete testing_input;
	    testing_input = new Matrix( inputdata ); 
	}

	DataSet::Matrix & DataSet::getTestingOutput() const { return *testing_output; }
	void DataSet::setTestingOutput( const DataSet::Matrix &outputdata ) { 
	    if ( (Matrix *)0 != testing_output ) delete testing_output;
	    testing_output = new Matrix( outputdata ); 
	}

}
#endif //_DataSet_I

