#pragma once
#ifndef GRAPHMTX_H
#define GRAPHMTX_H
#include"luyou.h"
#include "Graph.h"
#include<string>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
using namespace std;

//����Ϣ���Ͷ���
struct RowColWeight
{
	int row;							//���±�
	int col;							//���±�
	int weight;							//Ȩֵ
};

class Graphmtx : public Graph
{
public:
	Graphmtx(int sz = DeafultVertices);
	~Graphmtx()
	{
		delete[] VerticesList;
		delete[] Edge;
	}
	bool removeEdge(string s, string n);
protected:
	Router *VerticesList;		//�����
	int * *Edge;				//�ڽӾ���
	int * Path(int v1, int w);//�±�Ϊv1��·�����±�Ϊw��·��������·�ɱ�
	int zhuan(string n);//����·�������ҵ���Ӧ�±�
};

#endif