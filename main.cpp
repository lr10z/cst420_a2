//
// CST 420 - Assignment # 2
//
// Author: Leander Rodriguez
//
// File: main.cpp
//
// Due date:  Sunday, July 21st by 11:59pm
//


#include  "index.h"
 

using  namespace  std;


//
// Main program
//
int  main()
{

	//
	// Prompt user to enter file name
	//
	string  docFileName; 

	cout  <<  "Enter document file name: ";

	getline( cin, docFileName );

	
	//
	// Index object is created
	//
	Index index( docFileName );


	return  0;

}