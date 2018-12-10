 #pragma once
#ifndef ROUTER_H
#define ROUTER_H
#include<string>
#include <iostream>
using namespace std;
struct Node
{
	string net_num;//����ţ�Ŀ��
	int distance;//����
	string next_hop;//��һ��
	Node *next;
	Node() :next(NULL) {}
	Node(string x, int y, string z, Node *n = NULL) :net_num(x), distance(y), next_hop(z), next(n) {};
};
struct Router//·����
{
	string name;//·������
	Node *head;//·�ɱ�ͷ
	Router() :head(NULL) {}
	Router(string n) :name(n), head(NULL) {}
};
#endif
