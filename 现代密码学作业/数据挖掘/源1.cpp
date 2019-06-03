#include<iostream> 
#include<string>
#include<algorithm>
#include<vector>
#include<map> 
#include<fstream>
#include<sstream>
#define suport 0.001//最小支持度
using namespace std;
struct FPtreeNode {//孩子兄弟链表法存储FP-tree
	int  data;
	int count;
	FPtreeNode *father;
	FPtreeNode *children;
	FPtreeNode *brother;
	FPtreeNode *next;
	FPtreeNode() {
		data = 0;
		count = 0;
		father = NULL;
		children = NULL;
		brother = NULL;
		next = NULL;
	}
};
struct resultNode {//结果
	string data;
	int count;
	resultNode() {
		count = 0;
	}
};
struct listNode {//头表
	int data;
	int count;
	FPtreeNode *next;
};
struct fptreeNode {//递归过程中的子FP-tree 
	int data;
	int count;
	fptreeNode() {
		data = 0;
		count = 0;
	}
};
int line = 0;
vector<string> Getfile() {
	vector<string> file;
	ifstream ifile("jiayou.txt");
	if (!ifile) {
		cout << "open file error" << endl;
	}
	else {
		string temp;
		while (getline(ifile, temp)) {
			line++;
			file.insert(file.end(), temp);
		}
	}
	ifile.close();
	return file;
}
bool cmp(listNode &a, listNode &b) {
	return a.count > b.count;
}

vector<listNode> Getheadlist(vector<string> &file) {
	vector<listNode>L1;
	map<string, int>r1;
	string temp;
	string lk;
	for (int f = 0; f < file.size(); f++) {//第一次扫描数据库 
		temp = file[f];
		int i;
		for (i = 0; i < temp.size(); i++) {
			while (temp[i] != ' '&&temp[i] != '\n'&&i != temp.size()) {
				lk += temp[i];
				i++;
			}
			if (r1.find(lk) != r1.end())
				r1[lk]++;
			else
				r1[lk] = 1;
			lk.clear();//
		}
	}
	temp.clear();
	map<string, int>::iterator it;
	for (it = r1.begin(); it != r1.end(); it++) {//待删除 

		if (it->second >= ceil(suport*line)) {
			string s = it->first;
			int x = atoi(s.c_str());//转换成整数
			listNode xx;
			xx.data = x;
			xx.count = it->second;
			xx.next = NULL;
			L1.insert(L1.end(), xx);
		}
	}
	sort(L1.begin(), L1.end(), cmp);
	return L1;
}
bool Isin(string temp, string str) {
	int j;
	string s;
	for (j = 0; j < temp.size(); j++) {//遍历temp
		while (temp[j] != ' '&&j < temp.size() && temp[j] != '\n') {
			s.insert(s.end(), temp[j]);
			j++;
		}
		if (s == str)
			break;
		s.clear();
	}
	if (j >= temp.size())
		return 0;
	else
		return 1;

}
vector<vector<int> > Get_FPfile(vector<string> &file, vector<listNode> &L1) {//第二次扫描数据库 删除非频繁一项 
	string temp;
	vector<vector<int> > rfile;
	vector<int >ri;
	for (int f = 0; f < file.size(); f++) {
		temp = file[f];
		for (int k = 0; k < L1.size(); k++) {
			string s;
			int n = L1[k].data;

			stringstream ss;
			ss << n;
			ss >> s;
			if (Isin(temp, s)) {
				ri.push_back(n);
			}
		}
		if (ri.size() > 0) {
			rfile.push_back(ri);
			ri.clear();
		}
		temp.clear();
	}
	file.clear();
	return rfile;
}
int c = 0;
void Linknext(FPtreeNode *newNode, vector<listNode> &L1) {
	for (int m = 0; m < L1.size(); m++) {
		if (L1[m].data == newNode->data) {
			if (L1[m].next == NULL) {
				L1[m].next = newNode;
			}
			else {
				FPtreeNode *t1 = L1[m].next;
				FPtreeNode *t2 = L1[m].next;
				while (t1) {
					t2 = t1;
					t1 = t1->next;
				}
				t2->next = newNode;
			}
			break;
		}
	}

}
FPtreeNode*  Buildtree(vector<vector<int> > &rfile, vector<listNode> &L1) {
	FPtreeNode *head = new FPtreeNode;
	FPtreeNode *p = head;
	FPtreeNode *q = head;
	int flag = 0;
	for (int i = 0; i < rfile.size(); i++) {
		p = head;
		int j = 0;
		while (j < rfile[i].size()) {
			flag = 0;
			if (i == 0) {//第一条 
				FPtreeNode *newNode = new FPtreeNode;
				c++;
				newNode->count = 1;
				newNode->data = rfile[i][j];
				newNode->father = p;
				p->children = newNode;
				p = p->children;
				j++;
				for (int m = 0; m < L1.size(); m++) {
					if (L1[m].data == newNode->data) {
						L1[m].next = newNode;
						break;
					}
				}
			}
			else {
				p = p->children;
				while (p&&j < rfile[i].size()) {
					if (p->data == rfile[i][j]) {
						p->count++;
						q = p;//q->chilren=p;
						p = p->children;
						j++;
						flag = 1;
					}
					else {//
						q = p;//q->brother=p;
						p = p->brother;
						flag = 2;
					}

				}
				if (flag == 1) {
					while (j < rfile[i].size()) {
						FPtreeNode *newNode = new FPtreeNode;
						c++;
						newNode->count = 1;
						newNode->father = q;
						q->children = newNode;
						newNode->data = rfile[i][j];
						q = q->children;
						j++;
						//Linknext();
						Linknext(newNode, L1);
					}


				}
				else  if (flag == 2) {
					FPtreeNode *newNode = new FPtreeNode; c++;
					newNode->count = 1;
					newNode->data = rfile[i][j];
					q->brother = newNode;
					newNode->father = q->father;
					q = q->brother;
					j++;
					Linknext(newNode, L1);
					while (j < rfile[i].size()) {
						FPtreeNode *newNode = new FPtreeNode;
						c++;
						newNode->count = 1;
						newNode->father = q;
						q->children = newNode;
						newNode->data = rfile[i][j];
						q = q->children;
						j++;
						//Linknext();
						Linknext(newNode, L1);
					}


				}
			}
		}
	}
	return head;
}
vector<string> GetFrequentItems(listNode &lk, FPtreeNode* &head) {//生成条件模式基 rfile
	FPtreeNode *p = lk.next;
	vector<string> rfile;
	while (p) {
		FPtreeNode* q = p;
		vector<string> temp;
		while (q->father != head) {
			q = q->father;
			stringstream ss;
			string x;
			int n;
			n = q->data;

			ss << n;
			ss >> x;

			temp.push_back(x + " ");
		}
		reverse(temp.begin(), temp.end());
		string s;

		for (int j = 0; j < temp.size(); j++) {
			s += temp[j];
		}
		for (int i = 0; i < p->count; i++) {
			if (s.size() > 0)
				rfile.push_back(s);
		}
		s.clear();
		p = p->next;
	}
	return rfile;
}
vector<resultNode> result;
void Getresult(vector<listNode> &headlist, FPtreeNode* &head, string &base, vector<resultNode> &result) {
	if (headlist.empty()) {
		return;
	}
	for (auto p = headlist.rbegin(); p != headlist.rend(); p++) {
		resultNode temp;
		int n;
		n = p->data;//int to string
		stringstream ss;
		string x;
		ss << n;
		ss >> x;
		string xx = base + " " + x;
		temp.data = xx;
		temp.count = p->count;
		result.push_back(temp);
		/*****递归******/
		//产生条件模式基
		vector<string> file1 = GetFrequentItems(*p, head);


		vector<listNode>headlist1 = Getheadlist(file1);//getL1

		vector<vector<int> > rfile1 = Get_FPfile(file1, headlist1);

		//建树
		FPtreeNode* Tree = Buildtree(rfile1, headlist1);

		string s = base + " " + x;
		//产生结果
		Getresult(headlist1, Tree, s, result);
	}

}
void Print() {
	for (auto p = result.cbegin(); p != result.cend(); p++)
	{
		cout << p->data << " " << "(" << p->count << ")" << endl;
	}
}
int main1() {
	vector<string> file = Getfile();
	vector<listNode> headlist = Getheadlist(file);

	vector<vector<int> >rfile = Get_FPfile(file, headlist);

	FPtreeNode* head = Buildtree(rfile, headlist);
	string base = " ";

	Getresult(headlist, head, base, result);
	Print();
	cout << result.size();
	return 0;
}