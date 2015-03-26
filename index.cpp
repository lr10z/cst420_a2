//
// CST 420 - Assignment # 2
//
// Author: Leander Rodriguez
//
// File: index.cpp
//
// Due date:  Sunday, July 21st by 11:59pm
//


#include  <fstream>
#include  <sstream>
#include  "index.h"
#include  "skip.h"


typedef  set<Entry>  EntrySet;


//
// Index Class Constructor
//
Index::Index( const string &docFileName )
{

	//
	// Document file is opened and checked
	//
	ifstream docIN( docFileName );


	if( !docIN )
	{

		cout  <<  "Error opening document '"
			  <<  docFileName
			  <<  "'"
			  <<  endl; 

		exit( EXIT_FAILURE );

	}

	

	//
	// Skip file is opened and object is created
	//
	string skipFileName;

	cout  <<  "Enter the skip-words file name: ";

	getline( cin, skipFileName );
	


	//
	// Read in a line of text from Document file
	//
	int  lineNum  =  0;
	int  pageNum  =  1;


	while( ! docIN.eof() )
	{

		string  lineFromFile;

		getline( docIN, lineFromFile );

		++lineNum;


		//
		// Keeps track of page number
		//
		if  ( lineFromFile == "<newpage>" )
		{
			++pageNum;
			lineNum  =  0;
			continue;
		}


		//
		// Ignores blank lines read in
		//
		if  ( lineFromFile.length() == 0 )
		{
			continue;
		}


		//
		// Line that was read in from file, will be parsed into words
		//
		breakLineIntoWords( lineFromFile, pageNum, lineNum, skipFileName );

	}



	//
	// Displays contents of the Index container
	//
	displayIndex();


	//
	// Document file is closed
	//
	docIN.close();


}



//
// Line read in from Document file is parsed into words; 
// their respective page and line numbers are stored
//
const void Index::breakLineIntoWords( string lineFromFile, 
									  int pageNum, 
									  int lineNum, 
									  string skipFileName )
{

	//
	// Instance of Skip object is created
	//
	Skip skipWords( skipFileName );
	

	//
    // Associate the line from the file with a stream
    //
    istringstream  in( lineFromFile );


    //
    // Break the line into individual words based on whitespace
    // using the stream.
    //
    while( ! in.eof() )
    {
		
		//
		// Gets the next word from stream
		//
		string  word;
		in  >>  word; 


		//
		// Normalize word to remove uppercase and punctuation
		//
		toLower( word );

		erasePunctuation( word );
		


		//
		// Check if word is in skip file, if not, data is stored
		//
		if( ! skipWords.exists( word ) )
		{
		
			//
			// Entry object is created:
			// word, page #, and line # are stored 
			//
			Entry entry( word, pageNum, lineNum );


			//
			// Each entry is then stored into Index-class container
			//
			m_entries.insert( entry );

		}
	
   }

}



//
// Converts all uppercase words to lowercase
//
const void Index::toLower( string &word ) const
{

	if( isupper( word[0] ) )
	{
		transform( word.begin(), word.end(), word.begin(), ::tolower );
	}

}



//
// Removes all punctuation found at the beginning or end of the string
//
const void Index::erasePunctuation( string &word ) const
{
	
	while( ispunct( word.front() ) )
	{
		word.erase( word.begin() );
	}

	while( ispunct( word.back() ) )
	{
		word.erase( word.end()-1 );
	}

}



//
// Displays contents of the Index-class container
//
const void Index::displayIndex() const
{

	EntrySet::iterator  iter;


	//
	// Header
	//
	cout <<  endl
		 <<  "Index"  
		 <<  endl
		 <<  "-----";  


	//
	// Loops through container and displays contents
	//
	string lastWord;

	for( iter = m_entries.begin(); iter != m_entries.end(); ++iter )
	{

		//
		// Checks for duplicate words
		//
		if( lastWord == iter->word() )
		{

			cout  <<  ", "
				  <<  iter->pagenum()
				  <<  "."
				  <<  iter->linenum();
			
		}
		else
		{
			cout  <<  endl  <<  *iter;
		}


		lastWord = iter->word();

	}

	cout << endl;
}



//
// Insertion operator
//
ostream  &operator<<( ostream  &lhs, const Entry  &rhs )
{

	return  lhs <<  rhs.word()  
				<<  endl
				<<  "  "
				<<  rhs.pagenum()
				<<  "."
				<<  rhs.linenum();

}