//
// CST 420 - Assignment # 2
//
// Author: Leander Rodriguez
//
// File: entry.h
//
// Due date:  Sunday, July 21st by 11:59pm
//


#ifndef  ENTRY_H
#define  ENTRY_H


#include <string>
#include <utility>
#include <set>


using namespace std;


typedef pair< int, int > Occurence;


//
// Entry class declaration
//
class  Entry
{

  public  :

	//
	// Contructor
	//
	Entry( const string word, int pageNum, int lineNum );

	//
	// Methods
	//
	const string word() const { return m_word;	  }

	const int pagenum() const { return m_pageNum; }
	const int linenum() const { return m_lineNum; }


  private  :
	 
	//
	// Member variables
	//
	string m_word;

	int m_pageNum;
	int m_lineNum;

	//
	// Member container
	//
	set<Occurence> m_occurence;

};


bool  operator<(  const Entry  &lhs, const Entry  &rhs );


#endif
