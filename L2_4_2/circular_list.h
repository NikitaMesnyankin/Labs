//#ifndef CIRCULAR_H
//#define CIRCULAR_H

#include <list>
#include <iterator>
#include <string>
#include <tuple>
#include <iostream>
#include <boost\circular_buffer.hpp>

typedef std::tuple<std::string, std::string, std::string, bool> target_tuple;
//autoNumber - surnameInitials - routeNumber - isOnWay

namespace mesnyankin
{
	target_tuple correctInput();
	boost::circular_buffer<target_tuple> generateDataSet();

	template<typename... args>
	void outputTuple(const std::tuple<args...>& tpl);

	template <typename T>
	class CircularList
	{
	public:
		CircularList<T>();
		CircularList<T>(const boost::circular_buffer<T>&);
		CircularList<T>(const CircularList<T>&);
		CircularList<T>(CircularList<T>&&) noexcept;

		void push_back(const target_tuple&);
		void clear();
		void changeOnSearch();
		void searchChange(bool);
		void criteriaOutput(bool);

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

template<typename T>
inline void mesnyankin::CircularList<T>::push_back(const target_tuple& data)
{
	
	if (this->buffer_.full()) {
		this->buffer_.set_capacity(this->buffer_.capacity() + 1);
	}
	this->buffer_.push_back(data);
}

template<typename T>
inline void mesnyankin::CircularList<T>::clear()
{
	std::cout << "Cleaning container..." << std::endl;
	buffer_.clear();
}

template<typename T>
inline void mesnyankin::CircularList<T>::changeOnSearch()
{
	bool searchCriteria;
	int choice;

	std::string s;

	do
	{
		std::cout << "1: Proceed to criteria and search..." << std::endl
			<< "2: Exit..." << std::endl;
		std::getline(std::cin, s);
		choice = (s.compare("1") == 0) ? 1 : (s.compare("2") == 0) ? 2 : 3;
		switch (choice)
		{
		case 1:
		{
			while (true) {
				std::string matching_string;
				std::cout << "Set searchCriteria to true / false? Enter t(true) or f(false) to proceed..." << std::endl;
				std::getline(std::cin, matching_string);
				std::cout << "Entered: " << matching_string << std::endl;
				if ((matching_string.compare("t") == 0) || (matching_string.compare("f") == 0))
				{
					searchCriteria = (matching_string == "t") ? true : false;
					break;
				}
				else {
					std::cout << "Wrong input! Repeat..." << std::endl;
				}
			}
			do
			{
				std::string s;
				std::cout << "1: Output on based criteria..." << std::endl
					<< "2: Change to based criteria..." << std::endl
					<< "3: Back to criteria setting..." << std::endl;

				std::getline(std::cin, s);
				choice = (s.compare("1") == 0) ? 1 : (s.compare("2") == 0) ? 2 : (s.compare("3") == 0) ? 3 : 4;

				switch (choice)
				{
				case 1:
				{
					criteriaOutput(searchCriteria);
					break;
				}
				case 2:
				{
					searchChange(searchCriteria);
					break;
				}
				case 3:
				{
					std::cout << "Returning to criteria setting..." << std::endl;
					break;
				}
				default:
				{
					std::cout << "No command found!..." << std::endl;
					break;
				}
				}
			} while (choice != 3);
			break;
		}
		case 2:
		{
			std::cout << "Exit proceeded..." << std::endl;
			break;
		}
		default:
		{
			std::cout << "No command found!..." << std::endl;
			break;
		}
		}
	} while (choice != 2);
}

template <typename T>
inline void mesnyankin::CircularList<T>::searchChange(bool searchCriteria)
{
	std::string searchString;
	std::cout << "Enter search string..." << std::endl;
	std::getline(std::cin, searchString);

	if (!(this->buffer_.empty()))
	{
		for (T& item : this->buffer_)
		{
			if (searchString.compare((std::get<0>(item))) == 0)
			{
				std::cout << "Item found, changing..." << std::endl;
				std::get<bool>(item) = searchCriteria;
			}
		}
	}
	else {
		std::cout << "Container is empty, search is not possible..." << std::endl;
	}
}

template <typename T>
inline void mesnyankin::CircularList<T>::criteriaOutput(bool searchCriteria)
{
	if (!(this->buffer_.empty()))
	{
		for (const T& item : buffer_)
		{
			if (std::get<3>(item) == searchCriteria)
			{
				outputTuple(item);
			}
		}
	}
	else {
		std::cout << "Container is empty, search is not possible..." << std::endl;
	}
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
		buffer_ = rhs.buffer_;
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
		std::cout << "Container data: " << std::endl;
		for (const T& item : buffer_)
		{
			outputTuple(item);
		}
	}
	else
	{
		std::cout << "Container is empty!.." << std::endl;
	}
}

template<typename... args>
void mesnyankin::outputTuple(const std::tuple<args...>& tpl)
{
	std::apply([](auto&&... arguments)
		{
			((std::cout << arguments << ' '), ...);
		}, tpl);
	std::cout << std::endl;
};

//#endif
