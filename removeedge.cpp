#include"removeedge.h"

bool Graphmtx::removeEdge(string s, string n)
{

	int v1 = zhuan(s);
	int v2 = zhuan(n);
	if (v1 > -1 && v1< numVertices && v2>-1 && v2 < numVertices && Edge[v1][v2] > 0 && Edge[v1][v2] < maxWeight)
	{
		Edge[v1][v2] = Edge[v2][v1] = maxWeight;
		numEdges--;
		return true;
	}
	else
	{
		return false;
	}
}