#include <iostream>
#include <cstring>
using namespace std;
const int N = 110;
typedef long long ll;
ll f[N][N], count[N][N];
char a[N], b[N];
int len1, len2;
void solve() {
	for (int i = 0; i <= max(len1, len2); i++) {
		f[i][0] = f[0][i] = i;
		count[i][0] = count[0][i] = 1;
	}
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (a[i] == b[j]) {
				f[i][j] = f[i - 1][j - 1] + 1;
				count[i][j] = count[i - 1][j - 1];
			} else {
				f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
				if (f[i - 1][j] < f[i][j - 1])
					count[i][j] = count[i - 1][j];
				else if (f[i - 1][j] > f[i][j - 1])
					count[i][j] = count[i][j - 1];
				else
					count[i][j] = count[i - 1][j] + count[i][j - 1];
			}
		}
	}
}
int main() {
	cin >> a + 1 >> b + 1;
	len1 = strlen(a + 1);
	len2 = strlen(b + 1);
	solve();
	cout << f[len1][len2] << " " << count[len1][len1];
	return 0;
}
