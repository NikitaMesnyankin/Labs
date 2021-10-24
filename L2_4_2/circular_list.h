//#ifndef CIRCULAR_H
//#define CIRCULAR_H

#include <list>
#include <iterator>
#include <string>
#include <tuple>
#include <iostream>
#include <boost\circular_buffer.hpp>

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

		boost::circular_buffer<T> getContainer() const;
		void showData() const;
		~CircularList<T>() = default;
	private:
		boost::circular_buffer<T> buffer_;
	};
}

template <typename T>
mesnyankin::CircularList<T>::CircularList()
{
	this->buffer_ = boost::circular_buffer<T>();
}

template <typename T>
mesnyankin::CircularList<T>::CircularList(const boost::circular_buffer<T>& buffer_data)
{
	this->buffer_ = buffer_data;
}

template<typename T>
mesnyankin::CircularList<T>::CircularList(const CircularList<T>& rhs)
{
	this.buffer_ = rhs.buffer_;
}


template <typename T>
mesnyankin::CircularList<T>::CircularList(CircularList<T>&& rhs) noexcept
{
	this.buffer_ = std::move(rhs.buffer_);
}

template <typename T>
mesnyankin::CircularList<T>& mesnyankin::CircularList<T>::operator=(const CircularList<T>& rhs)
{
	if (this->buffer_ != rhs->buffer_)
	{
		this->buffer_(rhs->buffer_);
	}
	return *this;
}

template <typename T>
mesnyankin::CircularList<T>& mesnyankin::CircularList<T>::operator=(CircularList<T>&& rhs) noexcept
{
	if (!(rhs.buffer_.empty()))
	{
		this->buffer_(rhs->buffer_);
	}
	return *this;
}

template<typename T>
inline boost::circular_buffer<T> mesnyankin::CircularList<T>::getContainer() const
{
	return this->buffer_;
}

template <typename T>
void mesnyankin::CircularList<T>::showData() const
{
	if (!(this->buffer_.empty()))
	{
		for (const T& item : buffer_)
		{
			std::apply([](auto&&... args)
				{
					((std::cout << args << '\n'), ...);
				}, item);
		}
	}
}

//#endif
