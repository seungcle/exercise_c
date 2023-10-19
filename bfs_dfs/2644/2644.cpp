#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int n, A, B, m;
vector<int> family[101];
int dist[101] = { 0, };

void BFS() {
	queue<int> q;
	q.push(A);
	dist[A] = 0;

	while (!q.empty()) {
		int next = q.front();

		if (next == B) {
			cout << dist[B] << "\n";
			return;
		}

		for (int i = 0; i < family[next].size(); i++) {
			if (!dist[family[next][i]]) {
				q.push(family[next][i]);
				dist[family[next][i]] = dist[next] + 1;
			}
		}

		q.pop();
	}

	cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n;
	cin >> A >> B;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		family[x].push_back(y);
		family[y].push_back(x);

	}

	BFS();


	return 0;
}