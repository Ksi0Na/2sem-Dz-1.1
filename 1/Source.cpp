#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

#include "Header.h"

using namespace std;

class RCS {
public:
	RCS(double x, double y)
		: _x(x)
		, _y(y)
	{}

	double x() const { return _x; }
	double y() const { return _y; }

	void set_x(double x) { _x = x; };
	void set_y(double y) { _y = y; };

	string to_string() const
	{
		stringstream ss;
		ss << "(" << _x << ", " << _y << ")";
		return ss.str();
	}

	void print() const
	{
		cout << "( " << _x << " ; "
			<< _y << " )"
			<< endl;
	}

	class PCS convert() const
	{
		double fi = atan(y() / x());
		double ro = sqrt(x() * x() + y() * y());
		return PCS(fi, ro);
	}

	~RCS() {
		_x = NULL;
		_y = NULL;
	}

private:
	double _x, _y;
};

class PCS {
public:
	PCS(double fi, double ro)
		: _fi(fi)
		, _ro(ro)
	{}

	double fi() const { return _fi; }
	double ro() const { return _ro; }

	void set_fi(double fi) { _fi = fi; };
	void set_ro(double ro) { _ro = ro; };

	string to_string() const
	{
		stringstream ss;
		ss << "(" << _fi << ", " << _ro << ")";
		return ss.str();
	}

	void print() const
	{
		cout << "( " << _fi << " ; "
			<< _ro << " )"
			<< endl;
	}

	 RCS convert() const
	{
		double x = cos(fi()) * ro();
		double y = sin(fi()) * ro();
		return RCS(x, y);
	}

	~PCS() {
		_fi = NULL;
		_ro = NULL;
	}

private:
	double _fi, _ro;
};

double distance(RCS &dot_1, RCS &dot_2)
	{
		return 
			sqrt(
			 pow((dot_2.x() - dot_1.x()), 2) +
			 pow((dot_2.y() - dot_1.y()), 2)
				);
	}

double distance(PCS &dot_1, PCS &dot_2)
	{
		return 
			sqrt(
			 pow(dot_1.ro(), 2) +
			 pow(dot_2.ro(), 2) -
				 2 * dot_1.ro() * dot_2.ro() 
				   * cos(dot_1.fi() - dot_2.fi())
				);
	}

double distance(RCS &dot_1, PCS &dot_2)
	{
		distance(dot_1, dot_2.convert());
	}

double distance(PCS &dot_1, RCS &dot_2)
	{
		distance(dot_1.convert(), dot_2);
	}