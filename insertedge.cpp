#include"insertedge.h"

bool Graphmtx::insertEdge(int v1, int v2, int cost)//²åÈë±ß
{

	if (v1 > -1 && v1< numVertices && v2>-1 && v2 < numVertices && Edge[v1][v2] == maxWeight)
	{
		Edge[v1][v2] = Edge[v2][v1] = cost;
		numEdges++;
		return true;
	}
	else return false;
}
