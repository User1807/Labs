// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graph.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAddVertex_triggered();
    void on_actionRemoveVertex_triggered();
    void on_actionAddEdge_triggered();
    void on_actionRemoveEdge_triggered();
    void on_actionSetWeight_triggered();
    void on_actionBFS_triggered();
    void on_actionDFS_triggered();
    void on_actionDijkstra_triggered();

private:
    void drawGraph();

    Ui::MainWindow *ui;
    Graph graph;
};

#endif // MAINWINDOW_H
