/*
 * Player.cpp
 *
 *  Created on: 27 окт. 2022 г.
 *      Author: ∆идковƒя
 */

#include <cmath>
#include "Player.h"

static constexpr double Pi = acos(-1.0);

void Player::spawn(std::shared_ptr<Map> &m) {
    _map  = m;
    _x    = m -> start_x();
    _y    = m -> start_y();
    _dir  = m -> start_dir();
    _tilt = Pi / 2.0;
}

void Player::walk_fwd(double dist) {
    double nx = _x + dist * cos(_dir);
    double ny = _y + dist * sin(_dir);
    if (not _map -> is_wall(nx, ny)) {
        _x = nx;
        _y = ny;
    }
}

void Player::walk_back(double dist) {
    walk_fwd(-dist);
}

void Player::shift_left(double dist) {
    shift_right(-dist);
}

void Player::shift_right(double dist) {
    double nx = _x + dist * cos(_dir + Pi/2.0);
    double ny = _y + dist * sin(_dir + Pi/2.0);
    if (not _map -> is_wall(nx, ny)) {
        _x = nx;
        _y = ny;
    }
}

void Player::turn_left(double angle) {
    _dir -= angle;
    if (_dir < 0.0)
        _dir += 2.0 * Pi;
}

void Player::turn_right(double angle) {
    _dir += angle;
    if (_dir >= 2.0 * Pi)
        _dir -= 2.0 * Pi;
}

void Player::tilt_down(double angle)
{
	_tilt += angle;
	if (_tilt >= Pi * 0.95)
		_tilt = Pi * 0.95;
}

void Player::tilt_up(double angle)
{
	_tilt -= angle;
	if (_tilt < Pi * 0.05)
		_tilt = Pi * 0.05;
}

