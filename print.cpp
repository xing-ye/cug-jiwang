#include"print.h"

int Graphmtx::zhuan(string n)
{
	for (int i = 0; i < numVertices; i++)
	{
		if (VerticesList[i].name == n)
			return i;
	}
	return -1;
}

void Graphmtx::PrintItem(string s)	//输出路由表
{
	int v1 = zhuan(s);
		Node *ptr;
		ptr = VerticesList[v1].head;
		while (ptr) {
			cout << "     " << ptr->net_num << "  ";
			cout << "下一跳" << ptr->next_hop << "  ";
			cout << "最小权值" << ptr->distance << endl;
			ptr = ptr->next;
		}
}