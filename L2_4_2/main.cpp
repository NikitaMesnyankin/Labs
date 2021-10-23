#include "circular_list.h"

int main()
{
	target_tuple x = std::make_tuple("abc", "abc", "abc", true);
	boost::circular_buffer<target_tuple> buffer(3);
	buffer.push_back(x);
	buffer.push_back(x);
	buffer.push_back(x);
	auto buf = mesnyankin::CircularList<target_tuple>();
	//buf.showData();
	return 0;
}