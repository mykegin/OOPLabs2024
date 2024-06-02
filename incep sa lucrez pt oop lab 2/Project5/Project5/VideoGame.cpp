#include "VideoGame.h"

VideoGame::VideoGame(int price, int quantity, string producer, string game)
{
	this->pret = price;
	this->cantitate = quantity;
	this->producator = producer;
	this->numejoc = game;
}

string VideoGame::GetType()
{
	return "Videogame";
}

int VideoGame::GetQuantity()
{
	return this->cantitate;
}

int VideoGame::GetPrice()
{
	return this->pret;
}

void VideoGame::Print()
{
	cout << "VideoGame (Platform=" << this->producator << ", Name=" << this->numejoc << ") Price=" << this->pret << " Quantity=" << this->cantitate<<"\n";
	return;
}
