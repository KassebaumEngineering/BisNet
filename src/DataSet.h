//*******************************************************************************
//* DataSet.h
//* C++ Class Interface Definition of the DataSet Class
//*
//* Copyright (C) 2000, John A. Kassebaum - All Rights Reserved.
//*
//* See file "COPYING" for Licensing Info.
//*
//* Version: $Id: DataSet.h,v 1.1 2000/05/08 23:32:24 jak Exp $
//*
//******************************************************************************/

#ifndef _DataSet_H
#define _DataSet_H

static char rcsid_DataSet_h[] = "$Id: DataSet.h,v 1.1 2000/05/08 23:32:24 jak Exp $";

#include <mtl/mtl.h>
#include <string>
#include <map>

namespace BisNet {
	class DataSet {

		// Class Data Members
		//
		static std::map< std::string, DataSet& > DataSetMap;
		
		// Instance Data Members
		//
		std::string name;
		Matrix & training_input;
		Matrix & training_output;
		Matrix & testing_input;
		Matrix & testing_output;

	public:
	    static DataSet & getDataSet( string aName );
	    static void      deleteDataSet( std::string aName );
	
	private:
		// Constructor and Destructor
		DataSet( std::string aName );
		virtual ~DataSet();

		// Class Methods
		
		// Instance Methods
		Matrix & getTrainingInput();
		void setTrainingInput( Matrix &inputdata );
		
		Matrix & getTrainingOutput();
		void setTrainingOutput( Matrix &outputdata );
		
		Matrix & getTestingInput();
		void setTrainingInput( Matrix &inputdata );
		
		Matrix & getTestingOutput();
		void setTrainingInput( Matrix &outputdata );
	};
}

// Include Inline Methods
#include "DataSet.inl"

#endif // _DataSet_H

