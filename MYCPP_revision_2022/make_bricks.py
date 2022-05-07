#!/usr/bin/python3
# -*- coding: utf-8 -*-

# coding exercise from:
#   https://codingbat.com/prob/p118406
#   http://codingbat.com/python/Logic-2

test_cases = [
    (3, 1, 8, True),
    (3, 1, 9, False),
    (3, 2, 10, True),
    (4, 1, 8, True),
    (1, 3, 14, False),
    (3, 2, 8, True),
    (3, 2, 9, False),
    (6, 1, 11, True),
    (6, 0, 11, False),
    (1, 4, 11, True),
    (0, 3, 10, True),
    (1, 4, 12, False),
    (3, 1, 7, True),
    (1, 1, 7, False),
    (2, 1, 7, True),
    (7, 1, 11, True),
    (7, 1, 8, True),
    (7, 1, 13, False),
    (43, 1, 46, True),
    (40, 1, 46, False),
    (40, 2, 47, True),
    (40, 2, 50, True),
    (40, 2, 52, False),
    (22, 2, 33, False),
    (0, 2, 10, True),
    (1000000, 1000, 1000100, True),
    (2, 1000000, 100003, False),
    (20, 0, 19, True),
    (20, 0, 21, False),
    (20, 4, 51, False),
    (20, 4, 39, True),
    (3, 10, 54, False),
    (4, 10, 54, True),
    (5, 10, 54, True),
    (18, 1, 19, True), # this is an unnecessarily cruel/trick test case, since it looks like 18 + 1 = 19, buy really it's a (subset of 18) + (1 * 5) = 19
]

size_big = 5

def make_bricks_1(small, big, goal):
    if (goal // size_big) <= big and goal % size_big <= small:
        return True
    elif (goal - (big * size_big) >= 0 and goal - (big * size_big) <= small):
        return True
    else:
        return False

def make_bricks_2(small, big, goal):
    for i in range(big + 1):
        if i * size_big <= goal and goal - (i * size_big) <= small:
            return True
    return False

def make_bricks_3(small, big, goal):
    if goal > (big * size_big) + small:
        return False
    elif goal % size_big > small:
        return False
    else:
        return True

if __name__ == '__main__':
    print('Testing make_bricks solution:')
    for t, tc in enumerate(test_cases):

        # test each attempt separately, one at a time
        result = make_bricks_1(tc[0], tc[1], tc[2])
        # result = make_bricks_2(tc[0], tc[1], tc[2])
        # result = make_bricks_3(tc[0], tc[1], tc[2])

        # display results
        if result == tc[3]:
            print('{:2d}   PASS'.format(t + 1), tc)
        else:
            print('{:2d}   FAIL {:s}'.format(t + 1, str(result)), tc)
