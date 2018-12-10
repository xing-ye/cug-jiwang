#pragma once
#ifndef GRAPH_H
#define GRAPH_H
#include<string>
#include"luyou.h"
using namespace std;
const int maxWeight = INT_MAX;
const int DeafultVertices = 30;			//������󶥵��� =n

struct Edge
{
	int dest;			//�ߵ���һ������λ��
	int cost;				//���ϵ�Ȩֵ
	Edge * link;	//��һ������ָ��
	Edge() { cost = maxWeight; }
	Edge(int num, int weight) : dest(num), cost(weight), link(NULL) {}
	bool operator != (Edge& R)const
	{
		return (dest != R.dest) ? true : false;
	}
};

struct Vertex
{
	Router data;
	Edge *adj;			//�������ͷָ��
};

class Graph
{
public:
	Graph(int sz = DeafultVertices) {};
	~Graph() {}
	bool GraphEmpty()const
	{
		if (numEdges == 0)
			return true;
		else
		{
			return false;
		}
	}
	bool GraphFull()const
	{
		if (numVertices == maxVertices || numEdges == maxVertices * (maxVertices - 1) / 2)
			return true;
		else return false;
	}
	int NumberOfVertices() { return numVertices; }		//���ص�ǰ������
	int NunberOfEdges() { return numEdges; }			//���ص�ǰ����
	virtual Router getValue(int i) = 0;							//ȡ����i��ֵ
	virtual int getWeight(int v1, int v2) = 0;					//ȡ�ߣ�v1��v2���ϵ�Ȩֵ
	virtual bool insertVertex(const Router vertex) = 0;			//����һ������vertex
	virtual bool insertEdge(string s, string n, int cost) = 0;		//�����(v1,v2),ȨΪcost
	virtual bool removeVertex(string s) = 0;					//ɾȥ����v��������v��صı�
	virtual bool removeEdge(string s, string n) = 0;				//ɾȥ��(v1,v2)
protected:
	int maxVertices;
	int numEdges;
	int numVertices;
};
#endif