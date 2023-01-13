#ifndef __PAIR_HPP__
# define __PAIR_HPP__

namespace	ft {
	template <class T1, class T2>
	class	pair {
		public:
			typedef T1	first_type;
			typedef T2	second_type;

			pair();
			pair(const first_type& a, const second_type& b);

			template <class U1, class U2>
			pair(const pair<U1, U2>& pr);

			pair&	operator=(const pair& pr);

			first_type	first;
			second_type	second;
	};

	# include "pair.tpp"
}

#endif
