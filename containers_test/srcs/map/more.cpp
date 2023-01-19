#include "common.hpp"

#define T1 int
#define T2 std::string
#include <map>
struct ft_more
{
	constexpr bool operator()(const T1 &lhs, const T1 &rhs) const
	{
		return lhs > rhs; // assumes that the implementation uses a flat address space
	}
};

typedef TESTED_NAMESPACE::map<T1, T2, ft_more> ft_mp;
typedef TESTED_NAMESPACE ::map<T1, T2, ft_more>::iterator ft_mp_it;

int main(void)
{
	ft_mp mp;

	mp[42] = "fgzgxfn";
	mp[25] = "funny";
	mp[80] = "hey";
	mp[12] = "no";
	mp[27] = "bee";
	mp[90] = "8";
	printSize(mp);

	return (0);
}
