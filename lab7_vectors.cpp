//============================================================================
// Name        : lab7_vectors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Lab7_vectors.cpp
// This program shows some simple vector examples, and asks for simple tasks.
// Reference: Lippman, section 3.3

// Author: Luis Rivera

// IMPORTANT NOTE: YOU MAY NEED TO COMPILE ADDING THE FOLLOWING FLAG: -std=c++11
//                 OR: -std=c++0x
// Example:  g++ Lab7_vectors.cpp -o Lab7_vectors -std=c++11
//      or:  g++ Lab7_vectors.cpp -o Lab7_vectors -std=c++0x
// Some initialization methods and other things are not supported by the old standard.

#include <iostream>
#include <vector>

using namespace std;

// Main function. Shows a few examples. Complete the assignments stated in the comments.
int main()
{
	vector<int> ivec1(5), ivec2;
	vector<double> dvec1{5.1}, dvec2(5,1.5);
	vector<string> svec1 = {"hello", "world"};
	// vector<myClass> myCvec;	// you can have vectors of objects
	// in general: vector<Type> vec;	// vector is a template

	for(int i = 0; i < ivec1.size(); i++)
		cout << ivec1[i] << "\n";// << endl; //i had to comment the endl out because compile error
	cout << "\n------------------------------------------------------------------" << endl;

	for(auto i:ivec1)	// This is equivalent to the above for loop
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;

	for(auto i:dvec1)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;

	for(auto i:dvec2)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;

	for(auto i:svec1)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;

	cout << "Original size: " << ivec2.size() << endl;
	ivec2.push_back(50);
	cout << "New size: " << ivec2.size() << "\nAdded element: " << ivec2[0] << endl;
	cout << "\n------------------------------------------------------------------" << endl;

// ***********************************************************************
// Try all the ways to initializa a vector shown in Table 3.4. Use the
// vectors above and/or declare new vectors.
// Some of those operations have already been used, but write your
// own examples.

// Do exercises 3.14 and 3.15 from Lippman (page 102)

// Try all the vector operations shown in table 3.5. Use the vectors above
// or define new ones. Try different types.
// ***********************************************************************

	//TABLE 3.4:

	vector <int> v1; //vector holds objects of type int
	vector <int> v2(v1); //v2 has a copy of each element in v1
	vector <int> v3 = v1; //same as v2
	vector <int> v4(5, 2); //v4 has 5 copies of value 2
	vector <int> v5(3); //has 3 copies of value-initialized object
	vector <int> v6{1,2,3,4}; //initialized values
	vector <int> v7 = {1,2,3,4}; //same as v6

//exercise 3.14:
//write a program to read a sequence of ints from cin and store those values in a vector
	cout << "\n***Exercise 3.14***" << endl;
	int x; //initializes int
	vector <int> test_vec; //declares empty vector
	cout << "\nPlease enter an integer: ";
	while(cin>>x){ //while the user keeps entering numbers
		cout << "\nPlease enter an integer: ";
		test_vec.push_back(x); // appends the integer to the vector
	}
	cin.clear();
	cin.ignore();
	cout << endl;

	//prints vector to show if worked properly:
	int i=0;
	while(test_vec[i]){
		cout << test_vec[i] << "\n";
		i++;
	}

//exercise 3.15
//repeat previous program but read strings this time
	cout << "\n***Exercise 3.15***" << endl;
	int count=0; //counter
	string s; //initializes string
	//string comp =
	vector <string> test_vec2; //declares empty vector

	cout << "\nPlease enter a word or '&' to stop: ";

	while(cin>>s && (s != "&")){ //while the user keeps entering words
		cout << "\nPlease enter a word or '&' to stop: ";
		test_vec2.push_back(s); // appends the string to the vector
		count++;
	}
	cin.clear();
	cin.ignore();
	cout << endl;

	//prints vector to show if worked properly:
	int k=0;
	while(k<count){
		cout << test_vec2[k] << "\n";
		k++;
	}

//TABLE 3.5:

	if(v1.empty()){ //should be true
		cout << "\nV1 is empty" << endl;
	}

	int size;
	size = v6.size(); //size should be 4
	cout << size << endl;

	v1.push_back(10);//adds element with value 10 to end of v1

	cout << v7[2] << "\n"; //should be 3

	v5 = v4;//replaces the elements in v5 with a copy of elements in v4
	if(v5==v4){ //should be true
		cout << "\nv5 = v4\n";
	}

	v1 = {4,5,6}; //assigns new values to v1

	if(v7<v1){ //should be true
		cout << "v7 < v1\n";
	}
	if(v7<=v1){//should be true
		cout << "v7 <= v1\n";
	}

	vector <string> vs_test{"hello", "world"}; //initializes a test string vector
	vector <string> vs_test2 = {"helloworld"}; //initializes second test string

	if(vs_test2>vs_test){ //should pass
		cout << "vs_test2 > vs_test\n";
	}
	if(vs_test2>=vs_test){//should pass
		cout << "vs_test2 >= vs_test\n";
	}

	return 0;
}
