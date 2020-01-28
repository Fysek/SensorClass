import datetime


class Data:
    def __init__(self, datetime="", temperature="", humidity="", pressure="", gasResistance="", proximity="",
                 smokeLevel="", distance=""):
        self.datetime = datetime
        self.temperature = temperature
        self.humidity = humidity
        self.pressure = pressure
        self.gasResistance = gasResistance
        self.proximity = proximity
        self.smokeLevel = smokeLevel
        self.distance = distance

    def __str__(self):
        return "Temperature: " + self.temperature + " degC" + ", Humidity: " + self.humidity + " %rH" \
                + ", Pressure: " + self.pressure + " hPa" + ", Gas resistance: " + self.gasResistance + " kOhms" \
                + ", Proximity: " + self.proximity + " %" + ", Smoke level: " + self.smokeLevel + " %" \
                + ", Distance: " + self.distance + " m"

    def reparse_data(self, data):
        meas_list = data.split()
        datetime_str = meas_list[0] + " " + meas_list[1]
        self.datetime = datetime.datetime.strptime(datetime_str, '%Y/%m/%d %H:%M:%S')
        self.temperature = meas_list[3]
        self.humidity = meas_list[6]
        self.pressure = meas_list[9]
        self.gasResistance = meas_list[13]
        self.proximity = meas_list[16]
        self.smokeLevel = meas_list[20]
        self.distance = meas_list[23]

