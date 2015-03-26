//
// CST 420 - Assignment # 2
//
// Author: Leander Rodriguez
//
// File: skip.cpp
//
// Due date:  Sunday, July 21st by 11:59pm
//


#include <iostream>
#include <fstream>
#include "skip.h"


using  namespace  std;


//
// Skip Class Constructor
//
Skip::Skip( const string &skipFileName )
{

	//
	// Skip file is opened and checked
	//
	ifstream skipIN( skipFileName );


	if( !skipIN )
	{

		cout  <<  "Error opening file '"
			  <<  skipFileName
			  <<  "'"
			  <<  endl; 

		exit( EXIT_FAILURE );
	}


	//
	// Read in from Skip file and insert into container
	//
	string wordTOskip;

	while( getline( skipIN, wordTOskip ) )
	{
		m_skip.insert( wordTOskip );
	}


	//
	// Skip file is closed
	//
	skipIN.close();

}



//
// Returns true is word is found in Skip container
//
const bool Skip::exists( string wordTOskip ) const
{

	set<string>::const_iterator  iter;

	iter  =  m_skip.find( wordTOskip );

	if( iter != m_skip.end() )
	{
		return true;
	}
	else
	{
		return false;
	}

}
