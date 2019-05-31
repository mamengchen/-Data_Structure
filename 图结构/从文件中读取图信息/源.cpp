#include "Graph.h"
#include "ReadGraph.h"
using namespace std;
int main()
{
	string filename = "text.txt";
	DenseGraph DG(13, false);
	ReadGraph<DenseGraph> iterator(DG, filename);
	DG.show();

	SparseGraph SG(13, false);
	ReadGraph<SparseGraph> iterator1(SG, filename);
	SG.show();
	return 0;
}