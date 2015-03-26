//
// CST 420 - Assignment # 2
//
// Author: Leander Rodriguez
//
// File: skip.h
//
// Due date:  Sunday, July 21st by 11:59pm
//


#ifndef  SKIP_H
#define  SKIP_H


#include <string>
#include <set>
#include <algorithm>


using namespace std;


//
// Skip class declaration
//
class  Skip
{

  public  :

	//
	// Contructor
	//
	Skip( const string &skipFileName );

	
	//
	// Method
	//
	const bool exists( string wordTOskip ) const;
	

  private  :

	//
	// Member container
	//
	set<string> m_skip;

};


#endif
