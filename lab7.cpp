//============================================================================
// Name        : lab7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <vector>
using namespace std;

void usage(); //not related to the object so separate function

class Signal{ //defining object
	public:
		//declares three constructors
		Signal();
		Signal(int);
		Signal(string);
		void Sig_info(); //prints info
		void Save_file(string); //saves info to new file
		void operator+(double); //member operator
		void operator*(double); //member operator
		void statistics();
		void normalize();
		void center();
		void print_sigd();
		//had to be made public:
		int length;
		double maximum_value;
		double average;
		vector <double> signal_data; //made into a vector
		void average_calc();
		double act_max(); //finds max found in the signal_data
};

Signal operator+(Signal &ob1,Signal &ob2); //declares non-member function

void Signal::print_sigd(){
	for(auto i:signal_data){
		cout << i << "\n"; //test
	}
	return;
}

Signal::Signal(){
	//initializes values to zero
	length = 0;
	maximum_value = 0;
	average = 0;
}

Signal::Signal(int fileNumber){
	//initializes variables to zero
	length = 0;
	maximum_value = 0;
	average = 0;
	double val;

	ifstream file; //creates file object
	string pt1; //initializes string part 1
	string pt2;
	string pt3 = ".txt";
	string name; //changed to string

	if(fileNumber>0 && fileNumber <10){
		pt2 = to_string(fileNumber); //converts num to string
		pt1 = "Raw_data_0";
	}

	if(fileNumber>9 && fileNumber <15){
		pt2 = to_string(fileNumber); //converts num to string
		pt1 = "Raw_data_";
	}

	name = (pt1 + pt2 + pt3); //adds all parts together to make correct file name

	file.open(name, ios::in); //opens designated file

	if(!(file.is_open())){ //if file doesnt open then print error and show usage
			cout << "\nError opening file.\n" << endl;
			usage();
			exit(0); //exit if file couldn't be opened
	}

	file >> length >> maximum_value; //read in length and max from the file

	while(file >> val){ //read in the numbers from the file
		signal_data.push_back(val); //appends double to the end of vector
	}

	file.close(); //closes the file
}

Signal::Signal(string fileName){
	//initializes variables to zero
	length = 0;
	maximum_value = 0;
	average = 0;
	double val;

	ifstream file; //creates file object

	file.open(fileName, ios::in); //opens designated file

	if(!(file.is_open())){ //if file doesn't open print error
		cout << "\nError opening file.\n" << endl;
		usage();
		exit(0); //exit if file couldn't be opened
	}

	file >> length >> maximum_value; //read in length and max from the file

	while(file >> val){ //read in the numbers from the file
		signal_data.push_back(val); //appends double to end of vector
	}

	file.close(); //closes the file
}

int main(int argc, char *argv[]) {
	//initialize variables
	int x=1;
	int y=1;
	int num=0;
	int flag=0;
	int flag1=0;
	int flag3=0;
	int choice=0;
	double off2=0;
	double sca2=0;
	Signal *sig=NULL; //pointer of type Signal

	//scans through entire command line looking for -n
	while(y < argc && flag == 0){
		if((argv[y][0] == '-') && (argv[y][1] == 'n')){ //compares to -n
			num=0;

			if((y+1) >= argc){ // if no number is entered after -n
				cout << "\nError. Not enough information." << endl; //print error
				usage(); //shows usage
			}

			num = atoi(argv[y+1]); // converts character to integer

			if(num<1 || num>14){ //checks if a number option
				usage();
			}
			else{ //if in range
				//assigns address to Signal pointer
				sig = new Signal(num); //calls constructor with int parameter
				flag = 1; //file is found and opened

			}

			y++; //increments past y+1 because it's already found and used
		}
		else if((argv[y][0] == '-') && (argv[y][1] == 'f')){ //compares to -f
			string nam;

			if((y+1) >= argc){ // if no number is entered after -n
				cout << "\nError. Not enough information." << endl; //print error
				usage(); //shows usage
			}

			string p1 = argv[y+1]; //assigns command line arguement to string pt 1
			string p2 = ".txt";

			nam = (p1 + p2); //add strings to make filename

			//assigns address to Signal pointer
			sig = new Signal(nam); //calls constructor with char* parameter
			flag = 1; //file is found and opened
			y++; //increments past y+1 because it's found
		}
		y++; //increments through the argv elements
	}

	if(flag != 1){ //-n/-f are not found, so use default
		//assigns address to Signal pointer
		sig = new Signal(); //default constructor
		usage();
	}

	while(x < argc){ //looks for other command line arguments

		if((argv[x][0] == '-') && (argv[x][1] == 'n')){
			x++; //if found, skip because file has already been opened before
		}
		else if((argv[x][0] == '-') && (argv[x][1] == 'f')){
			x++; //if found, skip because file has already been opened
		}
		else if((argv[x][0] == '-') && (argv[x][1] == 'o')){
			flag1=1; //-o found
			//initializes variables
			int num1;
			double off=0;

			if((x+1) >= argc){ //checks if there is an argument entered after the -o
				cout << "\nError. Not enough information.\n" << endl;
				usage(); //shows valid command-line arguments
			}

			num1 = sscanf(argv[x+1], "%lf", &off); //checks if offset contains characters

			if(num1==0){  //if yes, print error
				cout << "\nError.\n" << endl;
				usage();
			}

			sig->operator+(off); //calls offset method through the Signal pointer

			x++; //already found the next element
		}
		else if((argv[x][0] == '-') && (argv[x][1] == 's')){
			flag1 = 1; //-s found
			//initializes variables
			int num2;
			double sca=0;

			if((x+1) >= argc){ //prints usage if there is no argument after -s
				cout << "\nError. Not enough information.\n" << endl;
				usage();
			}

			num2 = sscanf(argv[x+1], "%lf", &sca); //checks if number contains characters

			if(num2==0){ //if yes, print error
				cout << "\nError.\n" << endl;
				usage();
			}

			sig->operator*(sca); //calls scale method through Signal pointer

			x++; //increments past next element
		}
		else if((argv[x][0] == '-') && (argv[x][1] == 'S')){
			flag1 = 1; //-S found

			sig->statistics(); //calls statistics method
		}
		else if((argv[x][0] == '-') && (argv[x][1] == 'C')){
			flag1 = 1; //-C found

			sig->center(); //calling center method
		}
		else if((argv[x][0] == '-') && (argv[x][1] == 'N')){
			flag1 = 1; //-N found

			sig->normalize(); //calls normalize method
		}

		x++; //increments to next command-line argument
	}

	int flagg=0;
	if(flag1 != 1){ //if no command-line arguments found for methods
		while(flagg!=1){
			do{
				cout << "Options: \n" << "1) Offset\n" << "2) Scale\n"
					 << "3) Center\n" << "4) Normalize\n" << "5) Statistics\n"
					 << "6)Done" << endl;

				cout << "Please enter the number of your choice above: ";
				cin >> choice; //user selects option

				if(choice == 6){
					flagg=1;
				}

				if(choice<1 || choice>6){
					flag3 = 0; //keep looping
				}
				else{
					flag3 = 1; //breaks loop
				}


			}while(flag3 != 1); //keep asking for valid option


		switch(choice){
			case 1:
				cout << "\nPlease enter the offset number: ";
				cin >> off2; //gets offset from user input
				cout << endl;
				sig->operator+(off2); //calls offset method
				break;
			case 2:
				cout << "\nPlease enter the scale number: ";
				cin >> sca2; //gets scale from user
				cout << endl;
				sig->operator*(sca2); //calls scale method
				break;
			case 3:
				sig->center(); //calling center method
				break;
			case 4:
				sig->normalize(); //calls normalize method
				break;
			case 5:
				sig->statistics(); //calls statistics method
				break;
		}//end of switch
	}//end of flag != 1
	}

	string filenam = "NewFile.txt"; //file name to create in Save_file

	sig->Sig_info(); //prints length, max, and average
	sig->Save_file(filenam); //creates a new file

	//operator with two Signal inputs:
	//initializes variables
	int choice1=0;
	int choice2=0;

	cout << "\nPlease enter the number of the file you want to open for the first object: "
		 << endl;

	cin >> choice1; //asks for first file number

	if(choice1<1 || choice1>14){ //checks if a number option
		usage();
	}
	 //if in range
	//assigns address to Signal pointer
	Signal sig1(choice1); //calls constructor with int parameter


	cout << "\nPlease enter the number of the file you want to open for the second object: "
		 << endl;

	cin >> choice2; //asks for first file number

	if(choice2<1 || choice2>14){ //checks if a number option
		usage();
	}
	//if in range
	//assigns address to Signal pointer
	Signal sig2(choice2); //calls constructor with int parameter

	Signal sig3;

	sig3 = operator+(sig1, sig2); //calls non-member addition operator
	sig3.Sig_info(); //prints members
	sig3.print_sigd();//prints sum signal data

	return 0;
}

Signal operator+(Signal &ob1,Signal &ob2){
	Signal sum;
	int i=0;
	double max1=0;
	double max2=0;

	cout<< "test";

	if(ob1.length != ob2.length){ //makes sure same length
		cout << "\nError. Only objects of same length can be added." << endl;
		exit(0);
	}

	for(i=0; i<ob1.length;i++){ //either length b/c same length
		sum.signal_data[i] = (ob1.signal_data[i] + ob2.signal_data[i]);//element wise addition
	}

	max1 = ob1.act_max(); //finds the max of object 1
	max2 = ob2.act_max(); //finds the max of object 2

	if(max1>max2){
		sum.maximum_value = max1; //if max1 is max of both objects
	}
	else{
		sum.maximum_value = max2; //if greater or equal, then max of both
	}

	sum.average_calc(); //calculates average of new signal_data


	return sum;
}

void Signal::Sig_info(){ //prints length, max, and average
	cout << "Length: " << length << endl << "Current maximum value: "
		 << maximum_value << endl << "Current average: " << average << "\n  \n";
	return;
}

void Signal::Save_file(string newFilename){
	ofstream file; //creates file to write to
	file.open(newFilename); //creates new file

	if(!(file.is_open())){ //if not opened
		cout << "\nCannot open file." << endl;
		usage();
		exit(0); //exits if file isn't opened
	}

	file << length << " " << (double) maximum_value << "\n"; //prints the length and offset/scale

	for(auto i:signal_data){
		file << (double) i << "\n"; //prints signal_data to new file
	}

	file.close(); //closes file
	return;
}

void Signal::operator+(double off){
	for(auto &i:signal_data){ //use i as reference
		i = (double) (i + off); //adds offset to array of numbers
	}

	maximum_value = (double) act_max(); //finds the max in signal_data
	average_calc(); //calls average so it can be printed in Sig_info

	return;
}

void Signal::operator*(double sca){
	for(auto &i:signal_data){ //use i as reference
		i = (double) (i * sca); //creates the array of scaled numbers
	}

	maximum_value = (double) act_max(); //finds the max of singal_data
	average_calc(); //calls average so it can be printed in Sig_info

	return;
}

void usage(void){ //prints proper format of command-line arguments
	cout << "\nUsage:"
	     << "\n\t-n <Valid file number>           \tSelects the file to open."
		 << "\n\t-n                               \tOpens a default file."
		 << "\n\t-f <Valid file name>             \tOpens the specified file."
	     << "\n\t-o <Offset value>                \tOffsets the file numbers by the given value."
	     << "\n\t-s <scale factor value>          \tScales the file numbers by the given value."
	     << "\n\t-S                               \tShows statistics."
	     << "\n\t-C                               \tCenters the signal."
	     << "\n\t-N                               \tNormalizes the signal.\n"
	     << "\nExamples:\n   ./lab7 -n 2 - s 6.7\n   ./lab7 -C -n 4\n\n" << endl;
	exit(0); //quits program
}

double Signal::act_max(void){
	double actual_max=0;

	actual_max = (double) signal_data[0]; //makes initial max the first number in the array

	for(auto i:signal_data){
		if((double) i>actual_max){ //compares each number to the max
			actual_max = (double) i; //if larger, then make it the max
		}
	}

	return actual_max;
}

void Signal::average_calc(void){
	double sum=0;

	for(auto i:signal_data){
		sum += (double) i; //adds all the numbers in the array together
	}

	average = (double) sum / length; //divides sum by the amount of numbers in the array

	return;
}

void Signal::statistics(void){
	maximum_value = (double) act_max(); //finds the maximum
	average_calc(); //determines the average of the array
}

void Signal::normalize(){
	double new_max;

	new_max = ((double) 1 / (double) maximum_value); //scale it by dividing by the max
	operator*(new_max); //scales existing array

	maximum_value = (double) act_max(); //finds the max of signal_data
	average_calc(); //calls average so it can be printed in Sig_info

	return;
}

void Signal::center(){
	average_calc(); //finds the average of the numbers
	average *= (-1); //so it can be subtracted in the operator+
	operator+(average); //assigns to vector in operator+ function

	maximum_value = (double) act_max(); //finds the max of the signal_data
	average_calc(); //finds average to print in Sig_info

	return;
}

