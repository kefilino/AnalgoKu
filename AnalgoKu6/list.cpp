/*
 * Nama     : Kefilino Khalifa Filardi
 * NPM      : 140810180028
 * Kelas    : B
 * Program  : Program Undirected Graph
 * Tanggal  : 5 April 2020
 * Desc     : Program ini mengimplemen undirected graph dengan menggunakan adjacency list.
 */

#include <iostream>
using namespace std;

struct edge {
    int data;
    edge *next;
};

struct node {
    int data;
    node *next;
    edge *edge;
};

void create(node *&newNode)
{
    newNode = new node;
    newNode->next = NULL;
    newNode->edge = NULL;
    cin >> newNode->data;
}

void create(edge *&newEdge)
{
    newEdge = new edge;
    newEdge->next = NULL;
    cin >> newEdge->data;
}

void insert(node *&list, node *newNode)
{
    if (list == NULL)
        list = newNode;
    else {
        node *temp = list;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

void insert(node *&parent, edge *newEdge)
{
    if (parent->edge == NULL)
        parent->edge = newEdge;
    else {
        edge *temp = parent->edge;
        while (temp->next)
            temp = temp->next;
        temp->next = newEdge;
    }
}

void print(node *list)
{
    if (list == NULL)
        cout << "List simpul kosong." << endl;
    else {
        cout << "\nAdjacency list dari undirected graph : ";
        node *temp = list;
        while (temp) {
            edge *trav = temp->edge;

            cout << endl << temp->data << ": ";
            while (trav)
            {
                cout << trav->data;
                if (trav->next)
                    cout << "->";
                trav = trav->next;
            }

            temp = temp->next;
        }
    }
}

int main()
{
    node *n, *list = NULL;
    edge *e;
    int s, g;

    cout << "Banyak simpul dalam graph : ";
    cin >> s;

    for (int i = 0; i < s; i++) {
        cout << endl << "Nilai simpul ke-" << i+1 << " : ";
        create(n);
        insert(list, n);

        cout << "Banyak garis dari simpul " << n->data << " : ";
        cin >> g;

        for (int j = 0; j < g; j++) {
            cout << "Simpul garis ke-" << j+1 << " : ";
            create(e);
            insert(n, e);
        }
    }

    print(list);
}