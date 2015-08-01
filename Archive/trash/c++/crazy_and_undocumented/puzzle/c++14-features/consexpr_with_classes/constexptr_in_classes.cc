struct Point {
	int x;
	int y;
	Point() {}
	constexpr Point(int x, int y) : x{x}, y{y} {}
};
int main() {
	constexpr int x = 10;
	constexpr int y = 43;
	Point p_point{x, y};
	return 0;
}
