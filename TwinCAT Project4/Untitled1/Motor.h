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
	long m_current_position;
	int m_command;
	


protected:

public:
	typedef bool (CModule1::*fp)(Motor&);
	int m_num;
	int m_timeout_count;
	int m_depth;

	//bool(*p)(void);
	fp* m_execute;
	fp* m_re_execute;
	int m_set_point_ack_flag;
	int m_goal;
	int m_seq;
	int m_state;
	int m_key;

	bool set_position;

	Motor() : m_status_word(0x00),
		m_deceleration(6000),
		m_acceleration(5000),
		m_velocity(3000),
		m_target_position(0),
		m_current_position(0),
		m_command(0),
		m_timeout_count(0),
		m_num(0),
		m_seq(0),
		m_goal(0),
		m_set_point_ack_flag(0),
		m_depth(1),
		set_position(false),
		m_key(0){}

	UINT8 GetMode() { return m_mode; }

	long GetAcceleration() { return m_acceleration; }
	long GetDeceleration() { return m_deceleration; }
	long GetVelocity() { return m_velocity; }
	long GetTargetPosition() { return m_target_position; }
	long GetCurrentPosition() { return m_current_position; }
	int  GetCommand() { return m_command; }

	void SetNum(int num) { this->m_num = num; }
	void SetTargetPosition(long val) { m_target_position = val; }
	void SetCommand(int cmd) { m_command = cmd; };
	void SetCurrentPosition() { m_current_position = m_target_position;  };

	int GetKey() {
		
		//fault
		if ((m_key % 100) / 10 == 8) {
			m_key += 1;
			return m_key;
		}
		else if(m_key == 241){
			m_key += 1;
			return m_key;
		}
		return 100 * m_command + 10 * m_state + 1;
	}
	void SetKey(int key) {
		m_key = key;
	}
	int GetDepth() {

		if (set_position)
			m_depth = 2;
		
		return m_depth;
	}
	
	void update(Module1DataArea3 data ) {

		m_command = data.command[m_num];
		m_target_position = data.target_position[m_num];
	
		//data.command;
		//this->m_target_position = data.target_position;
	}


};

