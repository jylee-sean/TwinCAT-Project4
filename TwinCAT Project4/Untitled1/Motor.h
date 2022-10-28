#pragma once


#include "UserInterface.h"
#include <vector>

class CModule;


class Motor
{

private:
	const static  UINT8 m_mode = 1;
	UINT16 m_status_word;
	long m_deceleration;
	long m_acceleration;
	long m_velocity;
	long m_current_position;
	long m_target_position;
	int m_command;


public:

	typedef bool (CModule1::*fp)(void);
	//bool(*p)(void);
	fp* m_execute;
	fp* m_re_execute;

	Motor() : m_status_word(0x00),
		m_deceleration(6000),
		m_acceleration(5000),
		m_velocity(3000),
		//m_current_position(0),
		m_target_position(0),
		m_command(0)
	{
	}
	//void SetCommand() { m_command = 0; }
	//void SetCommand(int cmd) { m_command = cmd; };
	long GetCurrentPosition() { return m_current_position; }
	UINT8 GetMode() { return m_mode; }
	long GetAcceleration() { return m_acceleration; }
	long GetDeceleration() { return m_deceleration; }
	long GetVelocity() { return m_velocity; }

	long GetTargetPosition() { return m_target_position; }


	void SetTargetPosition(long val) { m_target_position = val; }

	int GetCommand() { return m_command;  }


	void update(Module1DataArea3 data) {
		//data.command;
		this->m_target_position = data.target_position;
	}
};

