/* ??CURRENTLY ONLY DOES MULTIPLY SO FAR
* 
* main for my project which
* uses a basic user interface to 
* get information, and then call various
* member functions for the class RGBImage
* defined in the included header and source file below
*/

//this is the file path in my commputer, but you will
//probably need to change it in yours
#include "C:\Users\magic\source\repos\CS201_HW8\image.h"
#include "C:\Users\magic\source\repos\CS201_HW8\image.cpp"
#include <sstream>
using std::cin;
using std::istringstream;



int main() {
	string line;
	string inFile;
	string hexCode;
	string layerType;

	//letting people know what the program does
	cout << "This program takes an image (that must be in the same file as the program and in .ppm format) \n"
		"and writes a new file with an added multiply layer. " << endl;

	
	while (true) {
		//get strings for the different pieces of info needed
		cout << "please enter the file name "; cin >> inFile;
		//cout << "Please enter the layer type "; cin >> layerType; 
		cout << "Please enter the hexidecimal color for the layer that will be added "; cin >> hexCode; cout << endl;
		
		//get hex number for rgb
		string strr = hexCode.substr(0, 2);
		string strg = hexCode.substr(2, 2);
		string strb = hexCode.substr(4, 2);
		//convert the string hex rgb numbers to strings
		int r = stoi(strr, 0, 16);
		int g = stoi(strg, 0, 16);
		int b = stoi(strb, 0, 16);

		// read int he file and get info using the class RGBimage
		RGBImage image(inFile);
		

		//decide which member function to run, and run it
		//if (layerType == "multiply") {
			//cout << "you chose a mupltiply layer";
			image.writeMultipliedPPMfile(inFile, r, g, b);
		//}
	}
	
	return 0;
}