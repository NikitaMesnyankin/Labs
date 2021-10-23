#include "circular_list.h"

target_tuple mesnyankin::correctInput()
{
	std::string nmbr, drvrnm, mrschrt;
	bool nw;
	std::cout << "Enter autobus number..." << std::endl;
	std::cin >> nmbr;
	std::cout << "Enter driver name..." << std::endl;
	std::cin >> drvrnm;
	std::cout << "Enter marschrute number..." << std::endl;
	std::cin >> mrschrt;
	nw = false;
	return std::make_tuple(nmbr, drvrnm, mrschrt, nw);
}

template <typename T>
mesnyankin::CircularList<T>::CircularList<T>()
{
	buffer_ = boost::circular_buffer();
}

template <typename T>
mesnyankin::CircularList<T>::CircularList<T>(const boost::circular_buffer<T>& buffer_data)
{
	this->buffer_(buffer_data);
}

template<typename T>
mesnyankin::CircularList<T>::CircularList<T>(const CircularList<T>& rhs)
{
	this.buffer_(rhs.buffer_);
}


template <typename T>
mesnyankin::CircularList<T>::CircularList<T>(CircularList<T>&& rhs) noexcept
{
	this.buffer_(std::move(rhs.buffer_));
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

template <typename T>
void mesnyankin::CircularList<T>::showData() const
{
	if (!(this->buffer_.empty()))
	{
		for (const auto& item : buffer_)
		{
			std::apply([](auto&&... args)
				{
					((std::cout << args << '\n'), ...);
				}, item);
		}
	}
}