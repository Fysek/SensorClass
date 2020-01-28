from collections import deque


class DataPlot:
    def __init__(self, max_entries = 100):
        self.axis_x = deque(maxlen=max_entries)
        self.axis_y = deque(maxlen=max_entries)
        self.max_entries = max_entries
        self.buf1=deque(maxlen=50)
        self.buf2=deque(maxlen=50)

    def add(self, x, y):
        self.axis_x.append(x)
        self.axis_y.append(y)


class RealtimePlot:
    def __init__(self, axes, plot_arg):
        self.axes = axes
        self.lineplot, = axes.plot([], [], plot_arg)

    def plot(self, dataPlot):
        self.lineplot.set_data(dataPlot.axis_x, dataPlot.axis_y)
        self.axes.set_xlim(min(dataPlot.axis_x), max(dataPlot.axis_x))
        self.axes.set_ylim(min(dataPlot.axis_y)-1, max(dataPlot.axis_y)+1)
        self.axes.relim()


