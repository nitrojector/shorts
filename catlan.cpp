#include <iostream>
#include <map>

using namespace std;

/**
 * # Catlan Numbers
 *
 * I did not know this is actually called something.
 * I ran into this problem while doing a problem on
 * the number of ways a binary search tree can be formed
 * with n nodes. At first I was being a dumbass as
 * I have always been, and even when trying to bruteforce
 * the number, failed horribly. Then I realized, like
 * any dumbass, that it is basically a recursive problem:
 *
 * After you choose the node that you want to be the parent,
 * there are a set of nodes (less than the node) that has to
 * be placed left of the node, and a number of nodes that have
 * to be placed in the right subtree. This is assuming unique
 * nodes, so I wrote out a recursive function(n is the number
 * of nodes to be arranged):
 *
 * ```tex
 * f(n) = \sum_{i=1}^n f(i - 1) \cdot f(n - i)
 * ```
 *
 * that defines number of ways through a summation.
 */
int catlan(int n, map<int, int>& memo) {
	if (memo.find(n) != memo.end())
		return memo[n];
	if (n == 0)
		return 1;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += catlan(i, memo) * catlan(n - i - 1, memo);
	}

	memo[n] = sum;
	return sum;
}

int main() {
	map<int, int> memo;
	int lim = 20;
	for (int i = 0; i < lim; i++) {
		cout << i << "=" << catlan(i, memo) << endl;
	}
}
