#include <iostream>
#include <string>

using namespace std;

long long karatsuba(long long x, long long y)
{
	if (x < 10 or y < 10)
		return x * y;

	int len_x = to_string(x).length();
	int len_y = to_string(y).length();

	int divider = min(to_string(x).length(), to_string(y).length());
	divider = divider / 2;

	long a = x / pow(10, divider);
	long b = x % (long)pow(10, divider);
	long c = y / pow(10, divider);
	long d = y % (long)pow(10, divider);

	long long step_1 = karatsuba(a, c);
	long long step_2 = karatsuba(b, d);
	long long step_3 = karatsuba((a + b), (c + d));

	long long step_4 = step_3 - step_2 - step_1;
	long long result = step_1 * pow(10, 2*divider) + step_4 * pow(10,divider) + step_2;
	return result;
}

void test_karatsuba(long long x,long long y,long long expect_result)
{
	if (karatsuba(x, y) == expect_result)
	{cout << "OK\n"; }
	else
	{cout << "ERROR\n"; };

}

int main()
{
	test_karatsuba(4527, 8357, 37832139);
	test_karatsuba(45279, 8357, 378396603);
	test_karatsuba(683613, 89058, 60881206554);
}
