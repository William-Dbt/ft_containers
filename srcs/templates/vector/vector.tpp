#include "constructors.tpp"
#include "capacity.tpp"
#include "access.tpp"
#include "modifiers.tpp"
#include "allocator.tpp"

template <class T, class Alloc>
void	ft::vector<T, Alloc>::changeCapacity(const size_type newCapacity) {
	pointer	newData;

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
