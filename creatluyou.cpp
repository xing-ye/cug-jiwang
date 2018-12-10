#include"creatluyou.h"

void  Graphmtx::chushihua() //��ʼ��
{
	Node *ptr;
	int n = NumberOfVertices();
	for (int v1 = 0; v1 < n; v1++) {
		int w = getFirstNeighbor(v1);
		ptr = VerticesList[v1].head = new Node(getValue(w).name, getWeight(v1, w), "��");
		while (1) {
			w = getNextNeighbor(v1, w);
			if (w == -1)break;
			ptr->next = new Node(getValue(w).name, getWeight(v1, w), "��");
			ptr = ptr->next;
		}
	}
}
void Graphmtx::CreatGraph(Router V[], int n, RowColWeight E[], int e)//
//��ͼG�в���n������V��e����int
{
	//��ͼG�в���n������
	for (int i = 0; i < n; i++)
		insertVertex(V[i]);

	//��ͼG�в���e����
	for (int k = 0; k < e; k++)
		insertEdge(E[k].row, E[k].col, E[k].weight);
}

int Graphmtx::getFirstNeighbor(int v)
{
	if (v != -1)
	{
		for (int col = 0; col < numVertices; col++)
		if (Edge[v][col] > 0 && Edge[v][col] < maxWeight)
			return col;
	}
	return -1;
}

Graphmtx::Graphmtx(int sz /* = DefaultVertices */) //����
{
	maxVertices = sz;
	numVertices = 0;
	numEdges = 0;
	int i, j;
	VerticesList = new Router[maxVertices];
	Edge = (int **) new int*[maxVertices];
	for (i = 0; i < maxVertices; i++)
		Edge[i] = new int[maxVertices];
	for (i = 0; i < maxVertices; i++)
	for (j = 0; j < maxVertices; j++)
		Edge[i][j] = (i == j) ? 0 : maxWeight;
}

