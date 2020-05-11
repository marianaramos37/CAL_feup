#ifndef CAL_FP05_UTILS_H
#define CAL_FP05_UTILS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>

#include "../GraphViewerLib/graphviewer.h"

#include "Cliente.h"
#include "Estafeta.h"
#include "Restaurante.h"

#include "Graph.h"
#include "EatExpress.h"

extern Graph<int> graph;
extern EatExpress<int> eatExpress;
GraphViewer *gv;

using namespace std;


template <class T>
Vertex<T>* readNode(string tuple) {
    tuple = tuple.substr(1, tuple.size() - 2);
    stringstream ss(tuple);
    string id, latitude, longitude;
    getline(ss, id, ',');
    getline(ss, latitude, ',');
    getline(ss, longitude, ',');
    auto* vertex = new Vertex<T>(stoi(id), stof(latitude), stof(longitude));
    return vertex;
}

template <class T>
void readNodes(string file_directory) {
    ifstream ler;
    string number;
    string tuple;
    ler.open(file_directory);
    getline(ler, number);
    int n = stoi(number);
    for (unsigned int i = 0 ; i < n ; i++) {
        getline(ler, tuple);
        tuple = tuple.substr(1, tuple.size() - 2);

        stringstream ss(tuple);
        string id, latitude, longitude;
        getline(ss, id, ',');
        getline(ss, latitude, ',');
        getline(ss, longitude, ',');
        Vertex<T>* vertex = new Vertex<T>(stoi(id), stof(latitude), stof(longitude));
        graph.addVertex(vertex);
    }
    cout << "Vertex Lidos: " << graph.getNumVertex() << endl;
    // graph.printVertexs();
    ler.close();
}

template <class T>
void readEdges(string file_directory) {
    ifstream ler;
    string number;
    string tuple;
    ler.open(file_directory);
    getline(ler, number);
    int n = stoi(number);
    for (unsigned int i = 0 ; i < n ; i++) {
        getline(ler, tuple);
        tuple = tuple.substr(1, tuple.size() - 2);

        stringstream ss(tuple);
        string id1, id2;
        getline(ss, id1, ',');
        getline(ss, id2, ',');
        graph.addEdge(stoi(id1), stoi(id2));
    }
    cout << "Edge Lidos: " << graph.getNumEdges() << endl;
    // graph.printEdges();
    ler.close();
}

void readMap(string directory) {
    string nodes_path = directory + "/nodes.txt";
    string edges_path = directory + "/edges.txt";
    readNodes<int>(nodes_path);
    readEdges<int>(edges_path);
}

template <class T>
void readTags(string file_directory) {

}

void Visualizar_Mapa() {
    gv = new GraphViewer(600, 600, false);
    gv->createWindow(600, 600);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");
    for (Vertex<int>* vertex : graph.getVertexSet()) {
        gv->addNode(vertex->getInfo(), vertex->getLatitude(), vertex->getLongitude());
    }
    int edgeID = 0;
    for (Vertex<int>* vertex : graph.getVertexSet()) {
        for (Edge<int> edge : vertex->getAdj()) {
            gv->addEdge(edgeID,vertex->getInfo(), edge.getDest()->getInfo(), EdgeType::DIRECTED);
            edgeID++;
        }
    }
    gv->rearrange();
}

template<class T>
void recolher_info_clientes(){
    vector<Cliente<T>*> v;
    Cliente<T>* cliente1 = new Cliente<T>("Antonio", "123456789", 2);
    Cliente<T>* cliente2 = new Cliente<T>("Joaquim", "987654321", 6);
    Cliente<T>* cliente3 = new Cliente<T>("Manuel", "999999999", 12);
    v.push_back(cliente1);
    v.push_back(cliente2);
    v.push_back(cliente3);
    eatExpress.setClientes(v);
    for (Vertex<int>* vertex : graph.getVertexSet()) {
        if(vertex->getInfo()==2){
            //gv->removeNode(2);
            //gv->addNode(2);
        }
    }
    return;
}

template <class T>
void recolher_info_restaurantes(){

}
template <class T>
void recolher_info_estafetas(){

}

template <class T>
void buildApp(){
    recolher_info_clientes<T>();
    Visualizar_Mapa();
}

#endif //CAL_FP05_UTILS_H
