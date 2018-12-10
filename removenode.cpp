#include"removenode.h"
bool Graphmtx::removeVertex(string n)
{

	int v = zhuan(n);
	if (v < 0 && v >= numVertices)
		return false;
	if (numVertices == 1)
		return false;

	int i, j;
	for (i = 0; i < numVertices; i++)
	{
		Edge[i][v] = maxWeight;
	}
	for (j = 0; j < numVertices; j++)
		Edge[v][j] = maxWeight;

	Node *ptr;
	for (int v1 = 0; v1 < numVertices; v1++) {
		ptr = VerticesList[v1].head;
		while (ptr) {
			VerticesList[v1].head = ptr->next;
			delete ptr;
			ptr = VerticesList[v1].head;
		}
	}
	return true;
}