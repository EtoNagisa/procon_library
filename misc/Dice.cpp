#include "bits/stdc++.h"

template <typename T> struct Dice {
public:
  Dice(std::vector<T> v) : faces(v) {}
  void roll(char c) {
    T tmp;
    switch (c) {
    case 'N':
      tmp = faces[TOP];
      faces[TOP] = faces[FRONT];
      faces[FRONT] = faces[BOTTOM];
      faces[BOTTOM] = faces[BACK];
      faces[BACK] = tmp;
      break;
    case 'S':
      tmp = faces[TOP];
      faces[TOP] = faces[BACK];
      faces[BACK] = faces[BOTTOM];
      faces[BOTTOM] = faces[FRONT];
      faces[FRONT] = tmp;
      break;
    case 'E':
      tmp = faces[TOP];
      faces[TOP] = faces[LEFT];
      faces[LEFT] = faces[BOTTOM];
      faces[BOTTOM] = faces[RIGHT];
      faces[RIGHT] = tmp;
      break;
    case 'W':
      tmp = faces[TOP];
      faces[TOP] = faces[RIGHT];
      faces[RIGHT] = faces[BOTTOM];
      faces[BOTTOM] = faces[LEFT];
      faces[LEFT] = tmp;
      break;
    case 'R':
      tmp = faces[FRONT];
      faces[FRONT] = faces[RIGHT];
      faces[RIGHT] = faces[BACK];
      faces[BACK] = faces[LEFT];
      faces[LEFT] = tmp;
      break;
    case 'L':
      tmp = faces[FRONT];
      faces[FRONT] = faces[LEFT];
      faces[LEFT] = faces[BACK];
      faces[BACK] = faces[RIGHT];
      faces[RIGHT] = tmp;
      break;
    default:
      std::cerr << "invalid char" << std::endl;
      abort();
    }
  }
  T top() {
    return faces[TOP];
  }
  T front() {
    return faces[FRONT];
  }
  T left() {
    return faces[LEFT];
  }
  T back() {
    return faces[BACK];
  }
  T right() {
    return faces[RIGHT];
  }
  T bottom() {
    return faces[BOTTOM];
  }

private:
  std::vector<T> faces;
  static constexpr int TOP = 0, FRONT = 1, RIGHT = 2, LEFT = 3, BACK = 4,
                       BOTTOM = 5;
};