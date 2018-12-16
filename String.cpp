int strcmp(string s, string t) {
	if (s[0] < t[0]) {
		return 1;
	}
	else if (s[0] == t[0]) {
		if (s.length() == 1 && t.length() == 1) {
			return 0;
		}
		else if (s.length() == 1) {
			return 1;
		}
		else if (t.length() == 1) {
			return -1;
		}
		else {
			return strcmp(s.substr(1), t.substr(1));
		}
	}
	else {
		return -1;
	}
}