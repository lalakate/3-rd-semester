#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

struct EnergyData {
    struct Date{
        int day;
        int month;
        int year;
    } date;
    int time;
    double globalActivePower;
    double globalReactivePower;
    double Voltage;
    double globalIntensity;
    struct subMetering{
        double first;
        double second;
        double third;
    }subMetering;
};

double stringToDouble(std::string str, int &i){
    double intResult = 0;
    double remainderResult = 0;
    int rang = 0;
    bool isRemainder = false;
    bool isFound = false;
    for ( ; i < str.size(); i++){
        if (str[i] == '/' || str[i] == '\t' || str[i] == ';'){
            if (!isFound) {
                continue;
            }
            else {
                return intResult += remainderResult;
            }
        }
        if (str[i] == '.'){
            isRemainder = true;
            rang = 0;
            continue;
        }
        if (!isRemainder) {
            isFound = true;
            intResult = intResult * 10 + (str[i] - '0');
        }
        else {
            isFound = true;
            rang--;
            remainderResult += (str[i] - '0') * powl(10, rang);
        }
    }
    return intResult += remainderResult;
}

EnergyData::Date parseDate(const std::string &str, int &index) {
    EnergyData::Date date;
    date.day = stringToDouble(str, index);
    date.month = stringToDouble(str, index);
    date.year = stringToDouble(str, index);
    return date;
}

std::vector<EnergyData> readDataFromFile() {
    std::ifstream inputFile("D:/7_2.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open the file." << std::endl;
    }
    std::vector<EnergyData> energyDataList;
    std::string line;

    std::getline(inputFile, line);
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        EnergyData energyData;
        int index = 0;

        energyData.date = parseDate(line, index);
        energyData.time = static_cast<int>(stringToDouble(line, index));
        energyData.globalActivePower = stringToDouble(line, index);
        energyData.globalReactivePower = stringToDouble(line, index);
        energyData.Voltage = stringToDouble(line, index);
        energyData.globalIntensity = stringToDouble(line, index);
        energyData.subMetering.first = stringToDouble(line, index);
        energyData.subMetering.second = stringToDouble(line, index);
        energyData.subMetering.third = stringToDouble(line, index);

        energyDataList.push_back(energyData);
    }

    inputFile.close();
    return energyDataList;
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    std::vector<EnergyData> result = readDataFromFile();

    QLineSeries *series = new QLineSeries();
    for (int i = 0; i < result.size(); ++i) {
        series->append(i, result[i].Voltage);
    }


    QValueAxis *axisX = new QValueAxis;
    axisX->setTitleText("Date");
    QValueAxis *axisY = new QValueAxis;
    axisY->setTitleText("Voltage");

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setAxisX(axisX, series);
    chart->setAxisY(axisY, series);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow mainWindow;
    mainWindow.setCentralWidget(chartView);
    mainWindow.resize(1500, 800);
    mainWindow.show();

    return a.exec();
}
