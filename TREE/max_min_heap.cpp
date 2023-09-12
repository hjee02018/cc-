#include <queue>
#include <iostream>
using namespace std;

int main() {
	priority_queue<int, vector<int>, less<int>> mx_pq;
	mx_pq.push(5);
	mx_pq.push(2);
	mx_pq.push(8);
	mx_pq.push(9);
	mx_pq.push(1);
	mx_pq.push(14);

	mx_pq.pop();
	mx_pq.pop();
	while (!mx_pq.empty()) {
		cout << mx_pq.top() << " ";
		mx_pq.pop();
	}
	priority_queue<int, vector<int>, greater<int>> mn_pq;
	mn_pq.push(5);
	mn_pq.push(2);
	mn_pq.push(8);
	mn_pq.push(9);
	mn_pq.push(1);
	mn_pq.push(14);

	mn_pq.pop();
	mn_pq.pop();

	while (!mn_pq.empty()) {
		cout << mn_pq.top() << " ";
		mn_pq.pop();
	}

}