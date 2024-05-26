#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int dest;
    int weight;
};

struct Node {
    string name;
    vector<Edge> edges;
};

struct CompareDist {
    bool operator()(pair<int, int> const& p1, pair<int, int> const& p2) {
        return p1.second > p2.second;
    }
};

class Graph {
public:
    void addNode(int id, const string& name) {
        nodes[id] = { name, {} };
    }

    void addEdge(int src, int dest, int weight) {
        nodes[src].edges.push_back({dest, weight});
        nodes[dest].edges.push_back({src, weight}); 
    }

    void dijkstra(int start, int end) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, CompareDist> pq; 
        unordered_map<int, int> distances;
        unordered_map<int, int> previous;

        for (const auto& node : nodes) {
            distances[node.first] = numeric_limits<int>::max();
        }

        distances[start] = 0;
        pq.push({start, 0});

        while (!pq.empty()) {
            int current = pq.top().first;
            pq.pop();

            if (current == end) break;

            for (const auto& edge : nodes[current].edges) {
                int neighbor = edge.dest;
                int newDist = distances[current] + edge.weight;

                if (newDist < distances[neighbor]) {
                    distances[neighbor] = newDist;
                    pq.push({neighbor, newDist});
                    previous[neighbor] = current;
                }
            }
        }

        printResult(start, end, distances, previous);
    }

private:
    unordered_map<int, Node> nodes;

    void printResult(int start, int end, const unordered_map<int, int>& distances, const unordered_map<int, int>& previous) {
        cout << "Shortest distance from " << nodes[start].name << " to " << nodes[end].name << ": " << distances.at(end) << endl;
        cout << "Path: ";
        cout<<endl;
        printPath(start, end, previous);
        cout << endl;
    }

    void printPath(int start, int current, const unordered_map<int, int>& previous) {
        if (current == start) {
            cout << nodes[start].name;
            return;
        }
        printPath(start, previous.at(current), previous);
        cout << " -> " << nodes[current].name;
    }
};

int main() {
    Graph bangaloreMetro;

    //green

    bangaloreMetro.addNode(0, "Yelachenahalli");
    bangaloreMetro.addNode(1, "JP Nagar");
    bangaloreMetro.addNode(2, "Banashankari");
    bangaloreMetro.addNode(3, "Rashtriya Vidyalaya Road");
    bangaloreMetro.addNode(4, "Jayanagar");
    bangaloreMetro.addNode(5, "South End Circle");
    bangaloreMetro.addNode(6, "Lalbagh");
    bangaloreMetro.addNode(7, "National College");
    bangaloreMetro.addNode(8, "KR Market");
    bangaloreMetro.addNode(9, "Chikpet");
    bangaloreMetro.addNode(10, "Majestic");
    bangaloreMetro.addNode(11, "Sampige Road");
    bangaloreMetro.addNode(12, "Srirampura");
    bangaloreMetro.addNode(13, "Kuvempu Road");
    bangaloreMetro.addNode(14, "Rajajinagar");
    bangaloreMetro.addNode(15, "Mahalaxmi");
    bangaloreMetro.addNode(16, "Nagasandra");
    bangaloreMetro.addNode(17, "Sandal Soap Factory");
    bangaloreMetro.addNode(18, "Yeshwantpur");
    bangaloreMetro.addNode(19, "Gorguntepalya");
    bangaloreMetro.addNode(20, "Peenya");
    bangaloreMetro.addNode(21, "Peenya Industry");
    bangaloreMetro.addNode(22, "Jalahalli");
    bangaloreMetro.addNode(23, "Dasarahalli");
    bangaloreMetro.addNode(24, "Nagasandra");


    // Purple 
    bangaloreMetro.addNode(25, "Baiyappanahalli");
    bangaloreMetro.addNode(26, "Swami Vivekananda Road");
    bangaloreMetro.addNode(27, "Indiranagar");
    bangaloreMetro.addNode(28, "Halasuru");
    bangaloreMetro.addNode(29, "Trinity");
    bangaloreMetro.addNode(30, "MG Road");
    bangaloreMetro.addNode(31, "Cubbon Park");
    bangaloreMetro.addNode(32, "Vidhana Soudha");
    bangaloreMetro.addNode(33, "Sir M Visveswaraya");
    bangaloreMetro.addNode(34, "City Railway Station");
    bangaloreMetro.addNode(35, "Magadi Road");
    bangaloreMetro.addNode(36, "Hosahalli");
    bangaloreMetro.addNode(37, "Vijaynagar");
    bangaloreMetro.addNode(38, "Attiguppe");
    bangaloreMetro.addNode(39, "Deepanjali Nagar");
    bangaloreMetro.addNode(40, "Mysore Road");

    // Yellow 
    bangaloreMetro.addNode(41, "Ragigudda");
    bangaloreMetro.addNode(42, "Jayadeva");
    bangaloreMetro.addNode(43, "BTM Layout");
    bangaloreMetro.addNode(44, "Silkboard");
    bangaloreMetro.addNode(45, "HSR Layout");
    bangaloreMetro.addNode(46, "Oxford College");
    bangaloreMetro.addNode(47, "Muneshwar Nagar");
    bangaloreMetro.addNode(48, "Chikka Begur");
    bangaloreMetro.addNode(49, "Basapura Road");
    bangaloreMetro.addNode(50, "Hosa Road");
    bangaloreMetro.addNode(51, "Electronic City 1");
    bangaloreMetro.addNode(52, "Electronic City 2");
    bangaloreMetro.addNode(53, "Hoskuru");
    bangaloreMetro.addNode(54, "Hebbagodi");
    bangaloreMetro.addNode(55, "Bommasandra");


    // Green edges
    bangaloreMetro.addEdge(0, 1, 2);
    bangaloreMetro.addEdge(1, 2, 2);
    bangaloreMetro.addEdge(2, 3, 2);
    bangaloreMetro.addEdge(3, 4, 2);
    bangaloreMetro.addEdge(4, 5, 2);
    bangaloreMetro.addEdge(5, 6, 2);
    bangaloreMetro.addEdge(6, 7, 2);
    bangaloreMetro.addEdge(7, 8, 2); 
    bangaloreMetro.addEdge(8, 9, 2);
    bangaloreMetro.addEdge(9, 10, 2);
    bangaloreMetro.addEdge(10, 11, 2);
    bangaloreMetro.addEdge(11, 12, 2);
    bangaloreMetro.addEdge(12, 13, 2);
    bangaloreMetro.addEdge(13, 14, 2);
    bangaloreMetro.addEdge(14, 15, 2);
    bangaloreMetro.addEdge(15, 16, 2);
    bangaloreMetro.addEdge(16, 17, 2);
    bangaloreMetro.addEdge(17, 18, 2);
    bangaloreMetro.addEdge(18, 19, 2);
    bangaloreMetro.addEdge(19, 20, 2);
    bangaloreMetro.addEdge(20, 21, 2);
    bangaloreMetro.addEdge(21, 22, 2);
    bangaloreMetro.addEdge(22, 23, 2);
    bangaloreMetro.addEdge(23, 24, 2);


    // Purple edges
    bangaloreMetro.addEdge(25, 26, 2);
    bangaloreMetro.addEdge(26, 27, 2);
    bangaloreMetro.addEdge(27, 28, 2);
    bangaloreMetro.addEdge(28, 29, 2);
    bangaloreMetro.addEdge(29, 30, 2);
    bangaloreMetro.addEdge(30, 31, 2);
    bangaloreMetro.addEdge(31, 32, 2);
    bangaloreMetro.addEdge(32, 33, 2);
    bangaloreMetro.addEdge(33, 10, 2);
    bangaloreMetro.addEdge(10, 34, 2);
    bangaloreMetro.addEdge(34, 35, 2);
    bangaloreMetro.addEdge(35, 36, 2);
    bangaloreMetro.addEdge(36, 37, 2);
    bangaloreMetro.addEdge(37, 38, 2);
    bangaloreMetro.addEdge(38, 39, 2);
    bangaloreMetro.addEdge(39, 40, 2);

    // Yellow edges
    bangaloreMetro.addEdge(3, 41, 2); 
    bangaloreMetro.addEdge(41, 42, 2);
    bangaloreMetro.addEdge(42, 43, 2);
    bangaloreMetro.addEdge(43, 44, 2);
    bangaloreMetro.addEdge(44, 45, 2);
    bangaloreMetro.addEdge(45, 46, 2);
    bangaloreMetro.addEdge(46, 47, 2);
    bangaloreMetro.addEdge(47, 48, 2);
    bangaloreMetro.addEdge(48, 49, 2);
    bangaloreMetro.addEdge(49, 50, 2);
    bangaloreMetro.addEdge(50, 51, 2);
    bangaloreMetro.addEdge(51, 52, 2);
    bangaloreMetro.addEdge(52, 53, 2);
    bangaloreMetro.addEdge(53, 54, 2);
    bangaloreMetro.addEdge(54, 55, 2);

    bangaloreMetro.dijkstra(0, 40);

    return 0;
}
