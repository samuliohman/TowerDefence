#ifndef TOWER_DEFENSE_BASIC_TOWER
#define TOWER_DEFENSE_BASIC_TOWER

#include "Tower.hpp"

class BasicTower : public Tower {
 public:
  BasicTower(Coordinate place, Game* game) : Tower(150, 3, 1, place, 2, game, 2){};

  void Defend() {
    Game* game = this->GetGame();
    std::vector<Enemy*> e = game->GetEnemies();
    std::vector<Enemy*> inRange;

    for (auto i : e) {
      auto a = i->GetCoord();
      auto b = this->GetPlace();
      auto dist = (a - b).getLength();
      // auto distance = ((i->GetCoord()) - place_).getLength();
      // std::cout << dist;
      if (dist < this->GetRange()) inRange.push_back(i);
    }
    std::sort(inRange.begin(), inRange.end());

    if (!inRange.empty()) {
      auto enemy = inRange.front();
      auto a = enemy->GetCoord();
      auto b = this->GetPlace();
      auto dist = (a - b).getLength();
      auto dir = (a - b) / dist;
      auto proj =
          Projectile(3, this->GetDamage(), this->GetPlace(), dir, normal, game);

      game->AddProjectile(proj);
    }
  };
};

#endif