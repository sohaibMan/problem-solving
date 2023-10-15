from typing import List

from bfs import BFS
from pyamaze import maze, agent


def isEscapePossible(blocked: List[List[int]], source: List[int], target: List[int]) -> bool:
    """
    :param blocked:  blocked[i] = [xi, yi] represents a blocked square with coordinates (xi, yi).
    :param source:   [sx, sy] square
    :param target:  target [tx, ty] square.
    :return:

    There are 1 million by 1 million grid on an XY-plane, and the coordinates of each grid square are (x, y).
    We start at the source = and want to reach

    Each move, we can walk one square north, east, south, or west if the square is not in the array of blocked squares.
     We are also not allowed to walk outside the grid.

    Return true if and only if it is possible to reach the target square from the source square through a
    sequence of valid moves.

    Constraints:

    0 <= blocked.length <= 200
    blocked[i].length == 2
    0 <= xi, yi < 106
    source.length == target.length == 2
    0 <= sx, sy, tx, ty < 106
    source != target
    It is guaranteed that source and target are not blocked.
    """
    visited = [source]
    frontier = [source]
    while len(frontier) > 1:
        currentNode = frontier.pop()
        if currentNode == target:
            return True


def main():
    m = maze(50, 50)
    m.CreateMaze()
    # print(m.)
    #  1 is open, 0 is blocked
    # path = DFS(m)
    path = BFS(m)
    a = agent(m, footprints=True)
    m.tracePath({a: path})
    m.run()
    # 5 by 5 maze( 5 rows and 5 columns)

    # # m = maze()
    # m = maze(20, 30)
    # # m.CreateMaze()
    # m.CreateMaze(5, 5, pattern='h', theme=COLOR.light, loopPercent=1)
    # # m.CreateMaze(loopPercent=100)
    #
    # # a=agent(m,5,4)
    # # print(a.x)
    # # print(a.y)
    # # print(a.position)
    #
    # a = agent(m, footprints=True, filled=True)
    # b = agent(m, 5, 5, footprints=True, color=COLOR.red)
    # c = agent(m, 4, 1, footprints=True, color=COLOR.green, shape='arrow')
    #
    # # m.enableArrowKey(a)
    # # m.enableWASD(b)
    #
    # path2 = [(5, 4), (5, 3), (4, 3), (3, 3), (3, 4), (4, 4)]
    # path3 = 'WWNNES'
    #
    # # l1=textLabel(m,'Total Cells',m.rows*m.cols)
    # # l1=textLabel(m,'Total Cells',m.rows*m.cols)
    # # l1=textLabel(m,'Total Cells',m.rows*m.cols)
    # # l1=textLabel(m,'Total Cells',m.rows*m.cols)
    #
    # m.tracePath({a: m.path, b: path2, c: path3}, delay=200, kill=True)
    #
    # m.run()


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    main()
