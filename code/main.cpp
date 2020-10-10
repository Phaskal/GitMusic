#include "music.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <irrKlang.h>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <thread>

using namespace irrklang;
using namespace std;

#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll


int main(int argc, const char** argv) {
	// start the sound engine with default parameters
	Music music = Music();
	system("cls");

	cout << "Now Playing~" << endl;
	cout.flush();

	ifstream partA("part_A.txt");
	cout << "part A" << endl;
	for (int line = 0; line < 2; line++)
	{
		vector<int> note;
		for (int i = 0; i < 8; i++)
		{
			int temp;
			partA >> temp;
			cout << temp << " ";
			note.push_back(temp);
		}
		music.note_adder(note, 0);
		cout << endl;
	}
	
	cout << endl;

	ifstream partB("part_B.txt");
	cout << "part B" << endl;
	for (int line = 0; line < 2; line++)
	{
		vector<int> note;
		for (int i = 0; i < 8; i++)
		{
			int temp;
			partB >> temp;
			cout << temp << " ";
			note.push_back(temp);
		}
		music.note_adder(note, 8);
		cout << endl;
	}

	cout << endl;

	ifstream partC("part_C.txt");
	cout << "part C" << endl;
	for (int line = 0; line < 2; line++)
	{
		vector<int> note;
		for (int i = 0; i < 8; i++)
		{
			int temp;
			partC >> temp;
			cout << temp << " ";
			note.push_back(temp);
		}
		music.note_adder(note, 16);
		cout << endl;
	}

	cout << endl;

	ifstream partD("part_D.txt");
	cout << "part D" << endl;
	for (int line = 0; line < 2; line++)
	{
		vector<int> note;
		for (int i = 0; i < 8; i++)
		{
			int temp;
			partD >> temp;
			cout << temp << " ";
			note.push_back(temp);
		}
		music.note_adder(note, 24);
		cout << endl;
	}

	// music thread
	thread music_thread(&Music::music_start, &music);

	// input
	while (1) {

	}

	music_thread.join();
	return 0;
}