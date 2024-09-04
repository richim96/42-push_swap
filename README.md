# 42-push_swap
This program sorts a stack of integers using the minimum amount of moves allowed by the [push_swap](https://github.com/richim96/42-push_swap/blob/main/src/push_swap/push_swap_rotate.c) algorithm. Beating the push_swap benchmark of 500 integers sorted in < 5500 moves - in my experience and in the many instances available online, - translates into rather inefficient programs with unsustainable codebases. For this reason, I shifted from move optimization to finding a balance where:

1) stack traversing is greatly reduced (compared to solutions like [Turk](https://github.com/ayogun/push_swap)), so that the program is much faster on large lists;
2) moves are solved in `O(nk)` time and `O(1)` space by binary [Radix Sort](https://github.com/42YerevanProjects/push_swap), with a x1.5 **constant** overhead (negligible) vis-à-vis Turk;
3) the codebase is cleaner.


For more details on the task and the specifics of push_swap, please refer to this [guide](https://github.com/richim96/42-push_swap/blob/main/resources/guidelines.pdf).

### Usage:
```bash
make

ARG=$(python3 resources/numgen.py <list_size>)

./push_swap $ARG | wc -l
```
