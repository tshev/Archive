struct Point {
	int x;
	int y;
	Point() {}
	constexpr Point(int x, int y) : x{x}, y{y} {}
};
int main() {
	int x = 10;
	int y = 10;
	Point p_point{x, y};
	return 0;
}
