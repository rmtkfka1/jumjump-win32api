#pragma once

class Object
{
public:
	
	Object(ObjectType type);
	virtual ~Object();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;

	ObjectType GetObjectType() { return _type; }
	Pos GetPos() { return _pos; }
	void SetPos(Pos pos) { _pos = pos; }
	float GetY() { return _pos.y; }
	void SetY(float y) { _pos.y = y; }



protected:
	ObjectType _type = ObjectType::NONE;
	Pos _pos = {};
	Stat _stat = {};
	Pos size;
};

