#pragma once
#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <windows.h>
#include <irrKlang.h>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <thread>
#pragma comment(lib, "irrKlang.lib")

using namespace irrklang;
using namespace std;

static const char* SOUND[17] = {
	"",
	"./data/LowDo.wav",
	"./data/LowLe.wav",
	"./data/LowMi.wav",
	"./data/LowFa.wav",
	"./data/LowSol.wav",
	"./data/LowLa.wav",
	"./data/LowSi.wav",
	"./data/Do.wav",
	"./data/Le.wav",
	"./data/Mi.wav",
	"./data/Fa.wav",
	"./data/Sol.wav",
	"./data/La.wav",
	"./data/Si.wav",
	"./data/Kick.wav",
	"./data/Snare.wav"
};

class Music {
private:
	ISoundEngine* music;
	vector<vector<int> > note;
	int nesting;
	int bpm;
	bool playing;
	double beat;
	bool optionSoundErase;
	void note_push(vector<int>& note, int sound);

public:
	Music(int nesting = 2, double bpm = 120, bool option1 = false);
	void music_start();
	void music_stop() { playing = false; }
	void bpm_changer(double bpm) { this->bpm = bpm; }
	void note_adder(int length);
	void note_adder(vector<int> note, int startPoint);
	void note_clear();
	double get_bpm() { return this->bpm; }
	~Music() { music->drop(); }
};

#endif