#include "shaker_timer.h"
#include "shaker_debug.h"

SHAKER_NS_START;

progess_timer::progess_timer()
{
	m_lTime = clock();
	m_iId = INT_MIN;
}

progess_timer::progess_timer(int id)
{
	m_lTime = clock();
	m_iId = id;
}

progess_timer::~progess_timer()
{
	if (m_iId != INT_MIN)
		SHAKER_DEBUG("progess_timer: id= %d, time= %f;", m_iId,
			double(clock() - m_lTime) / double(CLOCKS_PER_SEC));
	else
		SHAKER_DEBUG("progess_timer: time= %f;",
			double(clock() - m_lTime) / double(CLOCKS_PER_SEC));
}


timer::timer()
{
	m_start_time = clock();
}

void timer::reset()
{
	m_start_time = clock();
}

double timer::elapsed() const
{
	return double(clock() - m_start_time) / double(CLOCKS_PER_SEC);
}

double timer::elapsed_min() const
{
	return double(1) / double(CLOCKS_PER_SEC);
}

double timer::elapsed_max() const
{
	return (double(std::numeric_limits<clock_t>::max()) -
		double(m_start_time)) / double(CLOCKS_PER_SEC);
}


SHAKER_NS_END;