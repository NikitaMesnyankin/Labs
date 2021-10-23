#ifndef CIRCULAR_H
#define CIRCULAR_H

#include <list>
#include <iterator>
#include <string>
#include <tuple>
#include <iostream>
#include <boost/circular_buffer.hpp>

typedef std::tuple<std::string, std::string, std::string, bool> target_tuple;

namespace mesnyankin
{
	target_tuple correctInput();

	template <typename T>
	class CircularList
	{
	public:
		CircularList<T>();
		CircularList<T>(const boost::circular_buffer<T>&);
		CircularList<T>(const CircularList<T>&);
		CircularList<T>(CircularList<T>&&) noexcept;

		CircularList<T>& operator=(const CircularList<T>&);
		CircularList<T>& operator=(CircularList<T>&&) noexcept;

		void showData() const;
		~CircularList<T>() = default;
	private:
		boost::circular_buffer<T> buffer_;
	};
}

#endif
