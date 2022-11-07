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

typedef struct _status_word {

	static constexpr USHORT mask_type1 = 0x004F;
<<<<<<< HEAD
	static constexpr USHORT mask = 0x006F;

	static constexpr USHORT mask2 = 0x146F;

=======
	static constexpr USHORT mask_type2 = 0x006F;
>>>>>>> 1c2b7e1486d2fc25535f4f109e6d1e1477a8f50f
	static constexpr USHORT mask_type3 = 0x0400;
	static constexpr USHORT mask_set_point_ack = 0x0400;


	static constexpr USHORT switch_on_disabled = 0x0040;
	static constexpr USHORT ready_to_switch_on = 0x0021;
	static constexpr USHORT switch_on = 0x0023;
	static constexpr USHORT operation_enabled = 0x0027;
	static constexpr USHORT fault = 0x0008;
<<<<<<< HEAD
	static constexpr USHORT fault_reaction_active = 0x000F;
	static constexpr USHORT quick_stop_active = 0x0007;


=======
	static constexpr USHORT quick_stop_active = 0x0007;

>>>>>>> 1c2b7e1486d2fc25535f4f109e6d1e1477a8f50f
	static constexpr USHORT target_reached = 0x0400;
	static constexpr USHORT set_point_ack = 0x1000;


}status_word;



