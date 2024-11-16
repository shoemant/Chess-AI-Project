
#pragma once
#include <SFML/Graphics.hpp>
#include "../Types.h"
#include <memory>
class Board;

class Piece
{
public:
    Piece(int x, int y, const sf::Sprite &sprite, PieceColor color)
        : x_(x), y_(y), sprite_(sprite), color_(color), hasMoved_(false) {}

    virtual ~Piece() = default;

    int getX() const { return x_; }
    int getY() const { return y_; }
    PieceColor getColor() const { return color_; }
    PieceType getType() const { return type_; }
    sf::Sprite getSprite() const { return sprite_; }

    void setPosition(int x, int y)
    {
        x_ = x;
        y_ = y;
        sprite_.setPosition(x_ * 100.f, y_ * 100.f);
    }
    void move(int x, int y)
    {
        setPosition(x, y);
        hasMoved_ = true;
    }

    bool isSlidingPiece() const { return isSliding_; }

    bool hasMoved() const { return hasMoved_; }

    void setHasMoved(bool moved) { hasMoved_ = moved; }

    virtual std::vector<std::pair<int, int>> getPotentialMoves(const Board &board) const = 0;

    virtual std::unique_ptr<Piece> clone() const = 0;

protected:
    int x_;
    int y_;
    sf::Sprite sprite_;
    PieceColor color_;
    PieceType type_;
    bool isSliding_;
    bool hasMoved_;
};