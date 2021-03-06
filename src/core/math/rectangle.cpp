//
// Created by Ion Agorria on 25/03/18
//
#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->w = width;
    this->h = height;
}

Rectangle::Rectangle(const Vector2& position, const Vector2& size) {
    this->x = position.x;
    this->y = position.y;
    this->w = size.x;
    this->h = size.y;
}

Rectangle::Rectangle(const Rectangle& rectangle) {
    this->x = rectangle.x;
    this->y = rectangle.y;
    this->w = rectangle.w;
    this->h = rectangle.h;
}

Rectangle::Rectangle() {
    this->x = 0;
    this->y = 0;
    this->w = 0;
    this->h = 0;
}

bool Rectangle::operator==(const Rectangle& rectangle) {
    return x == rectangle.x
        && y == rectangle.y
        && w == rectangle.w
        && h == rectangle.h;
}

bool Rectangle::operator!=(const Rectangle& rectangle) {
    return x != rectangle.x
        || y != rectangle.y
        || w != rectangle.w
        || h != rectangle.h;
}

Rectangle::operator bool() {
    return 0 < w && 0 < h;
}

bool Rectangle::empty() {
    return 0 >= w || 0 >= h;
}

bool Rectangle::zero() {
    return 0 == x && 0 == y;
}

void Rectangle::set(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->w = width;
    this->h = height;
}

void Rectangle::set(const Vector2& position, const Vector2& size) {
    this->x = position.x;
    this->y = position.y;
    this->w = size.x;
    this->h = size.y;
}

void Rectangle::set(const Rectangle& rectangle)
    {
    this->x = rectangle.x;
    this->y = rectangle.y;
    this->w = rectangle.w;
    this->h = rectangle.h;
}

bool Rectangle::isInside(int px, int py) {
    return x <= px && px <= x + w
        && y <= py && py <= y + h;
}

bool Rectangle::isInside(const Vector2& v) {
    return x <= v.x && v.x <= x + w
        && y <= v.y && v.y <= y + h;
}

bool Rectangle::isInside(const Rectangle& rectangle) {
    float xmin = rectangle.x;
    float xmax = xmin + rectangle.w;

    float ymin = rectangle.y;
    float ymax = ymin + rectangle.h;

    return xmin > x && xmin < x + w && xmax > x && xmax < x + w
        && ymin > y && ymin < y + h && ymax > y && ymax < y + h;
}

bool Rectangle::isOverlap(const Rectangle& rectangle) {
    return x < rectangle.x + rectangle.w && rectangle.x < x + w
        && y < rectangle.y + rectangle.h && rectangle.y < y + h;

}

bool Rectangle::getIntersectRectangle(const Rectangle& rectangle, Rectangle& result) {
    return SDL_IntersectRect(this, &rectangle, &result) == SDL_TRUE;
}

bool Rectangle::getIntersectLine(Vector2& start, Vector2& end) {
    return SDL_IntersectRectAndLine(this, &start.x, &start.y, &end.x, &end.y);
}

std::string Rectangle::toString() {
    return "R(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(w) + ", " + std::to_string(h) + ")";
}
