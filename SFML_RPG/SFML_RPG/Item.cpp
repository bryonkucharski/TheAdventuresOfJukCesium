#include "Item.h"
Item::Item() {

}
Item::Item(std::string filename, Vector2f imageSize, int id, std::string name, int value) {
	texture.loadFromFile(filename);
	this->sprite.setTexture(this->texture);
	this->rect.setSize(imageSize);
	this->setID(id);
	this->setName(name);
	this->setValue(value);
}
Item::~Item() {

}
int Item::getID() {
	return ID;
}
std::string Item::getName() {
	return name;
}
int Item::getValue() {
	return value;
}

void Item::setID(int i) {
	this->ID = i;
}
void Item::setName(std::string s) {
	this->name = s;
}
void Item::setValue(int v) {
	this->value = v;
}