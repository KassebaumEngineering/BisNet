//*******************************************************************************
//* DataSet.inl
//* C++ Class Inline Methods of the DataSet Class
//*
//* Copyright (C) 2000, John A. Kassebaum - All Rights Reserved.
//*
//* See file "COPYING" for Licensing Info.
//*
//* Version: $Id: DataSet.inl,v 1.1 2000/05/08 23:32:24 jak Exp $
//*
//******************************************************************************/
#ifndef _DataSet_I
#define _DataSet_I

static char rcsid_DataSet_inl[] = "$Id: DataSet.inl,v 1.1 2000/05/08 23:32:24 jak Exp $";

#ifndef NOINLINES
#define INLINE inline
#else
#define INLINE 
#endif // NOINLINES

namespace BisNet {
	// Inline Methods
	//
	
	Matrix & getTrainingInput() { return training_input; }
	void setTrainingInput( Matrix &inputdata ){ training_input = inputdata; }

	Matrix & getTrainingOutput() { return training_output; }
	void setTrainingOutput( Matrix &outputdata ) { training_output = outputdata; }

	Matrix & getTestingInput() { return testing_input; }
	void setTrainingInput( Matrix &inputdata ) { testing_input = inputdata; }

	Matrix & getTestingOutput() { return testing_output; }
	void setTrainingInput( Matrix &outputdata ) { testing_output = outputdata; }

}
#endif //_DataSet_I

