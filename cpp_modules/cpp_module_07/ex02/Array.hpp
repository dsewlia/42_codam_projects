#pragma once
#include <exception>
#include <cstddef>


template<typename T>
class Array
{
	private:
		T			*_array = nullptr;
		size_t _size = 0;
	
	public:
		Array() : _array(nullptr), _size(0) {}

		Array(size_t size) : _array(new T[size]), _size(size) {}

		Array(const Array &rhs) : _array(new T[rhs.size()]), _size(rhs.size())
		{
			for (size_t i = 0; i < this->_size; i++)
				this->_array[i] = rhs._array[i];
		}

		~Array() { delete[] this->_array; }

		Array &operator=(const Array &rhs)
		{
			if (this == &rhs)
				return *this;
			
			delete[] this->_array;
			this->_size = rhs.size();
			this->_array = new T[this->_size];
			for (size_t i = 0; i < this->_size; i++)
				this->_array[i] = rhs._array[i];
			return (*this);
		}

		T &operator[](size_t index)
		{
			if (index >= this->_size)
			{
				throw Array<T>::IndexOutOfBoundException();
			}
			return (this->_array[index]);
		}

		const T &operator[](size_t index) const
		{
			if (index >= this->_size)
			{
				throw Array<T>::IndexOutOfBoundException();
			}
			return (this->_array[index]);
		}

		size_t size() const { return this->_size; }
		
		class IndexOutOfBoundException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};


};

template <typename T>
const char *Array<T>::IndexOutOfBoundException::what() const throw()
{
	return ("Array index out of bound");
}