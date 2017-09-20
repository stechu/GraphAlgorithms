 #include <iostream>
 #include <fstream>
 #include <sstream>
 #include <vector>
 #include <string>

 using namespace std;

 struct edge { int to, length;};

 typedef vector< vector<edge> > Graph;

 int dijkstra(const Graph &graph, int source, int target){
    // put your code here
    return 0;
 } 

 /*
 below is an example of how to create load a graph from file
 */
 void loadGraph(Graph &graph, string filename){
    // we first clear the Graph, i.e. delete all existing 
    // elements (if any)
    graph.clear();
    
    ifstream file(filename);

    //read the first line
    string line;
    getline(file, line);
    int n = 0;
    int m = 0; 
    stringstream lineStream(line);
    lineStream >> n >> m;

    //init graph
    for(int i = 0; i < n; i++){
        vector<edge> adj;
        graph.push_back(adj);
    }
    
    //read the rest of lines
    while(getline(file, line)){
        stringstream lineStream(line);
        int s, t, d;
        lineStream >> s >> t >> d;
        edge e = {t, d};
        graph[s].push_back(e);
    }
}

/*
    print graph 
*/
void printGraph(const Graph & g){
    cout<< "number of vertices: "<< g.size() << endl;
    for(int i = 0; i < g.size(); i++){
        cout << i <<" :";
        for(edge e: g[i]){
            cout << "(" << e.to << ", " << e.length << "), ";
        }
        cout << endl;
    }
}


int main(){
    Graph g;
    loadGraph(g, "./test.txt");
    printGraph(g);
    return 0;
}