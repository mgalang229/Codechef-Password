#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		// create a boolean array
		bool checker[5] = {false};
		for (int i = 0; i < (int) s.size(); i++) {
			if (s[i] >= 97 && s[i] <= 122) {
				// check if at least one lowercase letter exists
				checker[0] = true;
			} else if ((i > 0 && i < (int) s.size() - 1) && (s[i] >= 65 && s[i] <= 90)) {
				// check if at least one uppercase exists ONLY inside the word
				// not the first or last character
				checker[1] = true;
			} else if ((i > 0 && i < (int) s.size() - 1) && (s[i] - '0' >= 0 && s[i] - '0' <= 9)) {
				// check if at least one number exists ONLY inside the word
				// not the first or last character
				checker[2] = true;
			} else if ((i > 0 && i < (int) s.size() - 1) && (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '&' || s[i] == '?')) {
				// check if these symbols exists ONLY inside the word
				// not the first or last character
				checker[3] = true;
			}
		}
		// check if the length of the password is >= 10
		if ((int) s.size() >= 10) {
			checker[4] = true;
		} 
		// check if the password provided passes all conditions
		bool final_check = true;
		for (int i = 0; i < 5; i++) {
			if (!checker[i]) {
				final_check = false;
				break;
			}
		}
		cout << (final_check ? "YES" : "NO") << '\n';
	}
	return 0; 
}
