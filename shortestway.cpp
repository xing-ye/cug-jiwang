#include"shortestway.h"

int Graphmtx::getNextNeighbor(int v, int w)
{
	if (v != -1 && w != -1)
	{
		for (int col = w + 1; col < numVertices; col++)
		if (Edge[v][col] > 0 && Edge[v][col] < maxWeight)
			return col;
	}
	return -1;
}
void  Graphmtx::Path()
{

	int n = NumberOfVertices();
	for (int i = 0; i < n; i++) {
		for (int v1 = 0; v1 < n; v1++) {
			int w = getFirstNeighbor(v1);
			Path(v1, w);
			while (1) {
				w = getNextNeighbor(v1, w);
				if (w == -1)break;
				Path(v1, w);
			}
		}
	}
}

int * Graphmtx::Path(int v1, int w)
{
	Node *head, *ptr1, *ptr2, *cur = NULL;
	ptr1 = head = getValue(w).head;
	while (ptr1) {
		int j = 0;
		ptr2 = VerticesList[v1].head;
		while (ptr2) {
			if (ptr1->net_num != ptr2->net_num) {
				if (!ptr2->next) {
					cur = ptr2;
				}
				ptr2 = ptr2->next;
				continue;
			}
			else if (ptr1->distance + getWeight(v1, w) < ptr2->distance) {
				j++;
				ptr2->distance = ptr1->distance + getWeight(v1, w);
				ptr2->next_hop = getValue(w).name;
				break;
			}
			else {
				j++;
				break;
			}
			if (!ptr2->next)
				cur = ptr2;
			ptr2 = ptr2->next;
		}
		//if (j == 0) {
		if (j == 0 && getValue(v1).name != ptr1->net_num) {
			ptr2 = cur;
			ptr2->next = new Node;
			ptr2 = ptr2->next;
			ptr2->net_num = ptr1->net_num;
			ptr2->distance = ptr1->distance + getWeight(v1, w);
			ptr2->next_hop = getValue(w).name;
			break;
		}
		ptr1 = ptr1->next;

	}
	return NULL;
}