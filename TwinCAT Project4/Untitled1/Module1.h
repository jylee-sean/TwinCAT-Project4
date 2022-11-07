///////////////////////////////////////////////////////////////////////////////
// Module1.h
#pragma once

#include "Untitled1Interfaces.h"
#include "AdsR0.h"
#include <vector>
<<<<<<< HEAD
#include <map>
=======
>>>>>>> 1c2b7e1486d2fc25535f4f109e6d1e1477a8f50f

//#include "Motor.h"
//#include <vector>


#define CALL_MEMBER_FN(object, ptrToMember) ((object).*(ptrToMember))
// parameter ids for TwinCAT module Module1 with disabled code generation
// could be moved to Untitled1Services.h
const PTCID PID_Module1AdsPort        = 0x00000002;







class CModule1 
	: public ITComObject
	, public ITcADI
	, public ITcWatchSource
///<AutoGeneratedContent id="InheritanceList">
	, public ITcCyclic
///</AutoGeneratedContent>
	, public CAdsR0FifoPort
	, public Motor

{
public:
	DECLARE_IUNKNOWN()
DECLARE_IPERSIST(CID_Untitled1CModule1)
DECLARE_ITCOMOBJECT_LOCKOP()
DECLARE_ITCADI()
DECLARE_ITCWATCHSOURCE()
DECLARE_OBJPARAWATCH_MAP()
DECLARE_OBJDATAAREA_MAP()



CModule1();
virtual	~CModule1();




///<AutoGeneratedContent id="InterfaceMembers">
	// ITcCyclic
virtual HRESULT TCOMAPI CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context);

///</AutoGeneratedContent>

	// CAds
virtual	void	AdsReadWriteInd
(
	AmsAddr& rAddr,
	ULONG invokeId,
	ULONG indexGroup,
	ULONG indexOffset,
	ULONG cbReadLength,
	ULONG cbWriteLength,
	PVOID pData
);

virtual void AdsReadCon
(
	AmsAddr& rAddr,
	ULONG invokeId,
	ULONG result,
	ULONG cbLength,
	PVOID pData
);

enum RESULT {success = true, fail = false};

public:

protected:
	DECLARE_ITCOMOBJECT_SETSTATE();

	HRESULT AddModuleToCaller();
	VOID RemoveModuleFromCaller();
	
	// Tracing
	CTcTrace m_Trace;

	///<AutoGeneratedContent id="Members">
	TcTraceLevel m_TraceLevelMax;
	WORD m_DefaultAdsPort;
	WORD m_ContextAdsPort;
	ULONG m_Counter;
	SHORT m_move;
	LONG m_target;
	Module1Inputs m_Inputs;
	Module1Outputs m_Outputs;
	Module1DataArea3 m_DataArea3;

	ITcCyclicCallerInfoPtr m_spCyclicCaller;
	

	///</AutoGeneratedContent>

	void SubmitAdsReadReq();
	enum
	{
		invokeIdReadByOidAndPid = 1
	};
	ULONG  m_ReadByOidAndPid;
	
	std::vector<Motor> motors; 
<<<<<<< HEAD
	std::map<int, fp > trainsitionMap;
=======
>>>>>>> 1c2b7e1486d2fc25535f4f109e6d1e1477a8f50f
	static constexpr INT timeout_cnt =1000;
	fp* execute;

	fp exe;

<<<<<<< HEAD
	int key;

=======
private:
	/*pdo map */
	fp servo_on[6] = { &CModule1::set_disable_voltage , &CModule1::set_shutdown, &CModule1::set_ready_to_switch_on, &CModule1::set_switch_on, &CModule1::check_servo_on, &CModule1::end };

	fp stand_by[1] = {  &CModule1::end };
	fp stop[3] = { &CModule1::set_quick_stop,&CModule1::check_quick_stop_state ,&CModule1::end };
	fp fault_recover[4] = { &CModule1::set_disable_voltage, &CModule1::set_fault_reset, &CModule1::check_servo_off ,&CModule1::end };
	
>>>>>>> 1c2b7e1486d2fc25535f4f109e6d1e1477a8f50f

	fp arr[4][4] = { { &CModule1::set_disable_voltage, &CModule1::set_shutdown,  &CModule1::set_ready_to_switch_on,  &CModule1::set_switch_on },
					 { &CModule1::set_position,  &CModule1::set_point, &CModule1::clear_set_point, nullptr },
					 { &CModule1::set_quick_stop,&CModule1::check_quick_stop_state, nullptr, nullptr },
					 { &CModule1::set_disable_voltage ,&CModule1::set_fault_reset, nullptr, nullptr }
					};
	fp move[6] = { &CModule1::set_position, &CModule1::set_point , &CModule1::check_set_point_ack, &CModule1::clear_set_point, &CModule1::check_target_reached , nullptr};

<<<<<<< HEAD
private:

	void UpdateState(Motor& motor)
	{
		USHORT st = m_Inputs.status_word[motor.m_num] & status_word::mask;
		USHORT set_point_ack = m_Inputs.status_word[motor.m_num] & status_word::set_point_ack;
		USHORT tgt_reached = m_Inputs.status_word[motor.m_num] & status_word::target_reached;

		if (set_point_ack){
			if (tgt_reached) {
				motor.SetState(st::st_target_reached);
				return;
			}
			else {
				motor.SetState(st::st_moving);
				return;
			}
		}

		if (st == status_word::quick_stop_active) {
			motor.SetState(st::st_quick_stop_active);
			return;
		}

		else if (st == status_word::operation_enabled) {
			if (set_point_ack) {
				motor.SetState(st::st_set_point);
				return;
			}
			motor.SetState(st::st_operation_enabled);
			return;
		}
		else if (st == status_word::switch_on) {
			motor.SetState(st::st_switch_on);
			return;
		}
		else if (st == status_word::ready_to_switch_on) {
			motor.SetState(st::st_ready_to_switch_on);
			return;
		}

		st &= 0xFFDF;

		if (st == status_word::fault_reaction_active){
			motor.SetState(st::st_fault_reaction_active);
			return;
		}
		else if (st == status_word::fault) {
			motor.SetState(st::st_fault);
			return;
		}
		else if (st == status_word::switch_on_disabled) {
			motor.SetState(st::st_switch_on_disabled);
			return;
		}
	}

	bool set_quick_stop(Motor& motor)
	{
		m_Outputs.control_word[motor.m_num] = command::quick_stop;
		return success;

	}

	bool set_position(Motor& motor)
	{
		m_Outputs.target[motor.m_num] = motor.GetTargetPosition(); //m_DataArea3.target_position;
//		motor.set_position = true;
		return success;
	}

	bool set_point(Motor& motor)
	{
		m_Outputs.control_word[motor.m_num] = command::switch_on_and_enable_oepration;
//		motor.set_position = false;
		return success;
	}

	bool clear_set_point(Motor& motor)
	{
		m_Outputs.control_word[motor.m_num] = command::enable_operation;
		return success;
	}

	bool set_disable_voltage(Motor& motor) {
		m_Outputs.control_word[motor.m_num] = command::disable_voltage;
		return success;
	}
	bool set_shutdown(Motor& motor) {
		m_Outputs.control_word[motor.m_num] = command::shutdown;
		return success;
	}

	bool set_enable(Motor& motor) {
		m_Outputs.control_word[motor.m_num] = command::enable_operation;
		return success;
	}
	bool set_switch_on(Motor& motor) {
		m_Outputs.control_word[motor.m_num] = command::switch_on;
		return success;
	}
	bool set_fault_reset(Motor& motor) {
		m_Outputs.control_word[motor.m_num] = command::fault_reset;
		return success;
	}

=======
	void GetState(Motor& motor)
	{
		//(m_Inputs.status_word[motor.m_num] & status_word::mask_type2) == status_word::operation_enabled)
	}

	void GetCommand(Motor& motor)
	{
		//return motor.GetCommand();
	}
	bool check_servo_on(Motor& motor)
	{
		if (motor.m_timeout_count > timeout_cnt) {
			execute = stand_by;
			motor.m_timeout_count = 0;
			return fail;
		}

		if ((m_Inputs.status_word[motor.m_num] & status_word::mask_type2) == status_word::operation_enabled) {
			motor.m_timeout_count = 0;
			return success;
		}
		else {
			motor.m_execute = motor.m_re_execute;
			motor.m_timeout_count++;
			return fail;
		}
	}

	bool check_servo_off(Motor& motor)
	{
		if (motor.m_timeout_count > timeout_cnt) {
			execute = stand_by;
			motor.m_timeout_count = 0;
			return fail;
		}

		if ((m_Inputs.status_word[motor.m_num] & status_word::mask_type1) == status_word::switch_on_disabled) {
			motor.m_timeout_count = 0;
			return success;
		}
		else {
			motor.m_execute = motor.m_re_execute;
			motor.m_timeout_count++;
			return fail;
		}
	}
	bool check_quick_stop_state(Motor& motor)
	{
		if (motor.m_timeout_count > timeout_cnt) {
			execute = stand_by;
			motor.m_timeout_count = 0;
			return fail;
		}

		if ((m_Inputs.status_word[motor.m_num] & status_word::mask_type2) == status_word::quick_stop_active) {
			motor.m_timeout_count = 0;
			return success;
		}
		else {
			motor.m_execute = motor.m_re_execute;
			motor.m_timeout_count++;
			return fail;
		}
	}

	bool check_target_reached(Motor& motor)
	{
		if ((m_Inputs.status_word[motor.m_num] & status_word::mask_type3) == status_word::target_reached) {
			motor.SetCurrentPosition = motor.GetTargetPosition;
			return success;
		}
		else {
			return fail;
		}
	}

	bool check_set_point_ack(Motor& motor) {
		if ((m_Inputs.status_word[motor.m_num] & status_word::mask_set_point_ack) == status_word::set_point_ack) {
			motor.m_set_point_ack_flag = 1;
			return success;
		}
		else {
			motor.m_set_point_ack_flag = 0;
			return fail;
		}
	}
		/*for (auto motor = motors.begin(); motor != motors.end(); motor++) {
		if (check_status_word(USHORT target_reached)) {
		motor->UpdateCurrentPosition(m_DataArea3.target_position);
		}
		else {
		return fail;
		}
		}
		return success;*/

	//	//for (auto motor = motors.begin(); motor != motors.end(); motor++) {

	//	//	if ((m_Inputs.status_word & target_reached) != target_reached) {
	//	//m_DataArea3.state = state::standby; 
	//	//		return;
	//	//	}

	//	//
	//	//}
	//};

	//bool check_stopped()
	//{
	//	for (auto motor = motors.begin(); motor != motors.end(); motor++) {
	//		if ((m_Inputs.status_word & status_word::quick_stop_active) == status_word::quick_stop_active) {
	//			return fail;
	//		}
	//	}
	//	return success;
	//}

	//bool check_status() {
	//	for (auto motor = motors.begin(); motor != motors.end(); motor++) {
	//		//if ((m_Inputs.status_word & fault) == fault) {
	//		//transition 15
	//		m_Outputs.control_word = command::fault_reset;
	//		//}
	//	}
	//	return success;
	//}


	
	bool check_target_reached() {

		/*case 1. set position*/

		/*case 2. quick stop*/


		return success;
	}

	bool end(Motor& motor)
	{
		// always return false
		return false;
	}

	bool set_quick_stop(Motor& motor)
	{
		m_Outputs.control_word[motor.m_num] = command::quick_stop;
		return success;

	}

	bool set_position(Motor& motor)
	{
		m_Outputs.target[motor.m_num] = motor.GetTargetPosition(); //m_DataArea3.target_position;
		return success;
	}

	bool set_point(Motor& motor)
	{
		m_Outputs.control_word[motor.m_num] = command::switch_on_and_enable_oepration;
		return success;
	}

	bool clear_set_point(Motor& motor)
	{
		m_Outputs.control_word[motor.m_num] = command::enable_operation;
		return success;
	}

	bool set_disable_voltage(Motor& motor) {
		m_Outputs.control_word[motor.m_num] = command::disable_voltage;
		return success;
	}
	bool set_shutdown(Motor& motor) {
		m_Outputs.control_word[motor.m_num] = command::shutdown;
		return success;
	}

	bool set_switch_on(Motor& motor) {
		m_Outputs.control_word[motor.m_num] = command::enable_operation;
		return success;
	}
	bool set_ready_to_switch_on(Motor& motor) {
		m_Outputs.control_word[motor.m_num] = command::switch_on;
		return success;
	}
	bool set_fault_reset(Motor& motor) {
		m_Outputs.control_word[motor.m_num] = command::fault_reset;
		return success;
	}

>>>>>>> 1c2b7e1486d2fc25535f4f109e6d1e1477a8f50f
};


