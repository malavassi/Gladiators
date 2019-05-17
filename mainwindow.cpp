#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Plot->addGraph();
    ui->Plot->xAxis->setLabel("Numero de generacion");
    ui->Plot->yAxis->setLabel("Resistencia promedio");
    ui->Plot->graph(0)->setScatterStyle(QCPScatterStyle::ssDisc);
    ui->Plot->graph()->setLineStyle(QCPGraph::lsLine);
    QPen pen;
    pen.setColor(QColor(Qt::blue));
    pen.setStyle(Qt::DashLine);
    pen.setWidthF(2.5);
    ui->Plot->graph()->setPen(pen);
    ui->Plot->graph()->setBrush(QBrush(QColor(255,200,20,70)));
    ui->Plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->Plot->xAxis->setRange(0, 100);
    ui->Plot->yAxis->setRange(0, 100);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPoint(double x, double y)
{
  qv_x.append(x);
  qv_y.append(y);
  plot();

}

void MainWindow::plot()
{
    ui->Plot->graph(0)->setData(qv_x, qv_y);
    ui->Plot->replot();
    ui->Plot->update();
}

