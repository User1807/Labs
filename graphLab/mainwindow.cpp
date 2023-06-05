// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAddVertex_triggered()
{
    graph.addVertex();
    drawGraph();
}

void MainWindow::on_actionRemoveVertex_triggered()
{
    bool ok;
    int vertex = QInputDialog::getInt(this, "Remove Vertex", "Enter vertex to remove:", 0, 0, graph.adjacencyList.size() - 1, 1, &ok);
    if (ok) {
        graph.removeVertex(vertex);
        drawGraph();
    }
}

void MainWindow::on_actionAddEdge_triggered()
{
    bool ok;
    int source = QInputDialog::getInt(this, "Add Edge", "Enter source vertex:", 0, 0, graph.adjacencyList.size() - 1, 1, &ok);
    if (!ok)
        return;

    int destination = QInputDialog::getInt(this, "Add Edge", "Enter destination vertex:", 0, 0, graph.adjacencyList.size() - 1, 1, &ok);
    if (!ok)
        return;

    int weight = QInputDialog::getInt(this, "Add Edge", "Enter edge weight:", 0, 0, INT_MAX, 1, &ok);
    if (ok) {
        graph.addEdge(source, destination, weight);
        drawGraph();
    }
}

void MainWindow::on_actionRemoveEdge_triggered()
{
    bool ok;
    int source = QInputDialog::getInt(this, "Remove Edge", "Enter source vertex:", 0, 0, graph.adjacencyList.size() - 1, 1, &ok);
    if (!ok)
        return;

    int destination = QInputDialog::getInt(this, "Remove Edge", "Enter destination vertex:", 0, 0, graph.adjacencyList.size() - 1, 1, &ok);
    if (ok) {
        graph.removeEdge(source, destination);
        drawGraph();
    }
}

void MainWindow::on_actionSetWeight_triggered()
{
    bool ok;
    int source = QInputDialog::getInt(this, "Set Weight", "Enter source vertex:", 0, 0, graph.adjacencyList.size() - 1, 1, &ok);
    if (!ok)
        return;

    int destination = QInputDialog::getInt(this, "Set Weight", "Enter destination vertex:", 0, 0, graph.adjacencyList.size() - 1, 1, &ok);
    if (!ok)
        return;

    int weight = QInputDialog::getInt(this, "Set Weight", "Enter new edge weight:", 0, 0, INT_MAX, 1, &ok);
    if (ok) {
        graph.setEdgeWeight(source, destination, weight);
        drawGraph();
    }
}

void MainWindow::on_actionBFS_triggered()
{
    bool ok;
    int startVertex = QInputDialog::getInt(this, "BFS", "Enter start vertex:", 0, 0, graph.adjacencyList.size() - 1, 1, &ok);
    if (ok) {
        QList<int> traversal = graph.breadthFirstSearch(startVertex);
        QString message = "BFS traversal: ";
        for (int vertex : traversal) {
            message += QString::number(vertex) + " ";
        }
        QMessageBox::information(this, "BFS", message);
    }
}

void MainWindow::on_actionDFS_triggered()
{
    bool ok;
    int startVertex = QInputDialog::getInt(this, "DFS", "Enter start vertex:", 0, 0, graph.adjacencyList.size() - 1, 1, &ok);
    if (ok) {
        QList<int> traversal = graph.depthFirstSearch(startVertex);
        QString message = "DFS traversal: ";
        for (int vertex : traversal) {
            message += QString::number(vertex) + " ";
        }
        QMessageBox::information(this, "DFS", message);
    }
}

void MainWindow::on_actionDijkstra_triggered()
{
    bool ok;
    int startVertex = QInputDialog::getInt(this, "Dijkstra", "Enter start vertex:", 0, 0, graph.adjacencyList.size() - 1, 1, &ok);
    if (ok) {
        QList<int> distances = graph.dijkstraAlgorithm(startVertex);
        QString message = "Shortest distances from vertex ";
        message += QString::number(startVertex) + ":\n";
        for (int i = 0; i < distances.size(); ++i) {
            message += "To vertex " + QString::number(i) + ": ";
            if (distances[i] == INT_MAX)
                message += "Infinity\n";
            else
                message += QString::number(distances[i]) + "\n";
        }
        QMessageBox::information(this, "Dijkstra", message);
    }
}

void MainWindow::drawGraph()
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    for (int i = 0; i < graph.adjacencyList.size(); ++i) {
        scene->addEllipse(i * 50, 0, 30, 30); // Draw vertex as ellipse
        scene->addText(QString::number(i))->setPos(i * 50 + 10, 5); // Add vertex label
        for (const auto &edge : graph.adjacencyList[i]) {
            scene->addLine(edge.source * 50 + 15, 30, edge.destination * 50 + 15, 30)->setPen(QPen(Qt::black, 2)); // Draw edge as line
            scene->addText(QString::number(edge.weight))->setPos((edge.source + edge.destination) * 25 + 15, 33); // Add edge weight
        }
    }
    ui->graphicsView->setScene(scene);
}
