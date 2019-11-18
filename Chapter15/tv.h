#ifndef TV_H_
#define TV_H_

class Remote;
class Tv {
public:
	friend class Remote;
	enum { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };

	Tv(int s = Off, int mc = 125)
		: state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}
	void onoff() { state = (state == (int)On) ? (int)Off : (int)On; }
	bool ison() { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void set_input() { input = (input == TV) ? DVD : TV; }
	void settings() const;
	void set_rm_mode(Remote& r);
private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;
};

class Remote {
public:
	enum { Default, Conversational };
	friend class Tv;
	Remote(int m = Tv::TV, int rm = Default) : mode(m), rm_mode(rm) {}
	bool volup(Tv& t) { return t.volup(); }
	bool voldown(Tv& t) { return t.voldown(); }
	bool onoff(Tv& t) { t.onoff(); }
	void chanup(Tv& t) { t.chanup(); }
	void chandown(Tv& t) { t.chandown(); }
	void set_chan(Tv& t, int c) { t.channel = c; }
	void set_mode(Tv& t) { t.set_mode(); }
	void mode_setting();
private:
	int mode;
	int rm_mode;
};

inline void Tv::set_rm_mode(Remote& r) {
	if (ison())
		r.rm_mode = (r.rm_mode == Remote::Default) ? Remote::Conversational : Remote::Default;
};
#endif // !TV_H_

