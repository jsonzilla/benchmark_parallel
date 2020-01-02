#pragma once

#include <algorithm>
#include <future>

namespace DIY {
	template<typename Iterator, typename Func>
	void parallel_for_each(Iterator first, Iterator last, Func f) {
		unsigned long const lenght = std::distance(first, last);
		if (!lenght) {
			return;
		}
		unsigned long const min_per_thread = 25;
		if (lenght < (2 * min_per_thread)) {
			std::for_each(first, last, f);
		}
		else {
			Iterator const mid_point = first + lenght / 2;
			std::future<void> first_half = std::async(&parallel_for_each<Iterator, Func>, first, mid_point, f);
			parallel_for_each(mid_point, last, f);
			first_half.get();
		}
	}

	int f()
	{
		static int i = 1;
		return i++;
	}
}