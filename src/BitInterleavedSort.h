//*******************************************************************************
//* BitInterleavedSort.h
//* C++ Class Interface Definition of the BitInterleavedSort Class
//*
//* Copyright (C) 2000, John A. Kassebaum - All Rights Reserved.
//*
//* See file "COPYING" for Licensing Info.
//*
//* Version: $Id: BitInterleavedSort.h,v 1.2 2000/05/10 06:20:27 jak Exp $
//*
//******************************************************************************/

#ifndef _BitInterleavedSort_H
#define _BitInterleavedSort_H

static char rcsid_BitInterleavedSort_h[] = "$Id: BitInterleavedSort.h,v 1.2 2000/05/10 06:20:27 jak Exp $";

#include "DataSet.h"

namespace BisNet {
	class BitInterleavedSort {

		// Data Members
		//

	public:
		// Constructor and Destructor
		BitInterleavedSort( const DataSet & );
		virtual ~BitInterleavedSort( void );

		// Class Methods
		
		// Instance Methods
		
	};
}

// Include Inline Methods
#include "BitInterleavedSort.inl"

#endif // _BitInterleavedSort_H

