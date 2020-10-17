/* Copyright 2020 Herman Lundkvist
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
         l00, l01, l02, l03, l04, \
         l10, l11, l12, l13, l14, \
    l20, l21, l22, l23, l24, l25, \
         l30, l31, l32, l33, l34, \
              l40, l41, l42, l43, l44, l45, \
    l50, \
\
              r00, r01, r02, r03, r04, \
              r10, r11, r12, r13, r14, \
              r20, r21, r22, r23, r24, r25, \
              r30, r31, r32, r33, r34, \
    r40, r41, r42, r43, r44, r45, \
                                       r50 \
) { \
    { l20,   l00,   l01, l02, l03,   l04  }, \
    { l50,   l10,   l11, l12, l13,   l14  }, \
    { KC_NO, l21,   l22, l23, l24,   l25  }, \
    { l45,   l30,   l31, l32, l33,   l34  }, \
    { l44,   KC_NO, l40, l41, l42,   l43  }, \
    { r25  , r04,   r03, r02, r01,   r00  }, \
    { r50  , r14,   r13, r12, r11,   r10  }, \
    { KC_NO, r24,   r23, r22, r21,   r20  }, \
    { r40  , r34,   r33, r32, r31,   r30  }, \
    { r41  , KC_NO, r45, r44, r43,   r42  }, \
}
