// https://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;

class Graph
{
    int V; // number of vertices
    list<int> *adjList; // adjacency list
    
    void topologicalSortUtil(int v, bool visited[], stack<int>& Stack)
    {
        visited[v] = true; // mark current as visited

        list<int>::iterator i;
        for (i = adjList[v].begin(); i != adjList[v].end(); i++)
            if (!visited[*i])
                topologicalSortUtil(*i, visited, Stack);
        
        Stack.push(v); // push current element to stack
    }

    public:
    Graph(int v)
    {
        this->V = v;
        adjList = new list<int> [V];
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
    }

    void topologicalSort()
    {
        stack<int> Stack;

        bool* visited = new bool[V];    // initializing all nodes as not visited
        for (int i = 0; i < V; i++)
            visited[i] = false;
        
        for (int i = 0; i < V; i++)
            if (!visited[i])
                topologicalSortUtil(i, visited, Stack);

        // print the content of stack
        while (!Stack.empty())
        {
            cout << (char) ('a' + Stack.top()) << " "; // cast it back to character
            Stack.pop();
        }
    }
};

void printOrder(string words[], int n, int unique_alphabates)
{
    Graph G(unique_alphabates);

    for (int i = 0; i < n - 1; i++)
    {
        string word1 = words[i];
        string word2 = words[i + 1];

        for (int j = 0; j < min(word1.length(), word2.length()); j++)
        {
            if (word1[j] != word2[j]) // put first mismatching charecter to the graph and break
            {
                G.addEdge(word1[j] - 'a', word2[j] - 'a');
                break;
            }
        }
    }

    // print topological sorted order
    G.topologicalSort();
    return;
}

int main()
{
    string words[] = {"caa", "aaa", "aab"};

    printOrder(words, 3, 3);

    return 0;
}