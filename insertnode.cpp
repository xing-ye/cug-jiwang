
#include"insernode.h"

bool Graphmtx::insertVertex(const Router vertex)//���붥��
{

	if (numVertices == maxVertices)
		return false;
	VerticesList[numVertices++] = vertex;
	return true;
}
