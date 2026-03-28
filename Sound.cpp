#include <iostream>
#include <cstring>
#include "wavfile.h"
using namespace std;


void playfile(char* str) {
	if (playWavFile(str) == 0)
		cout << "Error: File not found!" << endl;
}

//Sample function for reading and storing sound data
void read_data(char* str) {
	
		int sampleRate = 0, size = 100000;
		unsigned char* ptr = new unsigned char[size];
		readWavFile(str, ptr, size, sampleRate);
		delete[] ptr;
	
}
