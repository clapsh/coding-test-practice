#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#define max 1001
using namespace std;

bool visit[max]; //�湮����

vector <int> graph[max];// �׷��� dfs���� ��� 
queue <int> Q;

void dfs(int srt) {
	visit[srt] = true;//�湮 ǥ��
	cout << srt << " ";
	//cout <<"\nstart index : " <<srt<<endl;
	for (int i = 0; i < graph[srt].size(); i++) {// �ش� �ε����� ���� ��� ������ŭ Ž��
		int next = graph[srt][i];//�������� �ؾ��� ***[�迭�ε���][�����ε���]
		if (!visit[next]) {
			dfs(next);
		}
	}

}

void bfs(int srt) {
	memset(visit, false, sizeof(visit));
	visit[srt] = true;
	Q.push(srt);
	while (!Q.empty()) {//ť�� ���Ұ� ���� �� ����
		int x = Q.front();//ť�� ù��° ����(LIFO->pop�Ҷ� ���� ù��° ���Ҹ� pop��)
		Q.pop();//���� ù��° ���� ����
		cout << x << " ";
		for (int i = 0; i < graph[x].size(); i++) {//������ ����� ������ŭ
			int next = graph[x][i];
			if (!visit[next]) {
				visit[next] = true;
				Q.push(next);
			}
		}
	}
}


int main() {
	int vtx, edge, srt; int a, b;
	cin >> vtx >> edge >> srt;

	// Undirected graph �����
	for (int i = 1; i <= edge; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	//sort
	for (int i = 1; i <= edge; i++) {//graph->size() == edge���� �� �ȵ���?
		sort(graph[i].begin(), graph[i].end());
	}

	//visit�� ��� false�� �ʱ�ȭ
	//memset(visit, false, graph->size());

	//Using Dfs
	dfs(srt);
	cout << endl;
	//Using Bfs
	bfs(srt);
	cout << endl;

	return 0;
}