#pragma once
#include <vector>


class Motor
{

private:

	const static  UINT8 m_mode = 1;
	UINT16 m_status_word;  
	long m_deceleration;
	long m_acceleration;
	long m_velocity;
	long m_current_position;

public:
	Motor() : m_status_word(0x00),
			  m_deceleration(6000),
			  m_acceleration(5000),
			  m_velocity(3000),
			  m_current_position(0){}

	
	void UpdateCurrentPosition(long position) { m_current_position = position; };

	long GetCurrentPosition() { return m_current_position; }
	UINT8 GetMode() { return m_mode; }
	long GetAcceleration() {return m_acceleration;}
	long GetDeceleration() { return m_deceleration; }
	long GetVelocity() { return m_velocity; }

};
