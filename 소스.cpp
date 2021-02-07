#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#define max 1001
using namespace std;

bool visit[max]; //방문여부

vector <int> graph[max];// 그래프 dfs에서 사용 
queue <int> Q;

void dfs(int srt) {
	visit[srt] = true;//방문 표시
	cout << srt << " ";
	//cout <<"\nstart index : " <<srt<<endl;
	for (int i = 0; i < graph[srt].size(); i++) {// 해당 인덱스의 연결 노드 개수만큼 탐색
		int next = graph[srt][i];//이중으로 해야함 ***[배열인덱스][벡터인덱스]
		if (!visit[next]) {
			dfs(next);
		}
	}

}

void bfs(int srt) {
	memset(visit, false, sizeof(visit));
	visit[srt] = true;
	Q.push(srt);
	while (!Q.empty()) {//큐에 원소가 있을 때 까지
		int x = Q.front();//큐의 첫번째 원소(IFO->pop할때 가장 첫번째 원소를 pop함)
		Q.pop();//가장 첫번째 원소 삭제
		cout << x << " ";
		for (int i = 0; i < graph[x].size(); i++) {//인접한 노드의 개수만큼
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

	// Undirected graph 만들기
	for (int i = 1; i <= edge; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	//sort
	for (int i = 1; i <= edge; i++) {//graph->size() == edge인줄 왜 안되지?
		sort(graph[i].begin(), graph[i].end());
	}

	//visit을 모두 false로 초기화
	//memset(visit, false, graph->size());

	//Using Dfs
	dfs(srt);
	cout << endl;
	//Using Bfs
	bfs(srt);
	cout << endl;

	return 0;
}
