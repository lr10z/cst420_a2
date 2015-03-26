//
// CST 420 - Assignment # 2
//
// Author: Leander Rodriguez
//
// File: index.h
//
// Due date:  Sunday, July 21st by 11:59pm
//


#ifndef  index_H
#define  index_H


#include  <iostream>
#include  <set>
#include  "entry.h"


using namespace std;


//
// Index class declaration
//
class Index
{

	friend  ostream  &operator<<( ostream  &lhs, const Entry  &rhs );

  public :

	//
	// Constructor
	//
	Index( const string &docFileName );

	//
	// Methods
	//
	const void breakLineIntoWords( string lineFromFile, 
								   int pageNum, 
								   int lineNum, 
								   string skipFileName );

	const void toLower( string &word )			const;
	const void erasePunctuation( string &word ) const;
	const void displayIndex()					const;


  private :

	// 
	// Member container
	//
	set<Entry> m_entries;

};


#endif




