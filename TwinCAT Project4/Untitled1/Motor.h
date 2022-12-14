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
	enum cmd {
		cmd_off = 0, 
		cmd_on=1,    
		cmd_set=2,   

	};
	enum st {
		st_switch_on_disabled = 1,    
		st_ready_to_switch_on = 2,    
		st_switch_on = 3,             
		st_operation_enabled = 4,    
		st_set_point = 5,             
		st_target_reached = 6,        
		st_quick_stop_active = 7,     
		st_fault = 8,                 
		st_fault_reaction_active = 9, 
		st_moving = 0                 
	};

	enum key {

		setDisabled = 81,
		faultReset = 82,


		Disabled = 11,

		setShutdown = 311,
		setSwitchOn = 321,
		setEnabled = 331,
		Enabled = 141,
		setPosition = 241,
		setPoint = 242,
		tgtReached = 261,
		moving = 201,
		clearPoint = 202,
		quickstop = 441,
	};
public:
	typedef bool (CModule1::*fp)(Motor&);
	int m_num;
	int m_timeout_count;

	int m_key;
	int m_state;
	bool m_target_position_changed;

	Motor() : 
		m_deceleration(6000),
		m_acceleration(5000),
		m_velocity(3000),
		m_target_position(0),
		m_current_position(0),
		m_command(0),
		m_timeout_count(0),
		m_num(0),
		m_target_position_changed(false),
		m_key(0){}

	UINT8 GetMode() { return m_mode; }

	long GetAcceleration() { return m_acceleration; }
	long GetDeceleration() { return m_deceleration; }
	long GetVelocity() { return m_velocity; }
	long GetTargetPosition() { return m_target_position; }
	long GetCurrentPosition() { return m_current_position; }
	int  GetCommand() { return m_command; }

	void SetNum(int num) { this->m_num = num; }


	void SetTargetPosition(long val) 
	{
		if (m_target_position != val) {
			m_target_position_changed = true;
			m_target_position = val;
		}
	}
	void SetCommand(int cmd) { m_command = cmd; };
	void SetCurrentPosition() { m_current_position = m_target_position;  };
	void SetState(int state) { m_state = state; };

	int GetKey() {

		
		/* fault sequence & set postion sequence */
		if (m_key == key::setDisabled || m_key == key::setPosition) {
			m_key += 1;
			return m_key;
		}
		/* target positon chagned while moving */
		else if (m_key == moving && m_target_position_changed) {
			m_key += 1;
			m_target_position_changed = false;
			return m_key;
		}
		
		if (m_state == st::st_fault) {
			m_key = key::setDisabled;
			return m_key;
		}


		if (m_command == cmd::cmd_off) {
			m_key = key::setDisabled;
			return m_key;
		}
		else if ( (m_command == cmd::cmd_on || m_command == cmd::cmd_set) && m_state <  st::st_operation_enabled) {
			m_key = 3 * 100 + m_state * 10 + 1;
			return m_key;
		}


		m_key = m_command * 100 + m_state * 10 + 1;
		return m_key;
	}

	void SetKey(int key) {
		m_key = key;
	}

	void update(Module1DataArea3 data ) {

		this->SetCommand(data.command[m_num]);
		this->SetTargetPosition(data.target_position[m_num]);
	}
};

