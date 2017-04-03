#include <сomplex_t.hpp>
#include <catch.hpp>
SCENARIO("def constructor")
{
	complex_t Complex;
	REQUIRE(Complex.a_() == 0);
	REQUIRE(Complex.b_() == 0);
}

SCENARIO("param constructor")
{
	complex_t Complex(1, 2);
	REQUIRE(Complex.a_() == 1);
	REQUIRE(Complex.b_() == 2);
}

SCENARIO("copy constructor")
{
	complex_t Complex(1, 2);
	complex_t cop(Complex);
	REQUIRE(cop.a_() == 1);
	REQUIRE(cop.b_() == 2);
}

SCENARIO("operator *")
{
	complex_t c1(7, 6);
	complex_t c2(5, 4);
	complex_t c3(11, 58);
	REQUIRE((c1*c2) == c3);
}

SCENARIO("operator /")
{
	complex_t c1(4, 5);
	complex_t c2(4, 5);
	complex_t c3(1, 0);
	REQUIRE((c1 / c2) == c3);
}

SCENARIO("operator +=")
{
	complex_t c1(11, 1);
	complex_t c2(8, 3);
	complex_t c3(19, 4);
	REQUIRE((c1 += c2) == c3);
}

SCENARIO("operator -=")
{
	complex_t c1(6, 10);
	complex_t c2(3, 6);
	complex_t c3(3, 4);
	REQUIRE((c1 -= c2) == c3);
}

SCENARIO("operator *=")
{
	complex_t c1(7, 6);
	complex_t c2(5, 4);
	complex_t c3(11, 58);
	REQUIRE((c1 *= c2) == c3);
}

SCENARIO("operator /=")
{
	complex_t c1(2, 1);
	complex_t c2(2, 1);
	complex_t c3(1, 0);
	REQUIRE((c1 /= c2) == c3);
}

SCENARIO("operator =")
{
	complex_t c1(5, 7);
	complex_t c2 = c1;
	REQUIRE(c2 == c1);
}

SCENARIO("operator ==")
{
	complex_t c1(2, 5);
	complex_t c2(2, 5);
	REQUIRE(c1 == c2);
}
