//============================================================================
// Name        : lab7_strings.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Lab7_strings.cpp
// This program shows some simple string examples, and asks for simple tasks.
// Reference: Lippman, section 3.2

// Author: Luis Rivera

// IMPORTANT NOTE: YOU MAY NEED TO COMPILE ADDING THE FOLLOWING FLAG: -std=c++11
//                 OR: -std=c++0x
// Example:  g++ Lab7_strings.cpp -o Lab7_strings -std=c++11
//      or:  g++ Lab7_strings.cpp -o Lab7_strings -std=c++0x
// Some initialization methods and other things are not supported by the old standard.

#include <iostream>
#include <string>

using namespace std;

// Main function. Shows a few examples. Complete the assignments stated in the comments.
int main()
{
	string s1, s2("Hello"), s3 = "World";
	cout << "\nEnter a word:" << endl;
	cin >> s1;
	cin.ignore();	// to consume the '\n' character. Otherwise, you may get issues with
					// the getline() below. Try commenting this out. Any issues?

	//it doesn't let the user "Enter some text", and skips it.

	string s4(s1);

	cout << s1 << endl
		 << s2 << endl
		 << s3 << endl
		 << s4 << endl;

	s1 = s2 + s3;
	cout << s1 << endl;

// ***********************************************************************
// Try all the operations in Table 3.2 using the strings above and
// using new strings that you may declare.
// Some of those operations have already been used, but write your
// own examples.
// ***********************************************************************

	//TABLE 3.2 EXAMPLES:

	string str1, str2, str3;//new strings I declared

	cout << "\nEnter string: ";
	cin >> str2; //input from user
	cin.ignore();
	cout << str2 << endl; //prints string
	cout << "\nEnter str1: ";
	getline(cin, str1); //reads input

	cout << str1 <<endl;
	if(str1.empty()){ //if string is not empty print
		cout << "\nstr1 is not empty" << endl;
	}

	int len;
	len = str2.size(); //find the length of the string
	cout << "\nthe length of str2 is: " << len << endl; //print length

	char c;
	c = str1[2]; //reference a specific character in the string
	cout << "Str1[2]: " << c << endl; //print that character

	str3 = str1 + str2; //combines strings
	cout << str1 << "+" << str2 << "=" << str3 << endl; //prints combines string

	str1 = str2; //replaces characters in str1 with the characters from str2

	if(str1 == str2){ //compares strings, and prints if equal
		cout << "the strings are equal." << endl;
	}

	if(str2 != str3){ //prints if the strings are not equal
		cout << "str2 and str3 are not equal: " << str2 << " , " << str3 << endl;
	}

	if(str3 >= str2){ //compares if str3 is greater than or equal to str2
		cout << "str3 >= str2\n" << str3 << "\n" << str2 << endl;
	}

	if(str3 > str2){ //compares if str3 is greater than str2 - should fail
		cout << "str3 > str2\n" << str3 << "\n" << str2 << endl;
	}

	if(str1 <= str2){ //compares i str1 is less than or equal to str2
		cout << "str1 <= str2\n" << str1 << "\n" << str2 << endl;
	}

	if(str3 < str2){ //compares is str3 is greater than str2 - should fail
		cout << "str3 > str2\n" << str3 << "\n" << str2 << endl;
	}
	else{
		cout << "str3 is not less than str2\n" << str3 << " , " << str2
			 << endl;
 	}

// -----------------------------------------------------------------------
	string line;
	string line2; //added
	cout << "\nEnter some text:" << endl;
	getline(cin, line);
	cout << line << endl;

	cout << "\nEnter some text, finish it with an &:" << endl;
	getline(cin, line2, '&');	// the delimiter can be any character
	cout << line2 << endl; //changed to line2

// ***********************************************************************
// Use a "Range for" (Lippman, page 93) and operations in table 3.3 to:
// 1) change the case of the letters in your input line above (upper to
//    lowercase and vice-versa).
// 2) Replace any whitespace with a dot ('.').
// Print the converted text.
// ***********************************************************************

	//what i added:
	string line3;
	line3 = line + line2;// added to print

	cout << "\nOriginal: " << line3 << endl; //prints original string
	for(auto &c : line3){ //for every character in line3
		if(isspace(c)){ //if whitespace replace with a '.'
			c = '.';
		}
		else{
			c = toupper(c); //changes from lower to upper
		}
	}

	cout << "Upper: " << line3 << endl; //print the new string

	for(auto &c : line3){ //for every character in line3
		if(isspace(c)){ //if whitespace replace with a '.'
			c = '.';
		}
		else{
			c = tolower(c); //changes from upper to lower
		}
	}

	cout << "Lower: " << line3 << endl; //print the new string

	return 0;
}
