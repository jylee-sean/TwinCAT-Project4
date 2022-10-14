#pragma once


struct state {
	static constexpr INT servo_off = 1;
	static constexpr INT servo_on = 2;
	static constexpr INT set_position = 3;
	static constexpr INT recovery = 4;
	static constexpr INT standby = 5;
	static constexpr INT error = 6;
};

struct command {
	static constexpr USHORT shutdown = 0x06;
	static constexpr USHORT switch_on = 0x07;
	static constexpr USHORT switch_on_and_enable_oepration = 0x3F;
	static constexpr USHORT disable_voltage = 0x00;
	static constexpr USHORT quick_stop = 0x02;
	static constexpr USHORT disable_operation = 0x07;
	static constexpr USHORT enable_operation = 0x0F;
	static constexpr USHORT fault_reset = 0x80;
};