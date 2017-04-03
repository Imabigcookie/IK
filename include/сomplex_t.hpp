#include <iostream>

using namespace std;

class complex_t
{
private:
	double a;
	double b;
public:
	complex_t();
	
	complex_t(double x, double y);
	
	complex_t(const complex_t&cop);
	
	double a_() const;
	double b_() const;
	
	complex_t operator * (const complex_t& c2) const;
	complex_t operator / (const complex_t& c2) const;
	complex_t operator += (const complex_t& c2); 
	complex_t operator -= (const complex_t& c2) ;
	complex_t operator *= (const complex_t& c2) ;
	complex_t operator /= (const complex_t& c2) ;
	complex_t operator = (const complex_t& result);
	bool operator == (const complex_t& c2) const;
	friend istream& operator >> (istream&cin,complex_t& result);
	friend ostream& operator << (ostream&cout,const complex_t& result);
};
