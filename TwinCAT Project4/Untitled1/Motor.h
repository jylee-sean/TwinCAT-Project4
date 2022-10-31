#pragma once


#include "UserInterface.h"
#include <vector>

class CModule1;


class Motor
{

private:
	const static  UINT8 m_mode = 1;
	UINT16 m_status_word;
	long m_deceleration;
	long m_acceleration;
	long m_velocity;
	long m_target_position;
	int m_command;

protected:

public:
	typedef bool (CModule1::*fp)(Motor&);
	int m_num;
	int m_timeout_count;

	//bool(*p)(void);
	fp* m_execute;
	fp* m_re_execute;

	Motor() : m_status_word(0x00),
		m_deceleration(6000),
		m_acceleration(5000),
		m_velocity(3000),
		m_target_position(0),
		m_command(0),
		m_timeout_count(0),
		m_num(0){}

	UINT8 GetMode() { return m_mode; }

	long GetAcceleration() { return m_acceleration; }
	long GetDeceleration() { return m_deceleration; }
	long GetVelocity() { return m_velocity; }
	long GetTargetPosition() { return m_target_position; }
	int  GetCommand() { return m_command; }

	void SetNum(int num) { this->m_num = num; }
	void SetTargetPosition(long val) { m_target_position = val; }
	void SetCommand(int cmd) { m_command = cmd; };


	void update(Module1DataArea3 data) {

		m_command = data.command[m_num];
		m_target_position = data.target_position[m_num];
		//data.command;
		//this->m_target_position = data.target_position;
	}
};

