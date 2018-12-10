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

//边信息类型定义
struct RowColWeight
{
	int row;							//行下标
	int col;							//列下标
	int weight;							//权值
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
	int getFirstNeighbor(int v);
	int getNextNeighbor(int v, int w);
	void Path();//生成路由表

protected:
	Router *VerticesList;		//顶点表
	int * *Edge;				//邻接矩阵
	int * Path(int v1, int w);//下标为v1的路由器下标为w的路由器生成路由表
};

#endif