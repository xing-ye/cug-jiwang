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
	Router getValue(int i)
	{
		string a = "�޴�·����";
		return (i >= 0 && i <= numVertices) ? VerticesList[i] : a;
	}
	int getWeight(int v1, int v2)
	{
		return (v1 != -1 && v2 != -1) ? Edge[v1][v2] : 0;
	}
	bool insertVertex(const Router vertex);
	bool insertEdge(string s, string n, int cost) { return insertEdge(zhuan(s), zhuan(n), cost); }
	int getFirstNeighbor(int v);
	int getNextNeighbor(int v, int w);
	void CreatGraph(Router V[], int n, RowColWeight E[], int e);//����������Ϣ����ͼ
	void chushihua();
protected:
	Router *VerticesList;		//�����
	int * *Edge;				//�ڽӾ���
	int * Path(int v1, int w);//�±�Ϊv1��·�����±�Ϊw��·��������·�ɱ�
	int zhuan(string n);//����·�������ҵ���Ӧ�±�
	bool insertEdge(int v1, int v2, int cost);
};

#endif