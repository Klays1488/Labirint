/*
 * Player.h
 *
 *  Created on: 27 окт. 2022 г.
 *      Author: ∆идковƒя
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include "Map.h"

class Player final {

private:
    double _x {}, _y {}, _dir {}, _tilt {};
    std::shared_ptr<Map> _map {};

public:
    Player() = default;

    void spawn(std::shared_ptr<Map> & m);

    double dir()  const { return _dir; }
    double x()    const { return _x; }
    double y()    const { return _y; }
    double tilt() const { return _tilt; }

    void walk_fwd(double dist);
    void walk_back(double dist);
    void shift_left(double dist);
    void shift_right(double dist);
    void turn_left(double angle);
    void turn_right(double angle);
    void tilt_down(double angle);
    void tilt_up(double angle);

};

#endif //PLAYER_H
