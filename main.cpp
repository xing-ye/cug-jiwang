#include "main.h"

using namespace std;
const int MaxVertices = 100;	//ͼ�е���󶥵���Ŀ
const int MaxWeight = 16;	//������Ȩֵ



void meau() {
	cout << "��ѡ���ܣ�\n";
	cout << "    1�����ָ��·������·�ɱ�\n";
	cout << "    2�����·����\n";
	cout << "    3����ӱ�\n";
	cout << "    4��ɾ��·����\n";
	cout << "    5��ɾ����\n";
	cout << "    6���˳�\n ";
	cout << " ������ѡ�";
}
int main()
{
	Router v1[] = { { "1" },{ "2" }, { "3" }, { "4" }, { "5" }, { "6" }, { "7" }, { "8" }, { "9" } };//������Ϣ
	RowColWeight rcw1[] = { { 0, 1, 2 }, { 0, 5, 1 }, { 0, 6, 1 },	{ 1, 2, 2 }, { 1, 3, 4 },	{ 2, 3, 1 }, 
	{ 2, 5, 3 }, { 2, 6, 2 },	{ 3, 4, 1 }, { 3, 6, 6 }, { 3, 7, 5 },{ 3, 8, 2 },{ 4, 5, 5 },{ 5, 6, 1 },
	{ 6, 7, 3 },	{ 7, 8, 2 } };//����Ϣ
	int d = 9, e = 16;
	Graphmtx g1;
	g1.CreatGraph(v1, d, rcw1, e);
	cout << "·�ɱ����ɳɹ���" << endl;
	meau();
	int ch; string s, n; int c;
	cin >> ch;
	while (1) {
		switch (ch) {
		case 1:
			g1.chushihua();
			g1.Path();
			cout << "������·��������" << endl;
			cin >> s;
			g1.PrintItem(s);
			break;
		case 2:
			cout << "����������·��������" << endl;
			cin >> s;
			g1.insertVertex(s);
			break;
		case 3:
			cout << "������ߵĶ˵㼰Ȩֵ��" << endl;
			cin >> s >> n >> c;
			g1.insertEdge(s, n, c); break;
		case 4:
			cout << "��������Ҫɾ��·������" << endl;
			cin >> s;
			g1.removeVertex(s); break;
		case 5:
			cout << "��������Ҫɾ���ߵ������˵㣺" << endl;
			cin >> s >> n;
			g1.removeEdge(s, n); break;
		case 6:return 0;
		default:cout << "�������" << endl;
		}
		meau(); cin >> ch;
	}
	return 0;
}
