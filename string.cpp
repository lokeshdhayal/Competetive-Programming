
-----KMP----

#define MAX_N 100010
string T,P;
int b[MAX_N], n, m;
void kmpPreprocess() {
	int i = 0, j = -1; b[0] = -1;
	while (i < m) {
		while (j >= 0 && P[i] != P[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}
void kmpSearch() {
	kmpPreprocess();
	int i = 0, j = 0;
	while (i < n) {
		while (j >= 0 && T[i] != P[j]) j = b[j];
		i++; j++;
		if (j == m) {
			printf("P is found at index %d in T\n", i - j);
			j = b[j];
		}
	}
}




-----------Z function ---------------

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}



