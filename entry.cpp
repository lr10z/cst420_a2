//
// CST 420 - Assignment # 2
//
// Author: Leander Rodriguez
//
// File: entry.cpp
//
// Due date:  Sunday, July 21st by 11:59pm
//


#include  "entry.h"


using  namespace  std;


//
// Constructor
//
Entry::Entry( const string word, int pageNum, int lineNum ) :
	m_word( word ), 
	m_pageNum( pageNum ), 
	m_lineNum( lineNum )
{

	m_occurence.insert( Occurence( m_pageNum, m_lineNum ) );

}


//
// Container comparison operator, sorts container 
//
bool  operator<( const Entry  &lhs, const Entry  &rhs )
{
	
	//
	// Sorts by page number if word is duplicated
	//
	if( string( lhs.word() ) == string( rhs.word() ) )
	{

		//
		// Sorts by line number if page number is duplicated
		//
		if( int( lhs.pagenum() ) == int( rhs.pagenum() ) )
		{
			return int( lhs.linenum() ) < int( rhs.linenum() );
		}


		//
		// Sorts by page number
		//
		if( int( lhs.pagenum() ) < int( rhs.pagenum() ) )
		{
			return true;
		}
		
	}
	

	//
	// Sorts words alphabetically
	//
	return string( lhs.word() ) < string( rhs.word() );
	
}


