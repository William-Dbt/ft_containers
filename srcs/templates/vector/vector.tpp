#include "vector_constructors.tpp"
#include "vector_capacity.tpp"
#include "vector_access.tpp"
#include "vector_allocator.tpp"

template <typename T, class Alloc>
void	ft::vector<T, Alloc>::changeCapacity(const size_type newCapacity) {
	pointer	newData;
	pointer	tmpNewData;
	pointer	oldData = this->_datas;
	pointer	tmpOldData = oldData;

	newData = this->_alloc.allocate(newCapacity);
	this->_datas = newData;
	tmpNewData = this->_datas;
	for (size_type i = 0; i < newCapacity; i++) {
		if (i < this->_size) {
			this->_alloc.construct(tmpNewData++, *tmpOldData);
			this->_alloc.destroy(tmpOldData++);
		}
		else
			*tmpNewData++ = value_type();
	}
	this->_alloc.deallocate(oldData, this->_capacity);
	this->_capacity = newCapacity;
}
