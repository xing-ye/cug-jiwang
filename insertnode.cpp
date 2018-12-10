
#include"insernode.h"

bool Graphmtx::insertVertex(const Router vertex)//≤Â»Î∂•µ„
{

	if (numVertices == maxVertices)
		return false;
	VerticesList[numVertices++] = vertex;
	return true;
}
