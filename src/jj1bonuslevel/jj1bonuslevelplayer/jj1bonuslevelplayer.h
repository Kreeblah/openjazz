
/**
 *
 * @file jj1bonuslevelplayer.h
 *
 * Part of the OpenJazz project
 *
 * @section History
 * 24th June 2010: Created bonusplayer.h from parts of player.h
 * 1st August 2012: Renamed bonusplayer.h to jj1bonuslevelplayer.h
 *
 * @section Licence
 * Copyright (c) 2005-2012 Alister Thomson
 *
 * OpenJazz is distributed under the terms of
 * the GNU General Public License, version 2.0
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef _BONUSPLAYER_H
#define _BONUSPLAYER_H


#include "player/player.h"

#include "OpenJazz.h"

#include <SDL/SDL.h>


// Constants

// Bonus level animations
#define PA_WALK  0
#define PA_LEFT  1
#define PA_RIGHT 2
#define PA_USER  3
#define PA_JUMP  4
#define PA_CRASH 5
#define PA_OTHER 6

#define BPANIMS  7

// Player speeds
#define PRS_CRASH   ITOF(-60)
#define PRS_REVERSE ITOF(-30)
#define PRS_JUMP    ITOF(40)
#define PRS_WALK    ITOF(40)
#define PRS_RUN     ITOF(80)
#define PAS_TURN    384
#define PZS_FALL    ITOF(-2)
#define PZS_JUMP    ITOF(3)

// Player accelerations
#define PRA_REBOUND 150
#define PRA_REVERSE 450
#define PRA_STOP    200
#define PRA_WALK    100
#define PAA_STOP    6
#define PAA_TURN    1
#define PZA_GRAVITY -6


// Classes

class Anim;
class JJ1BonusLevel;

/// JJ1 bonus level player
class JJ1BonusLevelPlayer {

	private:
		SDL_Color     palette[256]; ///< Palette (for custom colours)
		Anim*         anims[BPANIMS]; ///< Animations
		fixed         x; ///< X-coordinate
		fixed         y; ///< Y-coordinate
		fixed         z; ///< Z-coordinate (altitude)
		fixed         direction; ///< Direction
		fixed         dr; ///< Forward speed
		fixed         da; ///< Angular speed
		fixed         dz; ///< Vertical speed
		bool          running; ///< Rolling/running
		unsigned char animType; ///< Current animation
		int           gems; ///< Number of gems collected

	public:
		Player* player; ///< Corresponding game player

		JJ1BonusLevelPlayer  (Player* parent, Anim** newAnims, unsigned char startX, unsigned char startY);
		~JJ1BonusLevelPlayer ();

		void          addGem       ();
		fixed         getDirection ();
		int           getGems      ();
		fixed         getX         ();
		fixed         getY         ();
		fixed         getZ         ();

		void          step         (unsigned int ticks, int msps, JJ1BonusLevel* bonus);
		void          draw         (unsigned int ticks);

};

#endif
