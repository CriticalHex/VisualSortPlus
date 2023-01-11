#pragma once
#include<SFML/Graphics.hpp>
#include"Sort.h"
#include<vector>

using namespace std;

//constructor
Sort::Sort(sf::RenderWindow& screen, int elements, bool seperators)
{
	width = screen.getSize().x / elements;
	for (unsigned int i = width; i < screen.getSize().x + 1; i += width) {
		sort.push_back(i);
	}
	sorted.resize(sort.size());
	copy(sort.begin(), sort.end(), &sorted);
	shuffle(sort.begin(), sort.end(), rand());

	seperated = seperators;

}

void Sort::initialize(sf::RenderWindow& screen, int elements, bool seperators) {
	width = screen.getSize().x / elements;
	for (unsigned int i = width; i < screen.getSize().x + 1; i += width) {
		sort.push_back(i);
	}
	sorted.resize(sort.size());
	copy(sort.begin(), sort.end(), &sorted);
	shuffle(sort.begin(), sort.end(), rand());

	seperated = seperators;
}

void Sort::swap() {

	int temp = sort[current_index];
	sort[current_index] = sort[second_index];
	sort[second_index] = temp;

};

void Sort::draw(sf::RenderWindow& screen) {

	for (int i = 0; i < sort.size(); i++) {
		sf::RectangleShape rect;
		rect.setSize(sf::Vector2f(((i * width) + seperated), screen.getSize().y - interp(sort[i], 0, screen.getSize().x, 0, screen.getSize().y)));
		rect.setPosition(sf::Vector2f(width - (2 * seperated), interp(sort[i], 0, screen.getSize().x, 0, screen.getSize().y)));
		if (not done) {
			if (i == current_index or i == second_index) {
				rect.setFillColor(sf::Color::Red);
				screen.draw(rect);
			}
			else {
				rect.setFillColor(sf::Color::White);
				screen.draw(rect);
			}
		}
		else {
			rect.setFillColor(sf::Color::Green);
			screen.draw(rect);
		}
	}

};

void Sort::check() {
	if (sort == sorted) {
		done = true;
	}
};

double Sort::interp(double v, double a, double b, double c, double d) {
	double t = v / (b - a);
	return lerp(c, d, t);
}
/*
this was the big aha I suppose, numpy has the "interp" function, which is a linear interpolation function, as is "lerp",
but "interp" has more functionality, as you might excpect from numpy. My graphical sort program uses this to create rectangles
that fit the window size. The numpy interp lets you provide a value and two ranges. It finds the percentage along the first range that the value falls,
and then finds what number is that far along the second range. I.e. 5 is halfway between 0 and 10, and 10 is half way between 0 and 20, interp with those inputs
would return 10. The code below does just that. v would be 5, a=0, b=10, c=0, d=20. 5/10 is .5 (50%), 50% between 0 and 20 is 10. the reason lerp is used here
and not just .5*20, is because were the second range 10-20, then the function should return 15, as 15 is halfway between those 10 and 20. 
*/