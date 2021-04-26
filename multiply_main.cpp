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
	string mLayer;
	string layerType;

	//letting people know what the program does
	cout << "This program takes an image (that must be in the same file as the program and in .ppm format) \n"
		"and writes a new file with an added multiply layer. " << endl;
	cout << "You can input one image and one hexidecimal color code to apply a solid color multiply layer. \n"
		"Or you can input 2 .ppm files and the second one will act as the multiply layer." << endl; // actually it doesn't matter which one 
		//is on top here because the multiply blend mode is commutative

	
	while (true) {
		//get strings for the different pieces of info needed
		cout << "please enter the file name "; cin >> inFile;
		//cout << "Please enter the layer type "; cin >> layerType; 
		cout << "Please enter a hexidecimal color, or another .ppm image file name "; cin >> mLayer; cout << endl;
		

		if (mLayer.substr(mLayer.size() - 4) == ".ppm") {
			RGBImage image1(inFile);
			RGBImage image2(mLayer);
			image1.writeMultipliedPPMfile(image1, image2);
		}

		
		else {
			//get hex number for rgb
			string strr = mLayer.substr(0, 2);
			string strg = mLayer.substr(2, 2);
			string strb = mLayer.substr(4, 2);
			//convert the string hex rgb numbers to strings
			int r = stoi(strr, 0, 16);
			int g = stoi(strg, 0, 16);
			int b = stoi(strb, 0, 16);


			// read int he file and get info using the class RGBimage
			RGBImage image(inFile);

			//use member function to write the new image
			image.writeMultipliedPPMfileSolid(inFile, r, g, b);
			
		}
	}
	
	return 0;
}