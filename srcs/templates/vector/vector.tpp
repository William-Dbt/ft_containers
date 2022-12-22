#include "constructors.tpp"
#include "iterators.tpp"
#include "capacity.tpp"
#include "access.tpp"
#include "modifiers.tpp"
#include "allocator.tpp"

template <class T, class Alloc>
void	ft::vector<T, Alloc>::changeCapacity(size_type newCapacity) {
	pointer	newData;

	if (newCapacity == 0)
		newCapacity = 2;

	newData = this->_alloc.allocate(newCapacity);
	for (size_type i = 0; i < newCapacity; i++) {
		if (i < this->_size) {
			this->_alloc.construct(&newData[i], this->_datas[i]);
			this->_alloc.destroy(&this->_datas[i]);
		}
		else
			this->_alloc.construct(&newData[i], value_type());
	}
	this->_alloc.deallocate(this->_datas, this->_capacity);
	this->_datas = newData;
	this->_capacity = newCapacity;
}

template <class T, class Alloc>
bool	operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	size_t	i;

	if (lhs.size() != rhs.size())
		return false;

	for (i = 0; i < lhs.size(); i++)
		if (lhs[i] != rhs[i])
			return false;

	return true;
}

template <class T, class Alloc>
bool	operator!=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	return (!(lhs == rhs));
}

template <class T, class Alloc>
bool	operator<(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class T, class Alloc>
bool	operator<=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	return (!(rhs < lhs));
}

template <class T, class Alloc>
bool	operator>(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	return (rhs < lhs);
}

template <class T, class Alloc>
bool	operator>=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	return (!(lhs < rhs));
}

template <class T, class Alloc>
void	swap(ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs) {
	lhs.swap(rhs);
}
