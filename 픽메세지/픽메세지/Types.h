#pragma once

using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;
using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;


struct Pos {
	float x{};
	float y{};

	Pos operator-(const Pos& p) {
		Pos ret;
		ret.x = x - p.x;
		ret.y = y - p.y;
		return ret;
	}
	Pos operator+(const Pos& p) {
		Pos ret;
		ret.x = x + p.x;
		ret.y = y + p.y;
		return ret;
	}

	void operator-=(const Pos& p) {
		x -= p.x;
		y -= p.y;
	}
	void operator+=(const Pos& p) {
		x += p.x;
		y += p.y;
	}

	bool operator!=(const Pos& p) {
		return (x != p.x || y != p.y);
	}
};

struct Stat
{
	int32 hp = 0;
	int32 maxhp = 0;
	float speed = 0;
};