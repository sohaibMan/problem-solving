function merge(intervals: number[][]): number[][] {

    intervals.sort((i, j) => i[0] - j[0]);
    const intervalsOut: number[][] = [];
    let currentInterval = intervals[0];
    intervalsOut.push(currentInterval);
    for (let i = 0; i < intervals.length; i++) {
        if (intervals[i][0] <= currentInterval[1]) {
            currentInterval[1] = currentInterval[1] > intervals[i][1] ? currentInterval[1] : intervals[i][1];
        }
        else {
            currentInterval = intervals[i];
            intervalsOut.push(currentInterval);
        }
    }


    return intervalsOut;

};