#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <sstream>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int dest;
    int weight;
};

// Structure to represent a node in the graph
struct Node {
    string name;
    vector<Edge> edges;
};

// Comparator for the priority queue
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
        nodes[dest].edges.push_back({src, weight}); // Assuming undirected graph
    }

    string dijkstra(int start, int end) {
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

        return getResult(start, end, distances, previous);
    }

private:
    unordered_map<int, Node> nodes;

    string getResult(int start, int end, const unordered_map<int, int>& distances, const unordered_map<int, int>& previous) {
        stringstream ss;
        ss << "Shortest distance from " << nodes[start].name << " to " << nodes[end].name << ": " << distances.at(end) << endl;
        ss << "Path: ";
        getPath(start, end, previous, ss);
        ss << endl;
        return ss.str();
    }

    void getPath(int start, int current, const unordered_map<int, int>& previous, stringstream &ss) {
        if (current == start) {
            ss << nodes[start].name;
            return;
        }
        getPath(start, previous.at(current), previous, ss);
        ss << " -> " << nodes[current].name;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <start_station_id> <end_station_id>" << endl;
        return 1;
    }

    int start = stoi(argv[1]);
    int end = stoi(argv[2]);

    Graph bangaloreMetro;
    bangaloreMetro.addNode(56, "Konankunte Cross");
    bangaloreMetro.addNode(57, "Doddakallasandra");
    bangaloreMetro.addNode(58, "Vajarahalli");
    bangaloreMetro.addNode(59, "Talaghattapura");
    bangaloreMetro.addNode(60, "Silk Institute");
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
    bangaloreMetro.addEdge(0, 1, 1);
    bangaloreMetro.addEdge(1, 2, 1);
    bangaloreMetro.addEdge(2, 3, 1);
    bangaloreMetro.addEdge(3, 4, 1);
    bangaloreMetro.addEdge(4, 5, 1);
    bangaloreMetro.addEdge(5, 6, 1);
    bangaloreMetro.addEdge(6, 7, 1);
    bangaloreMetro.addEdge(7, 8, 1);
    bangaloreMetro.addEdge(8, 9, 1);
    bangaloreMetro.addEdge(9, 10, 1);
    bangaloreMetro.addEdge(10, 11, 1);
    bangaloreMetro.addEdge(11, 12, 1);
    bangaloreMetro.addEdge(12, 13, 1);
    bangaloreMetro.addEdge(13, 14, 1);
    bangaloreMetro.addEdge(14, 15, 1);
    bangaloreMetro.addEdge(15, 16, 1);
    bangaloreMetro.addEdge(16, 17, 1);
    bangaloreMetro.addEdge(17, 18, 1);
    bangaloreMetro.addEdge(18, 19, 1);
    bangaloreMetro.addEdge(19, 20, 1);
    bangaloreMetro.addEdge(20, 21, 1);
    bangaloreMetro.addEdge(21, 22, 1);
    bangaloreMetro.addEdge(22, 23, 1);
    bangaloreMetro.addEdge(23, 24, 1);
    bangaloreMetro.addEdge(0, 56, 1);
    bangaloreMetro.addEdge(56, 57, 1);
    bangaloreMetro.addEdge(57, 58, 1);
    bangaloreMetro.addEdge(58, 59, 1);
    bangaloreMetro.addEdge(59, 60, 1);

    // Purple edges
    bangaloreMetro.addEdge(25, 26, 1);
    bangaloreMetro.addEdge(26, 27, 1);
    bangaloreMetro.addEdge(27, 28, 1);
    bangaloreMetro.addEdge(28, 29, 1);
    bangaloreMetro.addEdge(29, 30, 1);
    bangaloreMetro.addEdge(30, 31, 1);
    bangaloreMetro.addEdge(31, 32, 1);
    bangaloreMetro.addEdge(32, 33, 1);
    bangaloreMetro.addEdge(33, 10, 1);
    bangaloreMetro.addEdge(10, 34, 1);
    bangaloreMetro.addEdge(34, 35, 1);
    bangaloreMetro.addEdge(35, 36, 1);
    bangaloreMetro.addEdge(36, 37, 1);
    bangaloreMetro.addEdge(37, 38, 1);
    bangaloreMetro.addEdge(38, 39, 1);
    bangaloreMetro.addEdge(39, 40, 1);

    // Yellow edges
    bangaloreMetro.addEdge(3, 41, 1);
    bangaloreMetro.addEdge(41, 42, 1);
    bangaloreMetro.addEdge(42, 43, 1);
    bangaloreMetro.addEdge(43, 44, 1);
    bangaloreMetro.addEdge(44, 45, 1);
    bangaloreMetro.addEdge(45, 46, 1);
    bangaloreMetro.addEdge(46, 47, 1);
    bangaloreMetro.addEdge(47, 48, 1);
    bangaloreMetro.addEdge(48, 49, 1);
    bangaloreMetro.addEdge(49, 50, 1);
    bangaloreMetro.addEdge(50, 51, 1);
    bangaloreMetro.addEdge(51, 52, 1);
    bangaloreMetro.addEdge(52, 53, 1);
    bangaloreMetro.addEdge(53, 54, 1);
    bangaloreMetro.addEdge(54, 55, 1);

    cout << bangaloreMetro.dijkstra(start, end) << endl;

    return 0;
}
