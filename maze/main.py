from dfs import DFS
from pyamaze import maze, COLOR, agent


def main():
    m = maze(5, 5)
    m.CreateMaze()
    # print(m.)
    #  1 is open, 0 is blocked
    path = DFS(m)
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
