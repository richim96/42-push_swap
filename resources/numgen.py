# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    numgen.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmei <rmei@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/30 15:37:23 by rmei              #+#    #+#              #
#    Updated: 2024/08/30 15:37:36 by rmei             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import random
import sys

if __name__ == "__main__":
    # Generate a list of the specified size.
    if len(sys.argv) != 2:
        print("[USAGE]: python3 numgen.py <list_size>")
        sys.exit(1)

    try:
        size: int = abs(int(sys.argv[1]))
    except ValueError:
        print("[ERROR]: You must provide a valid positive integer.")
        sys.exit(1)

    nums: list[int] = random.sample(range(-size, size), size)
    nums: str = " ".join([str(n) for n in nums])
    print(nums)
