#pragma once
#define DECLARE_SINGLE(classname)                   \
public:											\
	classname(){}									\
													\
public:												\
													\
	static classname* GetInstance()					\
	{												\
		static classname s_Insatance;				\
		return &s_Insatance;						\
	}												

#define GET_SINGLE(classname) classname::GetInstance() 

#define WINDOW_WIDTH 1216
#define WINDOW_HEIGHT 639
