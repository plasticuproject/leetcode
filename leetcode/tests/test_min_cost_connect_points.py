"""test_min_cost_connect_points.py"""
from typing import List, Dict, Tuple
from timeit import timeit
from leetcode import min_cost_connect_points  # C Extension


def native_min_cost_connect_points(points: List[List[int]]) -> int:
    """Given an array points representing integer coordinates
    of some points on a 2D-plane, where points[i] = [xi, yi],
    return the minimum cost to make all points connected. All
    points are connected if there is exactly one simple path
    between any two points."""
    result = 0
    MAX = 20000001
    dist = {}
    for i in range(len(points)):
        dist[points[i][0], points[i][1]] = MAX if i else 0

    while dist:
        temp_min = MAX
        for i in dist:
            if dist[i] < temp_min:
                temp_min = dist[i]
                x, y = i[0], i[1]
        result += dist.pop((x, y))
        # result += dist[(x, y)]
        # del dist[(x, y)]
        for i in dist:
            temp_min = (abs(x - i[0]) + abs(y - i[1]))
            if temp_min < dist[i]:
                dist[i] = temp_min
    return result


# #TESTS
assert native_min_cost_connect_points([[0, 0], [2, 2], [3, 10], [5, 2],
                                       [7, 0]]) == 20

assert native_min_cost_connect_points([[3, 12], [-2, 5], [-4, 1]]) == 18

assert native_min_cost_connect_points([[0, 0], [1, 1], [1, 0], [-1, 1]]) == 4

assert native_min_cost_connect_points([[-14, -14], [-18, 5], [18, -10],
                                       [18, 18], [10, -2]]) == 102

assert min_cost_connect_points([[0, 0], [2, 2], [3, 10], [5, 2], [7, 0]]) == 20

assert min_cost_connect_points([[3, 12], [-2, 5], [-4, 1]]) == 18

assert min_cost_connect_points([[0, 0], [1, 1], [1, 0], [-1, 1]]) == 4

assert min_cost_connect_points([[-14, -14], [-18, 5], [18, -10], [18, 18],
                                [10, -2]]) == 102

X = timeit(lambda: native_min_cost_connect_points([[0, 0], [2, 2], [3, 10],
                                                   [5, 2], [7, 0]]),
           number=1000000)
Y = timeit(
    lambda: min_cost_connect_points([[0, 0], [2, 2], [3, 10], [5, 2], [7, 0]]),
    number=1000000)

print("Native Code Time     :", X)
print("C Extension Code Time:", Y)
