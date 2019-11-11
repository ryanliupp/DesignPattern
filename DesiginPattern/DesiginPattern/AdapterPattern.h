#ifndef ADAPTERPATTERN
#define ADAPTERPATTERN
#include <iostream>

struct AdvanceMediaPlay
{
	virtual void playVlc(string playtype) = 0;
	virtual void playMp4(string playtype) = 0;
	virtual ~AdvanceMediaPlay(){};
};

struct vlcMediaPlay :public AdvanceMediaPlay
{
	void playVlc(string playtype)
	{
		cout << "only play vlc " << endl; 
	};
	void playMp4(string playtype)
	{
		cout << "error type" << endl; 
	};
};
struct mp4MediaPlay :public AdvanceMediaPlay
{
	void playMp4(string playtype)
	{
		cout << "only play mp4" << endl; 
	};
	void playVlc(string playtype)
	{ 
		cout << "error type" << endl; 
	};
};

struct MediaPlay
{
	virtual void play(string playtype) = 0;
	virtual ~MediaPlay(){};

};

struct AudioPlay :public MediaPlay
{
	void play(string playtype){ cout << "only play audio"<<endl; };
};
struct HumanPlayer
{
	void play(MediaPlay* audioplay, string type){ audioplay->play(type); };

};
struct MediaAdapter :public MediaPlay
{
	AdvanceMediaPlay* playadvanced;
	MediaAdapter(AdvanceMediaPlay* playtemp)
	{
		playadvanced = playtemp;
	}
	void changeAdapater(AdvanceMediaPlay* playtemp)
	{
		playadvanced = playtemp;
	}
	void play(string playtype)
	{
		if (playtype == "vlc")
			playadvanced->playVlc(playtype);
		else if (playtype == "mp4")
			playadvanced->playMp4(playtype);
		else
			cout << "error type" << endl;
	}

};

#endif