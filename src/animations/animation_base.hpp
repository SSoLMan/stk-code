//
//  SuperTuxKart - a fun racing game with go-kart
//  Copyright (C) 2009  Joerg Henrichs
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 3
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef HEADER_ANIMATION_BASE_HPP
#define HEADER_ANIMATION_BASE_HPP

/**
 * \defgroup animations
 * This module manages interpolation-based animation (of position, rotation
 * and/or scale)
 */

#include <vector>

#include "tracks/track_object.hpp"
#include "utils/ptr_vector.hpp"

class XMLNode;
class Ipo;

/**
  * \brief A base class for all animations.
  * \ingroup animations
  */
class AnimationBase : public TrackObject
{
private:
    /** Two types of animations: cyclic ones that play all the time, and
    *  one time only (which might get triggered more than once). */
    enum AnimTimeType { ATT_CYCLIC, ATT_CYCLIC_ONCE } m_anim_type;

    /** True if the animation is currently playing. */
    bool  m_playing;

    /** The current time used in the IPOs. */
    float m_current_time;

    /** For cyclic animations: duration of the cycle. */
    float m_cycle_length;

    /** The inital position of this object. */
    Vec3 m_initial_xyz;

    /** The initial rotation of this object. */
    Vec3 m_initial_hpr;

    void computeLengths();

protected:
    /** All IPOs for this animation. */
    PtrVector<Ipo>  m_all_ipos;

public:
                 AnimationBase(const XMLNode &node);
    virtual     ~AnimationBase();
    virtual void update(float dt, Vec3 *xyz, Vec3 *hpr, Vec3 *scale);
    /** This needs to be implemented by the inheriting classes. It is called
    *  once per frame from the track. */
    virtual void update(float dt) = 0;
    void         setInitialTransform(const Vec3 &xyz, 
                                     const Vec3 &hpr);
    void         reset();

};   // AnimationBase

#endif

