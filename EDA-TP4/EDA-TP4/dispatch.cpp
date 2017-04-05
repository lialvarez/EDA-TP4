#include "dispatch.h"
#include "Worms2.h"

void dispatch(keyEvents ev, Worms *wormArr)
{
	for (unsigned int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			switch (wormArr[i].getWormState())
			{
			case Still:

				switch (ev)
				{
				case KEY_W_DOWN:
					wormArr[i].startJumping();
					break;
				case KEY_A_DOWN:
					wormArr[i].setLookingRight(false);
					wormArr[i].startWalkPending();
					break;
				case KEY_D_DOWN:
					wormArr[i].setLookingRight(true);
					wormArr[i].startWalkPending();
					break;
				default:
					break;
				}
				break;

			case WalkPending:

				switch (ev)
				{

				case KEY_A_UP:
					wormArr[i].stopWalkPending();
					break;
				case KEY_D_UP:
					wormArr[i].stopWalkPending();
					break;
				default:
					wormArr[i].continueWalkPending();
					break;
				}
				break;

			case Walking:

				switch (ev)
				{
				case KEY_A_UP:
					wormArr[i].setWalkEnding();
					break;
				case KEY_D_UP:
					wormArr[i].setWalkEnding();
				default:
					wormArr[i].continueWalking();
					break;
				}
				break;

			case WalkEnding:

				switch (ev)
				{
				case KEY_A_DOWN:
					if (!wormArr[i].getLookingRight())
					{
						wormArr[i].continueWalking();
					}
					break;
				case KEY_D_DOWN:
					if (wormArr[i].getLookingRight())
					{
						wormArr[i].continueWalking();
					}
					break;
				default:
					wormArr[i].continueWalkEnding();
					break;
				}

			case JumpStarting:
				wormArr[i].continueStartJumping();
				break;

			case Jumping:
				wormArr[i].continueJumping();
				break;

			case JumpEnding:
				wormArr[i].continueJumpEnding();
				break;
			default:
				break;
			}
		}
		else if (i == 1)
		{
			switch (wormArr[i].getWormState())
			{
			case Still:
				switch (ev)
				{
				case KEY_UP_DOWN:
					wormArr[i].startJumping();
					break;
				case KEY_LEFT_DOWN:
					wormArr[i].setLookingRight(false);
					wormArr[i].startWalkPending();
					break;
				case KEY_RIGHT_DOWN:
					wormArr[i].setLookingRight(true);
					wormArr[i].startWalkPending();
					break;
				default:
					break;
				}
				break;

			case WalkPending:
				switch (ev)
				{

				case KEY_LEFT_UP:
					wormArr[i].stopWalkPending();
					break;
				case KEY_RIGHT_UP:
					wormArr[i].stopWalkPending();
					break;
				default:
					wormArr[i].continueWalkPending();
					break;
				}
				break;

			case Walking:
				switch (ev)
				{
				case KEY_LEFT_UP:
					wormArr[i].setWalkEnding();
					break;
				case KEY_RIGHT_UP:
					wormArr[i].setWalkEnding();
					break;
				default:
					wormArr[i].continueWalking();
					break;
				}
				break;

			case WalkEnding:
				switch (ev)
				{
				case KEY_LEFT_DOWN:
					if (!wormArr[i].getLookingRight())
					{
						wormArr[i].continueWalking();
					}
					break;
				case KEY_RIGHT_DOWN:
					if (wormArr[i].getLookingRight())
					{
						wormArr[i].continueWalking();
					}
					break;
				default:
					wormArr[i].continueWalkEnding();
					break;
				}
				break;

			case JumpStarting:
				wormArr[i].continueStartJumping();
				break;

			case Jumping:
				wormArr[i].continueJumping();
				break;

			case JumpEnding:
				wormArr[i].continueJumpEnding();
				break;
			default:
				break;
			}
		}

	}
}