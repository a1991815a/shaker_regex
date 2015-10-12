#ifndef __SHAKER_TIMER__
#define __SHAKER_TIMER__
#include "shaker_define.h"
#include <time.h>

SHAKER_NS_START;

class progess_timer{
public:
	progess_timer();
	progess_timer(int id);
	~progess_timer();

	
private:
	clock_t m_lTime;
	int m_iId;
};

class timer {
public:
	timer();
	void reset();
	double elapsed() const;
	double elapsed_min() const;
	double elapsed_max() const;
private:
	clock_t		m_start_time;
};
SHAKER_NS_END;
#endif