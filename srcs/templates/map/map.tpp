#include "constructors.tpp"
#include "iterators.tpp"
#include "capacity.tpp"
#include "access.tpp"
#include "modifiers.tpp"
#include "observers.tpp"
#include "operations.tpp"
#include "allocator.tpp"

template <class InputIt1, class InputIt2>
static bool	isContentItEqual(InputIt1 first, InputIt1 last, InputIt2 compareContent) {
	while (first != last) {
		if (*first != *compareContent)
			return false;

		first++;
		compareContent++;
	}
	return true;
}

template <class Key, class T, class Compare, class Alloc>
bool	operator==(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) {
	if (lhs.size() != rhs.size())
		return false;

	return (isContentItEqual(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class Key, class T, class Compare, class Alloc>
bool	operator!=(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) {
	return (!(lhs == rhs));
}

template <class Key, class T, class Compare, class Alloc>
bool	operator<(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) {
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class Key, class T, class Compare, class Alloc>
bool	operator<=(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) {
	return (!(rhs < lhs));
}

template <class Key, class T, class Compare, class Alloc>
bool	operator>(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) {
	return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
}

template <class Key, class T, class Compare, class Alloc>
bool	operator>=(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) {
	return (!(rhs > lhs));
}

template <class Key, class T, class Compare, class Alloc>
void	swap(ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs) {
	lhs.swap(rhs);
}

// template <class Key, class T, class Compare, class Alloc>
// bool operator== (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) { return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));};
// template <class Key, class T, class Compare, class Alloc>
// bool operator!= (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) { return (!(lhs == rhs));};
// template <class Key, class T, class Compare, class Alloc>
// bool operator<  (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));};
// template <class Key, class T, class Compare, class Alloc>
// bool operator<= (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) { return (!(rhs < lhs));};
// template <class Key, class T, class Compare, class Alloc>
// bool operator>  (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) { return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));};
// template <class Key, class T, class Compare, class Alloc>
// bool operator>= (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) { return (!(lhs < rhs));};
