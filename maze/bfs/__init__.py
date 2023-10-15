# order is west / north / south / east
from pyamaze import maze


#  N
# W  E
#  S


def BFS(some_maze: maze):
    # use reverse order because we're using a stack
    directions = ['E', 'S', 'N', 'W']
    start = (some_maze.rows, some_maze.cols)
    target = (1, 1)
    visited = [start]
    queue = [start]
    dfsPath = {}
    while len(queue) > 0:
        currentNode = queue.pop(0)
        if currentNode == target:
            break

        for direction in directions:
            if some_maze.maze_map.get(currentNode)[direction]:
                possibleNextNode = None
                if direction == "E":
                    possibleNextNode = (currentNode[0], currentNode[1] + 1)
                elif direction == "W":
                    possibleNextNode = (currentNode[0], currentNode[1] - 1)
                elif direction == "N":
                    possibleNextNode = (currentNode[0] - 1, currentNode[1])
                elif direction == "S":
                    possibleNextNode = (currentNode[0] + 1, currentNode[1])

                if (possibleNextNode[0] <= some_maze.rows
                        and possibleNextNode[1] <= some_maze.cols
                        and possibleNextNode not in visited):
                    queue.append(possibleNextNode)
                    visited.append(possibleNextNode)
                    dfsPath[possibleNextNode] = currentNode

    cell = target
    directPath = {}
    while cell != start:
        directPath[dfsPath[cell]] = cell
        cell = dfsPath[cell]
    return directPath
