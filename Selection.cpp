#pragma once
#include "Selection.h"
#include<SFML/Graphics.hpp>

void Selection::step() {
	if (sort[current_index] < smallest) {
		smallest_index = current_index;
		smallest = sort[smallest_index];
	}
	increment();
}

void Selection::swap() {

	int temp = sort[smallest_index];
	sort[smallest_index] = sort[second_index];
	sort[second_index] = temp;

};

void Selection::increment() {
	current_index++;
	if (current_index % sort.size() == 0) {
		check();
		swap();
		second_index++;
		second_index %= sort.size();
		current_index = second_index;
		smallest = INFINITY;
	}
}

void Selection::run(sf::RenderWindow& screen, int speed) {
	if (not done) {
		for (int i = 0; i < speed; i++) {
			step();
		}
	}
	draw(screen);
}