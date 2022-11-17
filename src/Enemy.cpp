#include "Enemy.hpp"

Enemy::Enemy(float speed, int health, Coordinate place, int worth)
    : speed_(speed),
      health_(health),
      place_(place),
      worth_(worth),
      currentNode_(0),
      game_(Game()) {}

Enemy::Enemy(float speed, int health, Coordinate place, int worth, Game game)
    : speed_(speed),
      health_(health),
      place_(place),
      worth_(worth),
      currentNode_(0),
      game_(game) {
  auto direction_raw = game_.getMap().GetNode(currentNode_) - place_;
  direction_ = direction_raw / direction_raw.getLength();
}

void Enemy::getHit(int amount) {
  if (health_ < amount)
    health_ = 0;
  else
    health_ -= amount;
}

bool Enemy::Move() {
  auto nextNode = game_.getMap().GetNode(currentNode_);
  double distance = (nextNode - this->place_).getLength();
  // if enemy is near the node, switch to next node unless next node is the
  // last node.
  if (distance < speed_ * 1.5) {
    if (currentNode_ >= game_.getMap().GetNofNodes() - 1) {
      std::cout << "Reached final destination, remove health and destroy enemy."
                << std::endl;
      return false;
    } else {
      currentNode_++;
      auto direction_raw = game_.getMap().GetNode(currentNode_) - this->place_;
      direction_ = direction_raw / direction_raw.getLength();
    }
  }

  // Move towards the next node with the speed
  place_ = place_ + (direction_ * speed_);
  return true;
}

void Enemy::Slow(double s) {
  auto t = s;
  if (speed_ - t > 0) speed_ -= s;
}

const float& Enemy::GetSpeed() const { return speed_; }

// Get the enemy's health
const int& Enemy::GetHealth() const { return health_; }

// Get the enemy's coordinates
const Coordinate& Enemy::GetCoord() const { return place_; }

// Get the enemy's worth
const int& Enemy::GetWorth() const { return worth_; }