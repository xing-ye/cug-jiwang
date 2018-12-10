#include "main.h"

using namespace std;
const int MaxVertices = 100;	//图中的最大顶点数目
const int MaxWeight = 16;	//无穷大的权值



void meau() {
	cout << "请选择功能：\n";
	cout << "    1、输出指定路由器的路由表\n";
	cout << "    2、添加路由器\n";
	cout << "    3、添加边\n";
	cout << "    4、删除路由器\n";
	cout << "    5、删除边\n";
	cout << "    6、退出\n ";
	cout << " 请输入选项：";
}
int main()
{
	Router v1[] = { { "1" },{ "2" }, { "3" }, { "4" }, { "5" }, { "6" }, { "7" }, { "8" }, { "9" } };//顶点信息
	RowColWeight rcw1[] = { { 0, 1, 2 }, { 0, 5, 1 }, { 0, 6, 1 },	{ 1, 2, 2 }, { 1, 3, 4 },	{ 2, 3, 1 }, 
	{ 2, 5, 3 }, { 2, 6, 2 },	{ 3, 4, 1 }, { 3, 6, 6 }, { 3, 7, 5 },{ 3, 8, 2 },{ 4, 5, 5 },{ 5, 6, 1 },
	{ 6, 7, 3 },	{ 7, 8, 2 } };//边信息
	int d = 9, e = 16;
	Graphmtx g1;
	g1.CreatGraph(v1, d, rcw1, e);
	cout << "路由表生成成功！" << endl;
	meau();
	int ch; string s, n; int c;
	cin >> ch;
	while (1) {
		switch (ch) {
		case 1:
			g1.chushihua();
			g1.Path();
			cout << "请输入路由器名：" << endl;
			cin >> s;
			g1.PrintItem(s);
			break;
		case 2:
			cout << "请输入增加路由器名：" << endl;
			cin >> s;
			g1.insertVertex(s);
			break;
		case 3:
			cout << "请输入边的端点及权值：" << endl;
			cin >> s >> n >> c;
			g1.insertEdge(s, n, c); break;
		case 4:
			cout << "请输入需要删除路由器名" << endl;
			cin >> s;
			g1.removeVertex(s); break;
		case 5:
			cout << "请输入需要删除边的两个端点：" << endl;
			cin >> s >> n;
			g1.removeEdge(s, n); break;
		case 6:return 0;
		default:cout << "输入错误" << endl;
		}
		meau(); cin >> ch;
	}
	return 0;
}
