#pragma once

class Vector {
public:
	virtual Vector operator+(Vector vector);
	virtual Vector operator-(Vector vector);

	virtual Vector operator*(int scalar);
	virtual Vector operator/(int scalar);

	virtual void operator+=(Vector vector);
	virtual void operator-=(Vector vector);

	virtual void operator*=(int scalar);
	virtual void operator/=(int scalar);

	Vector();
};