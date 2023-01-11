#pragma once
#include<SFML\Graphics.hpp>
#include<vector>

using namespace std;

class Sort
{
public:
	Sort(sf::RenderWindow& screen, int elements, bool seperators);
	~Sort() {};
	virtual void swap();
	void draw(sf::RenderWindow& screen);
	void check();
	double interp(double v, double a, double b, double c, double d);
	void initialize(sf::RenderWindow& screen, int elements, bool seperators);
	int width;
	vector<int> sort;
	vector<int> sorted;
	int current_index = 0;
	int second_index = 0;
	bool done = false;
	bool seperated;

private:
};