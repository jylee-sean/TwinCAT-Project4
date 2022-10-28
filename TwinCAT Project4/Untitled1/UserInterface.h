#pragma once


typedef struct _state {
	static constexpr INT servo_off = 1;
	//static constexpr INT servo_on = 2;
	static constexpr INT set_position = 3;
	static constexpr INT move = 4;
	static constexpr INT recovery = 5;
	static constexpr INT standby = 6;
	static constexpr INT error = 7;
 
	/*temp*/
	static constexpr INT enable = 10;
	static constexpr INT set = 8;
	static constexpr INT stop = 9;
}state;

typedef struct _command {
	static constexpr USHORT shutdown = 0x06;
	static constexpr USHORT switch_on = 0x07;
	static constexpr USHORT switch_on_and_enable_oepration = 0x3F;
	static constexpr USHORT disable_voltage = 0x00;
	static constexpr USHORT quick_stop = 0x02;
	static constexpr USHORT disable_operation = 0x07;
	static constexpr USHORT enable_operation = 0x0F;
	static constexpr USHORT fault_reset = 0x80;
}command;

typedef struct status_word {

	static constexpr USHORT mask_type1 = 0x004F;
	static constexpr USHORT mask_type2 = 0x006F;

	static constexpr USHORT switch_on_disabled = 0x0040;
	static constexpr USHORT ready_to_switch_on = 0x0021;
	static constexpr USHORT switch_on = 0x0023;
	static constexpr USHORT operation_enabled = 0x0027;
	static constexpr USHORT fault = 0x0008;
	static constexpr USHORT quick_stop_active = 0x0007;
	static constexpr USHORT target_reached = 0x0400;
}aa;