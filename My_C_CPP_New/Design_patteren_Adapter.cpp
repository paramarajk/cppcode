/*
Let us suppose we have an old player which plays songs. 
It has a method called OldPlay which takes the volume at which the song has to be played as a parameter.
The new interface which we have has a play method too. But that method does not take the volume as a parameter. 
So lets put Adapter design pattern in action.
*/

#include <iostream>
#include <string>
using namespace std;

class Iplayer {
public:
	Iplayer() { cout << "Iplayer : ctor" << endl; }
	virtual void play() = 0;
	virtual ~Iplayer() { cout << "Iplayer : dtor" << endl; }
};

class Oldplayer {
	string song;
public:
	Oldplayer(string _song) : song(_song) {
		cout << "Oldplayer : ctor" << endl;
	}
	void old_play(int volume) {
		cout << "Song : " << song << " : Played at voulme : " << volume << endl;
	}
	~Oldplayer() {
		cout << "Oldplayer : dtor" << endl;
	}
};

class Adapter : public Iplayer, private Oldplayer {
	int volume;
public:
	Adapter(string _song, int _volume) : volume(_volume), Oldplayer(_song) {
		cout << "Adapter : ctor" << endl;
	}

	void play() { //calling from Iplayer
		old_play(volume); // calling from Oldplayer
	}

	~Adapter() {
		cout << "Adapter : dtor" << endl;
	}
};

int main() {
	Iplayer* a = new Adapter("Good Ole Boy Like Me", 50);
	a->play();
	delete a;

	return 0;
}