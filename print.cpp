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

void Graphmtx::PrintItem(string s)	//���·�ɱ�
{
	int v1 = zhuan(s);
		Node *ptr;
		ptr = VerticesList[v1].head;
		while (ptr) {
			cout << "     " << ptr->net_num << "  ";
			cout << "��һ��" << ptr->next_hop << "  ";
			cout << "��СȨֵ" << ptr->distance << endl;
			ptr = ptr->next;
		}
}