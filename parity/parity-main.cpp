/** L05: Parity
: Liberty Mupotsa 
: username(s): mupotsal
Purpose: To use arrays, classes, and to learn some things about binary.

Acknowledgements:
Modified from original code written by Dr. Jan Pearce
*/

#include <iostream>
using namespace std;

class Parity {
public:
	Parity() {} //default constructor sets all member variables.

	Parity(bool tempbyte[8]) {
		for (int i = 0; i < bytelen; i++) {
			byte[i] = tempbyte[i];
		}
	}

	void set_byte() { //mutator method sets byte from keyboard

		bool readbit;

		for (int i = 0; i < bytelen; i++) {
			cout << "Please enter bit " << i << ": ";
			cin >> readbit;
			byte[i] = readbit;
		}

		cout << endl;
		return;
	}

	void show_byte() {

		for (int i = 0; i < bytelen; i++) {
			cout << byte[i];
		}
		return;
	}
	
	bool is_odd() { // This is used to check if the array is odd, returns true if the array is odd and false if the array is odd
		sum_byte = 0;
		for (int i = 0; i < bytelen; i++) {
			if (byte[i] == 1) {
				sum_byte += 1;
		     }
			else  {
				sum_byte += 0;
			}						
		}
		if (sum_byte % 2 == 0) {
			return true;
		}
		else {
			return false;
		}

	}

	void set_even() { // This method sets the given array to even parity
		sum_svbyte = 0;
		for (int i = 0; i < bytelen-1; i++) {
			if (byte[i] == 1) {
				sum_svbyte += 1;
			}
			else {
				sum_byte += 0;
			}
		}
		if (sum_svbyte % 2 == 0) {
			byte[7] = 0;
		}
		else {
			byte[7] = 1;
		}
		for (int i = 0; i < bytelen; i++) {
			cout << byte[i];
		}
		return;
	}

void set_odd() {  // This is used to set the array to odd parity
	sum_svbyte = 0;
	for (int i = 0; i < bytelen - 1; i++) {
		if (byte[i] == 1) {
			sum_svbyte += 1;
		}
		else {
			sum_byte += 0;
		}
	}
	if (sum_svbyte % 2 == 0) {
		byte[7] = 1;
	}
	else {
		byte[7] = 0;
	}
	for (int i = 0; i < bytelen; i++) {
		cout << byte[i];
	}
	return;
}
	
void flip() {
	for (int i = 0; i < bytelen; i++) {
		if (byte[i] == 1) {
			byte[i] = 0;
			cout << byte[i];
		}
		else {
			byte[i] = 1;
			cout << byte[i];
		}
		//return byte; if you want the value but do not want to see it one just uncomment this
	}
	/*for (int i = 0; i < bytelen; i++) { //  put this to test if my method is working
		cout << byte[i];

	}*/
}

// The following returns a byte to the main.
bool* byte_array() {

	bool static bit_array[8];
	for (int i = 0; i < bytelen; i++) {	 
		byte[i] = bit_array[i];	
	}
	return bit_array;
}

// The function masks the given byte
void  masking(bool maskbyte[]) {
	for (int i=0;i < bytelen; i++)
		if (byte[i] && maskbyte[i] == 1) {
			 byte[i] = true;
			cout << byte[i];
		}
		else {
			byte[i] = 0;
			cout << byte[i];
		}
	
	return;

}
 
friend ostream& operator <<(ostream& stream,  Parity& par);

private:
	bool byte[8] = { false }; //This initializes all of the bits
	const int bytelen = 8;
	int sum_byte = 0;
	int sum_svbyte = 0;
	

}; 

ostream& operator <<(ostream& stream, Parity& parval) {
	parval.show_byte(); 
	
	return stream;
}





int main() {

	bool truebyte[8] = { true, true, true, true, true, true, true, true}; // this style of initalization only works at compile time
	int readchar = 'Y';

	cout << "Welcome to the parity class Have fun!\n" << endl; //FIXME: Feel free to change this!

	Parity testbyte;
	Parity mybyte(truebyte);  // uses contructor that sets byte using parameter	
	

	testbyte.set_byte();
	cout << "Here is the byte you entered: ";
	testbyte.show_byte();

	cout << "   " << endl;
	cout << "Is mybyte_odd__ " << mybyte.is_odd() << endl;
	cout << "Is testbyte odd__" << testbyte.is_odd() << endl;


	bool maskbyte[8] = { true, true, true, true, false, true, true, true};
	cout << "        " << endl;
	cout << "This is the masked byte(makebyte masked with the entered byte)" << endl;	testbyte.masking(maskbyte);
	cout << "        " << endl;
	cout << "        " << endl;
	
	//cout << endl;
	cout << "Mybyte flipped" << endl;
	mybyte.flip();
	


	cout <<"This is the testbyte printed ussing << operator "<<testbyte << endl;// overloaded the << operator to print  the byte using <<


	


	
	// Testing set even and is working
	cout << "        " << endl;
	
	testbyte.set_even();
	cout << "The testbyte is set to even below " << endl;
	
	cout << "        " << endl;
	cout << "mybyte set even" << endl;
	mybyte.set_even();
	
	cout << "        " << endl;
	cout << "        " << endl;
	cout << "The twstbyte is set to odd below " << endl;
	testbyte.set_odd();
	cout << "The mybyte is set to odd below " << endl;
	mybyte.set_odd();

	cout << "This is the printed one" << endl;
	cout  << testbyte<< endl;
	

	cout << "Flip the array" << endl;
	//testbyte.flip();
	//mybyte.flip();

	bool *get_array; // using pointers to  get the array values stored
	cout << "The following is the byte returned " << endl;
	get_array = mybyte.byte_array();
	
	
	
	//cout << tbyte << endl;
	cout << endl;
	

	


	cin >> readchar; //This is to keep screen open in some situations.

	return 0;
}

