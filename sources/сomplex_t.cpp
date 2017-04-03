#include "сomplex_t.hpp"
complex_t::complex_t() : a(0.0), b(0.0)
{}
complex_t::complex_t(double x, double y) : a(x), b(y)
{}
complex_t::complex_t(const complex_t&cop)
{
	a = cop.a;
	b = cop.b;
}
double complex_t::a_() const
{
	return a;
}

double complex_t::b_() const
{
	return b;
}
bool complex_t::operator == (const complex_t& c2) const
{
	if ((a == c2.a) && (b == c2.b))
		return true;
}

complex_t complex_t::operator = (const complex_t& result)
{
	if (this != &result) 
	{
	a = result.a;
	b = result.b;
	return *this;
	}

}
istream& operator >> (istream&cin, complex_t& result) 
{
	cout << "Please enter real complex part:" << endl;
	cin >> result.a;
	cout << "Please enter imaginary complex part:" << endl;
	cin >> result.b;
	cout << endl;
	return cin;
}

ostream& operator << (ostream&cout,const complex_t& result) 
{
	if (result.b < 0)
	{
		cout << result.a << result.b << "i" << endl;
	}
	else
		cout << result.a << "+" << result.b << "i" << endl;
	return cout;
}
complex_t complex_t::operator * (const complex_t& c2) const
{
	return complex_t(a*c2.a - b*c2.b, a*c2.b + c2.a*b);
}

complex_t complex_t::operator / (const complex_t& c2) const
{
	return complex_t((a*c2.a + b*c2.b) / (c2.a*c2.a + c2.b*c2.b), (c2.a*b - a*c2.b) / (c2.a*c2.a + c2.b*c2.b));
}

complex_t complex_t::operator += (const complex_t& c2) 
{
	a += c2.a;
	b += c2.b;
	return *this;
}

complex_t complex_t::operator -= (const complex_t& c2) 
{
	a -= c2.a;
	b -= c2.b;
	return *this;
}
complex_t complex_t::operator /= (const complex_t& c2) 
{
	float a_ = (a*c2.a + b*c2.b) / (c2.a*c2.a + c2.b*c2.b);
	b = (c2.a*b - a*c2.b) / (c2.a*c2.a + c2.b*c2.b);
	a = a_;
	return *this;
}

complex_t complex_t::operator *= (const complex_t& c2) 
{
	float a_ = a*c2.a - b*c2.b;
	b = a*c2.b + c2.a*b;
	a = a_;
	return *this;
}
