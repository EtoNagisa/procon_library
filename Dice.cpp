#include "bits/stdc++.h"

template<typename T>
struct Dice {
public:

	Dice(std::vector<T> v) : faces(v) {}
	void roll(char c) {
		switch (c) {
		case 'N':
			T tmp = faces[0];
			faces[0] = faces[1];
			faces[1] = faces[5];
			faces[5] = faces[3];
			faces[3] = tmp;
			break;
		case 'E':
			T tmp = faces[0];
			faces[0] = faces[4];
			faces[4] = faces[5];
			faces[5] = faces[2];
			faces[2] = tmp;
			break;
		case 'S':
			T tmp = faces[0];
			faces[0] = faces[3];
			faces[3] = faces[5];
			faces[5] = faces[1];
			faces[1] = tmp;
			break;
		case 'W':
			T tmp = faces[0];
			faces[0] = faces[2];
			faces[2] = faces[5];
			faces[5] = faces[4];
			faces[4] = tmp;
			break;
		case 'R':
			T tmp = faces[1];
			faces[1] = faces[2];
			faces[2] = faces[3];
			faces[3] = faces[4];
			faces[4] = tmp;
			break;
		case 'L':
			T tmp = faces[1];
			faces[1] = faces[4];
			faces[4] = faces[3];
			faces[3] = faces[2];
			faces[2] = tmp;
			break;
		default:
			std::cerr << "invalid char" << endl;
			abort();
		}
	}
	T top() {
		return faces[0];
	}
	T front() {
		return faces[1];
	}
	T left() {
		return faces[2];
	}
	T back() {
		return faces[3];
	}
	T right() {
		return faces[4];
	}
	T bottom() {
		return faces[5];
	}
private:
	std::vector<T> faces(6);
};


